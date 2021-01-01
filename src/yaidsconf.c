/*
 *  yaidsconf.c - YAIDS Configuration Source Code
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
#include <sys/sysinfo.h>

extern yaidsConfig yaidsconf_init(void)
{
    yaidsConfig config;

    config.pcapDevice = NULL;
    config.yaraRulesFile = NULL;
    config.outputPrefix = NULL;
    config.outputPath = NULL;
    config.pcapInputFile = NULL;
    config.outputAlertFile = NULL;
    config.outputPcapFile = NULL;
    config.pcapFilterFile = NULL;
    config.threads = yaidsconf_get_default_thread_count();
    config.timelimit = 0;
    config.read_pcap_file = 0;
    config.silent_mode = 0;
    config.output_mode = 0;
    config.flush_mode = 0;
    config.fast_alert_mode = 0;
    config.debug = 0;
    config.status = 1;

    return config;
}

extern int yaidsconf_get_default_thread_count(void)
{
    return get_nprocs() * 4;
}

extern void yaidsconf_config_init(yaidsConfig_ptr config, char *exeName,        //LGTM[cpp/poorly-documented-function] - Configuration Initalization
                                  int options)
{
    if (config->status != YAIDS_PENDING_CONFIG) {
        return;
    }

    if (options == 1) {
        yaidsio_help(exeName);
        config->status = YAIDS_NO_ACTION;
        return;
    }

    if (config->silent_mode && config->output_mode) {
        yaidsio_help(exeName);
        config->status = YAIDS_INVALID_MODE;
        return;
    }

    if ((config->yaraRulesFile)
        && (access(config->yaraRulesFile, R_OK) != YAIDS_SUCCESS)) {
        config->status = YAIDS_FILE_DOES_NOT_EXIST;
        return;
    }

    if ((config->pcapInputFile)
        && (access(config->pcapInputFile, R_OK) != YAIDS_SUCCESS)) {
        config->status = YAIDS_FILE_DOES_NOT_EXIST;
        return;
    }

    if (config->pcapFilterFile) {
        if (access(config->pcapFilterFile, R_OK) != YAIDS_SUCCESS) {
            config->status = YAIDS_FILE_DOES_NOT_EXIST;
            return;
        } else {
            config->bpfContents =
                yaidsio_read_file(config->pcapFilterFile);
        }
    }

    if ((config->pcapDevice || config->pcapInputFile)
        && (config->yaraRulesFile)) {

        if (!config->outputPrefix) {
            char epochString[32];
            struct tm *epochTM;
            time_t timestamp = time(NULL);

#ifdef HAVE_GMTIME_R
            struct tm epochTM_struct;
            gmtime_r(&timestamp, &epochTM_struct);
            epochTM = &epochTM_struct;
#else
            epochTM = gmtime(&timestamp);
#endif
            strftime(epochString, 32, "%s", epochTM);
            config->outputPrefix =
                strndup(epochString, strlen(epochString));
        }

        if (!config->outputPath) {
            config->outputPath = "./";
        }

        if (!config->output_mode) {
            config->outputAlertFile =
                (char *) calloc(PATH_MAX + 1, sizeof(char));
            snprintf(config->outputAlertFile, PATH_MAX,
                     "%s/yaids.%s.alerts", config->outputPath,
                     config->outputPrefix);

            config->outputPcapFile =
                (char *) calloc(PATH_MAX + 1, sizeof(char));
            snprintf(config->outputPcapFile, PATH_MAX, "%s/yaids.%s.pcap",
                     config->outputPath, config->outputPrefix);

            if (access(config->outputPath, W_OK) != YAIDS_SUCCESS) {
                config->status = YAIDS_PERMISSION_DENIED;
                return;
            }

            if ((access(config->outputAlertFile, F_OK) == YAIDS_SUCCESS)
                && (access(config->outputAlertFile, W_OK) !=
                    YAIDS_SUCCESS)) {
                config->status = YAIDS_PERMISSION_DENIED;
                return;
            }

            if ((access(config->outputPcapFile, F_OK) == YAIDS_SUCCESS)
                && (access(config->outputPath, W_OK) != YAIDS_SUCCESS)) {
                config->status = YAIDS_PERMISSION_DENIED;
                return;
            }
        }

        config->status = YAIDS_SUCCESS;
    } else {
        config->status = YAIDS_MISSING_ARGUMENTS;
    }
}
