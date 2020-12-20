/*
 *  yaidsthread.c - YAIDS Threading Source Code
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
#include <pthread.h>
#include <pcap.h>
#include <signal.h>
#include <sys/prctl.h>

extern yaidsPacketCounts_ptr yaidsthread_new_packet_counts(void)
{
    yaidsPacketCounts_ptr packetCounts;
    packetCounts =
        (yaidsPacketCounts_ptr) calloc(sizeof(yaidsPacketCounts),
                                         sizeof(int));
    packetCounts->pcapPacketCount = 0;
    packetCounts->yaraPacketCount = 0;
    packetCounts->alertPacketCount = 0;
    packetCounts->outputPacketCount = 0;
    return packetCounts;
}

extern yaidsThreadStatuses_ptr yaidsthread_new_thread_statuses(void)
{
    yaidsThreadStatuses_ptr threadStatuses;
    threadStatuses =
        (yaidsThreadStatuses_ptr) calloc(sizeof(yaidsThreadStatuses),
                                         sizeof(int));
    threadStatuses->pcapThreadsFinished = false;
    threadStatuses->yaraThreadsFinished = false;
    threadStatuses->outputThreadsFinished = false;
    return threadStatuses;
}

extern yaidsInputDataQueue_ptr yaidsthread_new_input_queue(void)
{
    yaidsInputDataQueue_ptr dataQueue;
    dataQueue =
        (yaidsInputDataQueue_ptr) calloc(sizeof(yaidsInputDataQueue),
                                         sizeof(int));
    dataQueue->firstNode = NULL;
    dataQueue->lastNode = NULL;
    return dataQueue;
}

extern yaidsInputDataNode_ptr
yaidsthread_new_input_data(yaidsPcapPacket_ptr packet)
{
    yaidsInputDataNode_ptr dataNode;
    dataNode =
        (yaidsInputDataNode_ptr) calloc(sizeof(yaidsInputDataNode),
                                        sizeof(int));
    dataNode->data = packet;
    dataNode->nextNode = NULL;
    return dataNode;
}

extern yaidsInputThreadArgs_ptr
yaidsthread_new_input_thread_args(yaidsInputDataQueue_ptr dataQueue,
                                  yaidsPcapHandle_ptr pcapHandle,
                                  yaidsConfig_ptr config,
                                  yaidsPacketCounts_ptr packetCounts,
                                  yaidsThreadStatuses_ptr threadStatuses)
{
    yaidsInputThreadArgs_ptr threadArgs;
    threadArgs =
        (yaidsInputThreadArgs_ptr) calloc(sizeof(yaidsInputThreadArgs),
                                          sizeof(int));
    threadArgs->dataQueue = dataQueue;
    threadArgs->pcapHandle = pcapHandle;
    threadArgs->config = config;
    threadArgs->packetCounts = packetCounts;
    threadArgs->threadStatuses = threadStatuses;
    return threadArgs;
}

extern yaidsTimelimitThreadArgs_ptr
yaidsthread_new_timelimit_thread_args(bool * yaidsRunning,
                                      yaidsConfig_ptr config)
{
    yaidsTimelimitThreadArgs_ptr threadArgs;
    threadArgs = (yaidsTimelimitThreadArgs_ptr)
        calloc(sizeof(yaidsTimelimitThreadArgs), sizeof(int));
    threadArgs->yaidsRunning = yaidsRunning;
    threadArgs->config = config;
    return threadArgs;
}

extern yaidsOutputDataQueue_ptr yaidsthread_new_output_queue(void)
{
    yaidsOutputDataQueue_ptr dataQueue;
    dataQueue =
        (yaidsOutputDataQueue_ptr) calloc(sizeof(yaidsOutputDataQueue),
                                          sizeof(int));
    dataQueue->firstNode = NULL;
    dataQueue->lastNode = NULL;
    return dataQueue;
}

extern yaidsOutputDataNode_ptr
yaidsthread_new_output_data(yaidsPcapPacket_ptr packet, char *alert)
{
    yaidsOutputDataNode_ptr dataNode;
    dataNode =
        (yaidsOutputDataNode_ptr) calloc(sizeof(yaidsOutputDataNode),
                                         sizeof(int));
    dataNode->data = packet;
    dataNode->alert = alert;
    dataNode->nextNode = NULL;
    return dataNode;
}

extern yaidsOutputThreadArgs_ptr
yaidsthread_new_output_thread_args(yaidsOutputDataQueue_ptr dataQueue,
                                   yaidsPcapHandle_ptr pcapHandle,
                                   yaidsConfig_ptr config,
                                   yaidsPacketCounts_ptr packetCounts,
                                   yaidsThreadStatuses_ptr threadStatuses)
{
    yaidsOutputThreadArgs_ptr threadArgs;
    threadArgs =
        (yaidsOutputThreadArgs_ptr) calloc(sizeof(yaidsOutputThreadArgs),
                                           sizeof(int));
    threadArgs->dataQueue = dataQueue;
    threadArgs->config = config;
    threadArgs->pcapHandle = pcapHandle;
    threadArgs->packetCounts = packetCounts;
    threadArgs->threadStatuses = threadStatuses;
    return threadArgs;
}

extern yaidsYaraThreadArgs_ptr
yaidsthread_new_yara_thread_args(yaidsInputDataQueue_ptr inputDataQueue,
                                 yaidsOutputDataQueue_ptr outputDataQueue,
                                 yaidsYaraScanner_ptr yaraScanner,
                                 yaidsConfig_ptr config,
                                 yaidsPacketCounts_ptr packetCounts,
                                 yaidsThreadStatuses_ptr threadStatuses)
{
    yaidsYaraThreadArgs_ptr threadArgs;
    threadArgs =
        (yaidsYaraThreadArgs_ptr) calloc(sizeof(yaidsYaraThreadArgs),
                                         sizeof(int));
    threadArgs->inputDataQueue = inputDataQueue;
    threadArgs->outputDataQueue = outputDataQueue;
    threadArgs->yaraScanner = yaraScanner;
    threadArgs->config = config;
    threadArgs->packetCounts = packetCounts;
    threadArgs->threadStatuses = threadStatuses;
    return threadArgs;
}

extern void yaidsthread_update_pcap_packet_count(yaidsPacketCounts_ptr packetCounts)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesLowMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    packetCounts->pcapPacketCount++;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesLowMutex);
}

extern void yaidsthread_update_yara_packet_count(yaidsPacketCounts_ptr packetCounts)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    packetCounts->yaraPacketCount++;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
}

extern void yaidsthread_update_alert_packet_count(yaidsPacketCounts_ptr packetCounts)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesLowMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    packetCounts->alertPacketCount++;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesLowMutex);
}

extern void yaidsthread_update_output_packet_count(yaidsPacketCounts_ptr packetCounts)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesLowMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    packetCounts->outputPacketCount++;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesLowMutex);
}

extern void yaidsthread_set_pcap_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesLowMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    threadStatuses->pcapThreadsFinished = true;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesLowMutex);
    
    if (config->debug)
        yaidsio_print_debug_line("Thread(s) Finished: %u [PCAP]",
                                 pthread_self());
    
}

extern void yaidsthread_set_yara_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    threadStatuses->yaraThreadsFinished = true;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    
    if (config->debug)
        yaidsio_print_debug_line("Thread(s) Finished: %u [YARA]",
                                 pthread_self());
}

extern void yaidsthread_set_output_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config)
{
    pthread_mutex_lock(&packetCountsandThreadStatusesLowMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesNextMutex);
    pthread_mutex_lock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesNextMutex);
    
    threadStatuses->outputThreadsFinished = true;
    
    pthread_mutex_unlock(&packetCountsandThreadStatusesMutex);
    pthread_mutex_unlock(&packetCountsandThreadStatusesLowMutex);
    
    if (config->debug)
        yaidsio_print_debug_line("Thread(s) Finished: %u [OUTPUT]",
                                 pthread_self());
}

extern void yaidsthread_add_input_data(yaidsInputDataQueue_ptr dataQueue,
                                       yaidsPcapPacket_ptr packet)
{
    yaidsInputDataNode_ptr dataNode = yaidsthread_new_input_data(packet);

    pthread_mutex_lock(&dataInputQueueNextMutex);
    pthread_mutex_lock(&dataInputQueueMutex);
    pthread_mutex_unlock(&dataInputQueueNextMutex);

    if (dataQueue->firstNode == NULL) {
        dataQueue->firstNode = dataNode;
        dataQueue->lastNode = dataNode;
    } else {
        dataQueue->lastNode->nextNode = dataNode;
        dataQueue->lastNode = dataQueue->lastNode->nextNode;
    }

    pthread_mutex_unlock(&dataInputQueueMutex);
}

extern yaidsInputDataNode
yaidsthread_get_input_data(yaidsInputDataQueue_ptr dataQueue)
{
    yaidsInputDataNode_ptr queuedDataNode;
    yaidsInputDataNode nodeData;

    while (dataQueue->firstNode == NULL) {
        continue;
    }

    pthread_mutex_lock(&dataInputQueueReadMutex);
    pthread_mutex_lock(&dataInputQueueNextMutex);
    pthread_mutex_lock(&dataInputQueueMutex);
    pthread_mutex_unlock(&dataInputQueueNextMutex);

    if (dataQueue->firstNode != NULL) {
        queuedDataNode = dataQueue->firstNode;
        dataQueue->firstNode = dataQueue->firstNode->nextNode;
        nodeData = *queuedDataNode;
        free(queuedDataNode);
    }

    pthread_mutex_unlock(&dataInputQueueMutex);
    pthread_mutex_unlock(&dataInputQueueReadMutex);

    return nodeData;
}

extern void yaidsthread_add_output_data(yaidsOutputDataQueue_ptr dataQueue,
                                        yaidsPcapPacket_ptr packet,
                                        char *alert)
{
    yaidsOutputDataNode_ptr dataNode =
        yaidsthread_new_output_data(packet, alert);

    pthread_mutex_lock(&dataOutputQueueNextMutex);
    pthread_mutex_lock(&dataOutputQueueMutex);
    pthread_mutex_unlock(&dataOutputQueueNextMutex);

    if (dataQueue->firstNode == NULL) {
        dataQueue->firstNode = dataNode;
        dataQueue->lastNode = dataNode;
    } else {
        dataQueue->lastNode->nextNode = dataNode;
        dataQueue->lastNode = dataQueue->lastNode->nextNode;
    }

    pthread_mutex_unlock(&dataOutputQueueMutex);
}

extern yaidsOutputDataNode
yaidsthread_get_output_data(yaidsOutputDataQueue_ptr dataQueue)
{
    yaidsOutputDataNode_ptr queuedDataNode;
    yaidsOutputDataNode nodeData;

    while (dataQueue->firstNode == NULL) {
        continue;
    }

    pthread_mutex_lock(&dataOutputQueueReadMutex);
    pthread_mutex_lock(&dataOutputQueueNextMutex);
    pthread_mutex_lock(&dataOutputQueueMutex);
    pthread_mutex_unlock(&dataOutputQueueNextMutex);

    if (dataQueue->firstNode != NULL) {
        queuedDataNode = dataQueue->firstNode;
        dataQueue->firstNode = dataQueue->firstNode->nextNode;
        nodeData = *queuedDataNode;
        free(queuedDataNode);
    }

    pthread_mutex_unlock(&dataOutputQueueMutex);
    pthread_mutex_unlock(&dataOutputQueueReadMutex);

    return nodeData;
}

extern yaidsThreadReturn
yaidsthread_create_pcap_thread(yaidsInputThreadArgs_ptr threadArgs)
{
    yaidsThreadReturn threadReturn;
    yaidsThreadReturn_ptr threadReturn_ptr = &threadReturn;
    threadReturn.threadStatus =
        pthread_create(&((*threadReturn_ptr).threadId), NULL,
                       yaidsthread_pcap_thread, threadArgs);
    return threadReturn;
}

extern yaidsThreadReturn
yaidsthread_create_yara_thread(yaidsYaraThreadArgs_ptr threadArgs)
{
    yaidsThreadReturn threadReturn;
    yaidsThreadReturn_ptr threadReturn_ptr = &threadReturn;
    threadReturn.threadStatus =
        pthread_create(&((*threadReturn_ptr).threadId), NULL,
                       yaidsthread_yara_thread, threadArgs);
    return threadReturn;
}

extern yaidsThreadReturn
yaidsthread_create_output_thread(yaidsOutputThreadArgs_ptr threadArgs)
{
    yaidsThreadReturn threadReturn;
    yaidsThreadReturn_ptr threadReturn_ptr = &threadReturn;
    threadReturn.threadStatus =
        pthread_create(&((*threadReturn_ptr).threadId), NULL,
                       yaidsthread_output_thread, threadArgs);
    return threadReturn;
}

extern yaidsThreadReturn
yaidsthread_create_timelimit_thread(yaidsTimelimitThreadArgs_ptr
                                    threadArgs)
{
    yaidsThreadReturn threadReturn;
    yaidsThreadReturn_ptr threadReturn_ptr = &threadReturn;
    threadReturn.threadStatus =
        pthread_create(&((*threadReturn_ptr).threadId), NULL,
                       yaidsthread_timelimit_thread, threadArgs);
    return threadReturn;
}

extern void *yaidsthread_pcap_thread(void *args)
{
    pthread_detach(pthread_self());

    yaidsInputThreadArgs_ptr threadArgs = (yaidsInputThreadArgs_ptr) args;
    yaidsInputDataQueue_ptr yaidsInputQueue = threadArgs->dataQueue;
    yaidsConfig_ptr config = threadArgs->config;
    yaidsPcapHandle_ptr pcapHandle = threadArgs->pcapHandle;
    yaidsPacketCounts_ptr packetCounts = threadArgs->packetCounts;
    yaidsThreadStatuses_ptr threadStatuses = threadArgs->threadStatuses;

    if (config->debug)
        yaidsio_print_debug_line("Detatching Thread: %u [PCAP]",
                                 pthread_self());

    yaidsPcapCallbackArgs callbackArgs;
    callbackArgs.dataQueue = yaidsInputQueue;
    callbackArgs.config = config;
    callbackArgs.packetCounts = packetCounts;
    yaidspcap_read_packets(pcapHandle,
                           (yaidsPcapCallbackArgs_ptr) & callbackArgs);
    
    yaidsthread_set_pcap_finished(threadStatuses, config);

    return YAIDS_SUCCESS;
}

extern void *yaidsthread_yara_thread(void *args)
{
    pthread_detach(pthread_self());

    yaidsYaraThreadArgs_ptr threadArgs = (yaidsYaraThreadArgs_ptr) args;
    yaidsInputDataQueue_ptr yaidsInputQueue = threadArgs->inputDataQueue;
    yaidsOutputDataQueue_ptr yaidsOutputQueue =
        threadArgs->outputDataQueue;
    yaidsYaraScanner_ptr yaraScanner = threadArgs->yaraScanner;
    yaidsConfig_ptr config = threadArgs->config;
    yaidsPacketCounts_ptr packetCounts = threadArgs->packetCounts;
    yaidsThreadStatuses_ptr threadStatuses = threadArgs->threadStatuses;
    
    yaidsYaraCallbackArgs callbackArgs;
    callbackArgs.packetCounts = packetCounts;

    if (config->debug)
        yaidsio_print_debug_line("Detatching Thread: %u [Yara]",
                                 pthread_self());

    while (true) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
        malloc_trim(32);
#pragma GCC diagnostic pop

        if (config->debug > 1)
            yaidsio_print_debug_line("Flushing Memory [Yara Thread: %u]",
                                     pthread_self());

        if (yaidsInputQueue->firstNode == NULL) {
            if ((config->read_pcap_file) && (threadStatuses->pcapThreadsFinished) && (packetCounts->pcapPacketCount == packetCounts->yaraPacketCount)) {
                yaidsthread_set_yara_finished(threadStatuses, config);
                break;
            }
            continue;
        } else {
            yaidsInputDataNode dataNode =
                yaidsthread_get_input_data(yaidsInputQueue);
            yaidsyara_scan_packet(yaraScanner, dataNode.data,
                                  yaidsOutputQueue,
                                  (yaidsYaraCallbackArgs_ptr) &
                                  callbackArgs, config);
        }
    }

    return YAIDS_SUCCESS;
}

extern void *yaidsthread_output_thread(void *args)
{
    pthread_detach(pthread_self());

    yaidsOutputThreadArgs_ptr threadArgs =
        (yaidsOutputThreadArgs_ptr) args;
    yaidsOutputDataQueue_ptr yaidsOutputQueue = threadArgs->dataQueue;
    yaidsPcapHandle_ptr pcapHandle = threadArgs->pcapHandle;
    yaidsConfig_ptr config = threadArgs->config;
    yaidsPacketCounts_ptr packetCounts = threadArgs->packetCounts;
    yaidsThreadStatuses_ptr threadStatuses = threadArgs->threadStatuses;

    if (config->debug)
        yaidsio_print_debug_line("Detatching Thread: %u [Output]",
                                 pthread_self());

    FILE *alertFileHandle = NULL;
    FILE *pcapFileHandle = NULL;

    if (!config->output_mode) {
        alertFileHandle = fopen(config->outputAlertFile, "a");

        if (access(config->outputPcapFile, F_OK) != YAIDS_SUCCESS) {
            FILE *createpcapFileHandle;
            createpcapFileHandle = fopen(config->outputPcapFile, "a");
            fclose(createpcapFileHandle);
        }

        pcapFileHandle =
            yaidspcap_open_output_pcap_file(pcapHandle, config);
    }

    while (true) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
        malloc_trim(32);
#pragma GCC diagnostic pop

        if (config->debug > 1)
            yaidsio_print_debug_line("Flushing Memory [Output Thread: %u]",
                                     pthread_self());

        if (yaidsOutputQueue->firstNode == NULL) {
            if ((config->read_pcap_file) && (threadStatuses->yaraThreadsFinished) && (packetCounts->alertPacketCount == packetCounts->outputPacketCount)) {
                yaidsthread_set_output_finished(threadStatuses, config);
                break;
            }
            continue;
        } else {
            yaidsOutputDataNode dataNode =
                yaidsthread_get_output_data(yaidsOutputQueue);

            if (!config->silent_mode) {
                if (config->debug)
                    yaidsio_print_debug_line("Printing Alert: %p",
                                             dataNode.data);
                yaidsio_print_alert(dataNode.alert);
            }

            if (!config->output_mode) {
                if (config->debug)
                    yaidsio_print_debug_line("Writing Alert and PCAP: %p",
                                             dataNode.data);
                yaidsio_write_alert(alertFileHandle, dataNode.alert);
                yaidsio_write_pcap(pcapFileHandle, dataNode.data);
            }

            if (config->flush_mode) {
                fflush(alertFileHandle);
                yaidspcap_flush_output(pcapFileHandle);
            }


            free(dataNode.alert);
            free(dataNode.data);
            if (threadArgs->config->read_pcap_file) yaidsthread_update_output_packet_count(threadArgs->packetCounts);
        }
    }

    return YAIDS_SUCCESS;
}

extern void *yaidsthread_timelimit_thread(void *args)
{
    pthread_detach(pthread_self());

    yaidsTimelimitThreadArgs_ptr threadArgs =
        (yaidsTimelimitThreadArgs_ptr) args;
    bool *yaidsRunning = threadArgs->yaidsRunning;
    yaidsConfig_ptr config = threadArgs->config;

    if (config->debug) {
        yaidsio_print_debug_line("Detatching Thread: %u [Timelimit]",
                                 pthread_self());
        yaidsio_print_debug_line("Timelimit Set, Sleeping: %d",
                                 threadArgs->config->timelimit);
    }

    sleep(threadArgs->config->timelimit);

    yaidsio_print_horizontal_line(120);
    yaidsio_print_std_line("%s\n",
                           "[TIMELIMIT] Timelimit reached, exiting...");

    *yaidsRunning = false;

    return YAIDS_SUCCESS;
}

extern yaidsThreadList_ptr yaidsthread_new_threadlist(yaidsConfig config)
{
    yaidsThreadList_ptr threadList;
    threadList =
        (yaidsThreadList_ptr) calloc(sizeof(yaidsThreadList) *
                                     (config.threads + 2), sizeof(int));
    return threadList;
}

extern yaidsThreadInfo_ptr yaidsthread_new_threadinfo(void)
{
    yaidsThreadInfo_ptr threadInfo;
    threadInfo =
        (yaidsThreadInfo_ptr) calloc(sizeof(yaidsThreadInfo), sizeof(int));
    return threadInfo;
}

extern int yaidsthread_run_threads(bool * yaidsRunning, yaidsConfig config,
                                   yaidsThreadList_ptr threadList,
                                   yaidsInputDataQueue_ptr yaidsInputQueue,
                                   yaidsOutputDataQueue_ptr
                                   yaidsOutputQueue,
                                   yaidsPcapHandle_ptr pcapHandle,
                                   yaidsYaraScanner_ptr yaraScanners)
{
    yaidsInputQueue = yaidsthread_new_input_queue();
    yaidsOutputQueue = yaidsthread_new_output_queue();
    yaidsPacketCounts_ptr packetCounts = yaidsthread_new_packet_counts();
    yaidsThreadStatuses_ptr threadStatuses = yaidsthread_new_thread_statuses();

    sigset_t yaidsThreadSignal;
    sigemptyset(&yaidsThreadSignal);
    sigaddset(&yaidsThreadSignal, SIGINT);
    pthread_sigmask(SIG_BLOCK, &yaidsThreadSignal, NULL);
    prctl(PR_SET_PDEATHSIG, SIGHUP);

    if (config.debug)
        yaidsio_print_debug_line("Starting PCAP (Input) Thread...");

    yaidsThreadInfo_ptr pcapThreadInfo = yaidsthread_new_threadinfo();
    yaidsInputThreadArgs_ptr yaidsInputThreadArgs =
        yaidsthread_new_input_thread_args(yaidsInputQueue, pcapHandle,
                                          &config, packetCounts, threadStatuses);
    yaidsThreadReturn pcapThreadReturn =
        yaidsthread_create_pcap_thread(yaidsInputThreadArgs);
    if (pcapThreadReturn.threadStatus != YAIDS_SUCCESS) {
        return YAIDS_THREAD_ERROR;
    }
    pcapThreadInfo->threadId = pcapThreadReturn.threadId;
    pcapThreadInfo->threadType = YAIDS_THREAD_INPUT_PCAP;
    threadList[0].threadInfo = pcapThreadInfo;

    int scannerThreadCount;
    for (scannerThreadCount = 0; scannerThreadCount < config.threads;
         scannerThreadCount++) {
        if (config.debug)
            yaidsio_print_debug_line
                ("Starting Yara (Process) Thread [%d]...",
                 scannerThreadCount);

        yaidsThreadInfo_ptr yaraThreadInfo = yaidsthread_new_threadinfo();;
        yaidsYaraThreadArgs_ptr yaidsYaraThreadArgs =
            yaidsthread_new_yara_thread_args(yaidsInputQueue,
                                             yaidsOutputQueue,
                                             &yaraScanners
                                             [scannerThreadCount],
                                             &config,
                                             packetCounts,
                                             threadStatuses);
        yaidsThreadReturn threadReturn =
            yaidsthread_create_yara_thread(yaidsYaraThreadArgs);
        if (threadReturn.threadStatus != YAIDS_SUCCESS) {
            return YAIDS_THREAD_ERROR;
        }
        yaraThreadInfo->threadId = threadReturn.threadId;
        yaraThreadInfo->threadType = YAIDS_THREAD_YARA;
        threadList[1 + scannerThreadCount].threadInfo = yaraThreadInfo;
    }

    if (config.debug)
        yaidsio_print_debug_line("Starting Output Thread...");

    yaidsThreadInfo_ptr outputThreadInfo = yaidsthread_new_threadinfo();
    yaidsOutputThreadArgs_ptr yaidsOutputThreadArgs =
        yaidsthread_new_output_thread_args(yaidsOutputQueue, pcapHandle,
                                           &config, packetCounts, threadStatuses);
    yaidsThreadReturn outputThreadReturn =
        yaidsthread_create_output_thread(yaidsOutputThreadArgs);
    if (outputThreadReturn.threadStatus != YAIDS_SUCCESS) {
        return YAIDS_THREAD_ERROR;
    }
    outputThreadInfo->threadId = outputThreadReturn.threadId;
    outputThreadInfo->threadType = YAIDS_THREAD_OUTPUT;
    threadList[1 + scannerThreadCount].threadInfo = outputThreadInfo;

    if (config.timelimit > 0) {
        if (config.debug)
            yaidsio_print_debug_line("Starting Timelimit Thread...");

        yaidsThreadInfo_ptr timelimitThreadInfo =
            yaidsthread_new_threadinfo();
        yaidsTimelimitThreadArgs_ptr yaidsTimelimitThreadArgs =
            yaidsthread_new_timelimit_thread_args(yaidsRunning, &config);
        yaidsThreadReturn timelimitThreadReturn =
            yaidsthread_create_timelimit_thread(yaidsTimelimitThreadArgs);
        if (timelimitThreadReturn.threadStatus != YAIDS_SUCCESS) {
            return YAIDS_THREAD_ERROR;
        }
        timelimitThreadInfo->threadId = timelimitThreadReturn.threadId;
        timelimitThreadInfo->threadType = YAIDS_THREAD_TIMELIMIT;
        threadList[2 + scannerThreadCount].threadInfo =
            timelimitThreadInfo;
    }

    if (config.debug) {
        int threadListCount;
        int threadTotal = scannerThreadCount + 2;

        if (config.timelimit > 0)
            threadTotal++;

        yaidsio_print_debug_line("Threads: %d", threadTotal);

        for (threadListCount = 0; threadListCount < (threadTotal);
             threadListCount++) {
            yaidsio_print_debug_line("\t threadId: %u",
                                     (&threadList
                                      [threadListCount])->threadInfo->
                                     threadId);
            yaidsio_print_debug_line("\t\t threadType: %d",
                                     (&threadList
                                      [threadListCount])->threadInfo->
                                     threadType);
        }
    }

    yaidsio_print_started();

    pthread_sigmask(SIG_UNBLOCK, &yaidsThreadSignal, NULL);
    signal(SIGINT, yaids_signal);

    while (*yaidsRunning) {
        if ((config.read_pcap_file) && (threadStatuses->pcapThreadsFinished && threadStatuses->yaraThreadsFinished && threadStatuses->outputThreadsFinished))
            break;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
        malloc_trim(32);
#pragma GCC diagnostic pop

        if (config.debug > 1)
            yaidsio_print_debug_line("Flushing Memory [Main Thread]");
    }

    return YAIDS_COMPLETE;
}