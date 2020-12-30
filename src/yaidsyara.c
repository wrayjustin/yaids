/*
 *  yaidsyara.c - YAIDS YARA Source Code
 *
 *  This file is a part of or derived from YAIDS: https://github.com/wrayjustin/yaids
 *
 *  COPYRIGHT (C) 2020 Justin M. Wray - wray.justin@gmail.com / https://www.justinwray.com
 *  ALL RIGHTS RESERVED
 *  
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *  
 *  1. Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *  
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation and/or
 *  other materials provided with the distribution.
 *  
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *  may be used to endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <config.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <yaids.h>
#include <yaidstypes.h>
#include <yaidsconf.h>
#include <yaidsio.h>
#include <yaidspcap.h>
#include <yaidsyara.h>
#include <yaidsthread.h>
#include <yara.h>
#include <yara/types.h>

extern int yaidsyara_yara_initialize(void)
{
    if (yr_initialize() != ERROR_SUCCESS) {
        return YAIDS_YARA_ERROR;
    }

    return YAIDS_SUCCESS;
}

extern int yaidsyara_yara_finalize(void)
{
    if (yr_finalize() != ERROR_SUCCESS) {
        return YAIDS_YARA_ERROR;
    }

    return YAIDS_SUCCESS;
}

extern void yaidsyara_init(yaidsYaraScanner_ptr yara)
{
    (*yara).threadId = 0;
    (*yara).yaraRules = NULL;
    (*yara).yaraScanner = NULL;
}

extern int yaidsyara_create_scanner(yaidsConfig_ptr config,
                                    yaidsYaraScanner_ptr yara)
{
    if (yr_rules_load(config->yaraRulesFile, &(*yara).yaraRules) !=
        ERROR_SUCCESS) {
        return YAIDS_YARA_ERROR;
    }

    if (yr_scanner_create((*yara).yaraRules, &(*yara).yaraScanner) !=
        ERROR_SUCCESS) {
        return YAIDS_YARA_ERROR;
    }

    return YAIDS_SUCCESS;
}

extern int yaidsyara_create_scanners(yaidsConfig_ptr config,
                                     yaidsYaraScanner_ptr yaraScanners)
{
    int yaraStatus;
    int threadCount;
    for (threadCount = 0; threadCount < config->threads; threadCount++) {
        yaidsyara_init(&(yaraScanners[threadCount]));
        if ((yaraStatus =
             yaidsyara_create_scanner(config,
                                      &(yaraScanners[threadCount]))) !=
            YAIDS_SUCCESS) {
            return YAIDS_YARA_ERROR;
        }
        (yaraScanners[threadCount]).threadId = threadCount;
    }

    return YAIDS_SUCCESS;
}

extern void yaidsyara_scan_packet(yaidsYaraScanner_ptr yaraScanner,
                                  yaidsPcapPacket_ptr packet,
                                  yaidsOutputDataQueue_ptr
                                  yaidsOutputQueue,
                                  yaidsYaraCallbackArgs_ptr callbackArgs,
                                  yaidsConfig_ptr config)
{
    int packetSize = packet->packetSize;

    callbackArgs->packet = packet;
    callbackArgs->outputDataQueue = yaidsOutputQueue;
    callbackArgs->config = config;

    if (config->debug)
        yaidsio_print_debug_line("Scanning Packet: %p (Size: %d, TS: %d)",
                                 packet, packet->packetSize,
                                 (int) packet->packetHeader->ts.tv_sec);

    yr_scanner_set_callback(yaraScanner->yaraScanner,
                            &yaidsyara_scanner_callback,
                            (void *) callbackArgs);
    yr_scanner_scan_mem(yaraScanner->yaraScanner,
                        (const u_char *) packet->yaraPacket,
                        PKT_PREPROC_HDR_SIZE + packetSize);
}

extern int yaidsyara_scanner_callback(YR_SCAN_CONTEXT * scanContext,
                                      int status, void *rule, void *args)
{
    yaidsYaraCallbackArgs_ptr callbackArgs =
        (yaidsYaraCallbackArgs_ptr) args;

    if (status == CALLBACK_MSG_RULE_MATCHING) {
        YR_RULE *yaraRule = (YR_RULE *) rule;

        char *alertString;
        alertString =
            yaidsyara_scanner_callback_get_alert(callbackArgs, yaraRule,
                                                 scanContext);

        if (callbackArgs->config->read_pcap_file)
            yaidsthread_update_alert_packet_count
                (callbackArgs->packetCounts);

        if (callbackArgs->config->debug) {
            yaidsio_print_debug_line
                ("Adding Packet Count: Alert [PC: %d | YC: %d | AC: %d | OC: %d]",
                 callbackArgs->packetCounts->pcapPacketCount,
                 callbackArgs->packetCounts->yaraPacketCount,
                 callbackArgs->packetCounts->alertPacketCount,
                 callbackArgs->packetCounts->outputPacketCount);
            yaidsio_print_debug_line("Yara Match Found: %p (Size: %d)",
                                     callbackArgs->packet,
                                     callbackArgs->packet->packetSize);
        }

        callbackArgs->packet->alertCount++;
        yaidsthread_add_output_data((yaidsOutputDataQueue_ptr)
                                    callbackArgs->outputDataQueue,
                                    (yaidsPcapPacket_ptr)
                                    callbackArgs->packet,
                                    (char *) alertString);
    } else if (status == CALLBACK_MSG_SCAN_FINISHED) {
        callbackArgs->packet->yaraFinished = true;
        if (callbackArgs->packet->alertCount == 0) {
            free((void *) callbackArgs->packet->packetHeader);
            free((void *) callbackArgs->packet->packetBody);
            free((void *) callbackArgs->packet->parsedPacketHeaders);
            free((void *) callbackArgs->packet->yaraPacket);
            free(callbackArgs->packet);
        }

        if (callbackArgs->config->read_pcap_file)
            yaidsthread_update_yara_packet_count
                (callbackArgs->packetCounts);

        if (callbackArgs->config->debug) {
            yaidsio_print_debug_line
                ("Adding Packet Count: Yara [PC: %d | YC: %d | AC: %d | OC: %d]",
                 callbackArgs->packetCounts->pcapPacketCount,
                 callbackArgs->packetCounts->yaraPacketCount,
                 callbackArgs->packetCounts->alertPacketCount,
                 callbackArgs->packetCounts->outputPacketCount);
            yaidsio_print_debug_line("Yara Finished Packet: %p (Size: %d)",
                                     callbackArgs->packet,
                                     callbackArgs->packet->packetSize);
        }
    }

    return YAIDS_SUCCESS;
}

extern char *yaidsyara_scanner_callback_get_alert(yaidsYaraCallbackArgs_ptr
                                                  callbackArgs,
                                                  YR_RULE * yaraRule,
                                                  YR_SCAN_CONTEXT *
                                                  scanContext)
{
    char *metaMatch;
    char *stringMatch;
    char *ruleName;
    char *alertString;
    char timeString[64];
    struct tm *timestamp;

    int ruleNameSize;
    int alertStringMax = 68 + 120 + sizeof(yaidsPcapPacketHeader) + 26;

    alertString = calloc(alertStringMax, sizeof(char));
    memset(timeString, 0, 8 * (sizeof(char)));

    ruleName = calloc(140, sizeof(char));
    snprintf(ruleName, 120, "%s", yaraRule->identifier);
    ruleNameSize = fmin((120 - 1), strlen(yaraRule->identifier)) + 1;
    ruleName[ruleNameSize] = '\0';
    ruleName[120] = '\0';

#ifdef HAVE_GMTIME_R
    struct tm timestamp_struct;
    gmtime_r(&callbackArgs->packet->packetHeader->ts.tv_sec,
             &timestamp_struct);
    timestamp = &timestamp_struct;
#else
    timestamp = (struct tm *) calloc(sizeof(struct tm), sizeof(int));
    *timestamp = *gmtime(&callbackArgs->packet->packetHeader->ts.tv_sec);
#endif

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S",
             timestamp);

    if (callbackArgs->config->fast_alert_mode) {
        snprintf(alertString, alertStringMax,
                 "%s - %s", timeString, ruleName);
    } else {
        metaMatch =
            yaidsyara_scanner_callback_get_match_meta(scanContext,
                                                      yaraRule);
        stringMatch =
            yaidsyara_scanner_callback_get_match_string(scanContext,
                                                        yaraRule);

        yaidsyara_scanner_callback_get_alert_line(callbackArgs,
                                                  alertString,
                                                  alertStringMax,
                                                  timeString, ruleName,
                                                  metaMatch, stringMatch);

        free(metaMatch);
        free(stringMatch);
    }

    int alertStringSize;
    alertStringSize =
        (int) fmin((int) strlen(alertString), alertStringMax);
    alertString[alertStringSize] = '\0';

    free(ruleName);
#ifndef HAVE_GMTIME_R
    free(timestamp);
#endif

    return alertString;
}

extern void
yaidsyara_scanner_callback_get_alert_line(yaidsYaraCallbackArgs_ptr
                                          callbackArgs, char *alertString,
                                          int alertStringMax,
                                          char *timeString, char *ruleName,
                                          char *metaMatch,
                                          char *stringMatch)
{
    if (callbackArgs->packet->parsedPacketHeaders->transportExists) {
        snprintf(alertString, alertStringMax,
                 "%s - %s [%s] {%s} [%d:%d/%d] (%s) %s > %s - %s:%s > %s:%s",
                 timeString, ruleName, metaMatch, stringMatch,
                 callbackArgs->packet->packetSize,
                 callbackArgs->packet->packetHeader->caplen,
                 callbackArgs->packet->packetHeader->len,
                 callbackArgs->packet->parsedPacketHeaders->typeList,
                 callbackArgs->packet->parsedPacketHeaders->frameSource,
                 callbackArgs->packet->parsedPacketHeaders->frameDest,
                 callbackArgs->packet->parsedPacketHeaders->netSource,
                 callbackArgs->packet->
                 parsedPacketHeaders->transportSource,
                 callbackArgs->packet->parsedPacketHeaders->netDest,
                 callbackArgs->packet->parsedPacketHeaders->transportDest);
    } else if (callbackArgs->packet->parsedPacketHeaders->netExists) {
        snprintf(alertString, alertStringMax,
                 "%s - %s [%s] {%s} [%d:%d/%d] (%s) %s > %s - %s > %s",
                 timeString, ruleName, metaMatch, stringMatch,
                 callbackArgs->packet->packetSize,
                 callbackArgs->packet->packetHeader->caplen,
                 callbackArgs->packet->packetHeader->len,
                 callbackArgs->packet->parsedPacketHeaders->typeList,
                 callbackArgs->packet->parsedPacketHeaders->frameSource,
                 callbackArgs->packet->parsedPacketHeaders->frameDest,
                 callbackArgs->packet->parsedPacketHeaders->netSource,
                 callbackArgs->packet->parsedPacketHeaders->netDest);
    } else if (callbackArgs->packet->parsedPacketHeaders->frameExists) {
        snprintf(alertString, alertStringMax,
                 "%s - %s [%s] {%s} [%d:%d/%d] (%s) %s > %s",
                 timeString, ruleName, metaMatch, stringMatch,
                 callbackArgs->packet->packetSize,
                 callbackArgs->packet->packetHeader->caplen,
                 callbackArgs->packet->packetHeader->len,
                 callbackArgs->packet->parsedPacketHeaders->typeList,
                 callbackArgs->packet->parsedPacketHeaders->frameSource,
                 callbackArgs->packet->parsedPacketHeaders->frameDest);
    } else {
        snprintf(alertString, alertStringMax,
                 "%s - %s [%s] {%s} [%d:%d/%d] (%s)", timeString,
                 ruleName, metaMatch, stringMatch,
                 callbackArgs->packet->packetSize,
                 callbackArgs->packet->packetHeader->caplen,
                 callbackArgs->packet->packetHeader->len,
                 callbackArgs->packet->parsedPacketHeaders->typeList);
    }
}

extern char *yaidsyara_scanner_callback_get_match_meta(YR_SCAN_CONTEXT *
                                                       scanContext,
                                                       YR_RULE * yaraRule)
{
    char *metaString;
    metaString = calloc(MAX_OUTPUT_ELEMENT_SIZE, sizeof(char));

    YR_STRING *yaraString;

    yr_rule_strings_foreach(yaraRule, yaraString) {
        YR_MATCH *yaraMatch;

        yr_string_matches_foreach(scanContext, yaraString, yaraMatch) {
            char *metaStringInstance;
            metaStringInstance =
                calloc(MAX_OUTPUT_SINGLE_SIZE, sizeof(char));

            snprintf(metaStringInstance, MAX_OUTPUT_SINGLE_SIZE,
                     "%s:0x%" PRIx64 ":%d", yaraString->identifier,
                     yaraMatch->base + yaraMatch->offset,
                     yaraMatch->data_length);
            metaStringInstance[strlen(metaStringInstance)] = '\0';
            snprintf(metaString + strlen(metaString),
                     (MAX_OUTPUT_ELEMENT_SIZE - strlen(metaString)), "%s;",
                     metaStringInstance);
            free(metaStringInstance);
        }
    }

    metaString[strlen(metaString) - 1] = '\0';

    return metaString;
}

extern char *yaidsyara_scanner_callback_get_match_string(YR_SCAN_CONTEXT *
                                                         scanContext,
                                                         YR_RULE *
                                                         yaraRule)
{
    char *matchString;
    matchString = calloc(MAX_OUTPUT_ELEMENT_SIZE, sizeof(char));

    YR_STRING *yaraString;

    yr_rule_strings_foreach(yaraRule, yaraString) {
        YR_MATCH *yaraMatch;

        yr_string_matches_foreach(scanContext, yaraString, yaraMatch) {
            char *matchStringInstance;
            matchStringInstance =
                calloc(MAX_OUTPUT_SINGLE_SIZE, sizeof(char));

            if (STRING_IS_HEX(yaraString)) {
                for (int i = 0;
                     i < fmin(MAX_OUTPUT_SINGLE_SIZE,
                              yaraMatch->data_length); i++) {
                    char *matchStringHexInstance;
                    matchStringHexInstance =
                        calloc(sizeof(char) * 3, sizeof(char));

                    snprintf(matchStringHexInstance, 3, "%02X",
                             yaraMatch->data[i]);
                    snprintf(matchStringInstance +
                             strlen(matchStringInstance),
                             strlen(matchStringHexInstance), "%s",
                             matchStringHexInstance);

                    free(matchStringHexInstance);
                }
            } else {
                for (int i = 0;
                     i < fmin(MAX_OUTPUT_SINGLE_SIZE,
                              yaraMatch->data_length); i++) {
                    if ((intptr_t) yaraMatch->data >= 32
                        && (intptr_t) yaraMatch->data[i] <= 126) {
                        snprintf(matchStringInstance +
                                 strlen(matchStringInstance),
                                 MAX_OUTPUT_SINGLE_SIZE, "%c",
                                 yaraMatch->data[i]);
                    } else {
                        snprintf(matchStringInstance +
                                 strlen(matchStringInstance),
                                 MAX_OUTPUT_SINGLE_SIZE, "\\x%02X",
                                 yaraMatch->data[i]);
                    }
                }
            }

            matchStringInstance[strlen(matchStringInstance)] = '\0';
            snprintf(matchString + strlen(matchString),
                     (MAX_OUTPUT_ELEMENT_SIZE - strlen(matchString)),
                     "%s;", matchStringInstance);
            free(matchStringInstance);
        }
    }

    matchString[strlen(matchString) - 1] = '\0';

    return matchString;
}
