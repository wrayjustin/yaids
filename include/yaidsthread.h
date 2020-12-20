/*
 *  yaidsthread.h - YAIDS Thread Headers
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

#ifndef yaidsthread
#define yaidsthread

#define YAIDS_THREAD_INPUT_PCAP     1
#define YAIDS_THREAD_OUTPUT         2
#define YAIDS_THREAD_YARA           3
#define YAIDS_THREAD_TIMELIMIT      4

#define MAX_OUTPUT_ELEMENT_SIZE     60
#define MAX_OUTPUT_SINGLE_SIZE      20

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

static pthread_mutex_t dataInputQueueMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t dataInputQueueNextMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t dataInputQueueReadMutex = PTHREAD_MUTEX_INITIALIZER;

static pthread_mutex_t dataOutputQueueMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t dataOutputQueueNextMutex =
    PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t dataOutputQueueReadMutex =
    PTHREAD_MUTEX_INITIALIZER;
    
static pthread_mutex_t packetCountsandThreadStatusesMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t packetCountsandThreadStatusesNextMutex =
    PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t packetCountsandThreadStatusesLowMutex =
    PTHREAD_MUTEX_INITIALIZER;

#pragma GCC diagnostic pop

extern yaidsPacketCounts_ptr yaidsthread_new_packet_counts(void);
extern yaidsThreadStatuses_ptr yaidsthread_new_thread_statuses(void);
extern yaidsInputDataQueue_ptr yaidsthread_new_input_queue(void);
extern yaidsInputDataNode_ptr
yaidsthread_new_input_data(yaidsPcapPacket_ptr packet);
extern yaidsInputThreadArgs_ptr
yaidsthread_new_input_thread_args(yaidsInputDataQueue_ptr dataQueue,
                                  yaidsPcapHandle_ptr pcapHandle,
                                  yaidsConfig_ptr config,
                                  yaidsPacketCounts_ptr packetCounts,
                                  yaidsThreadStatuses_ptr threadStatuses);
extern yaidsTimelimitThreadArgs_ptr
yaidsthread_new_timelimit_thread_args(bool * yaidsRunning,
                                      yaidsConfig_ptr config);
extern yaidsOutputDataQueue_ptr yaidsthread_new_output_queue(void);
extern yaidsOutputDataNode_ptr
yaidsthread_new_output_data(yaidsPcapPacket_ptr packet, char *alert);
extern yaidsOutputThreadArgs_ptr
yaidsthread_new_output_thread_args(yaidsOutputDataQueue_ptr dataQueue,
                                   yaidsPcapHandle_ptr pcapHandle,
                                   yaidsConfig_ptr config,
                                   yaidsPacketCounts_ptr packetCounts,
                                   yaidsThreadStatuses_ptr threadStatuses);
extern yaidsYaraThreadArgs_ptr
yaidsthread_new_yara_thread_args(yaidsInputDataQueue_ptr inputDataQueue,
                                 yaidsOutputDataQueue_ptr outputDataQueue,
                                 yaidsYaraScanner_ptr yaraScanner,
                                 yaidsConfig_ptr config,
                                 yaidsPacketCounts_ptr packetCounts,
                                 yaidsThreadStatuses_ptr threadStatuses);
extern void yaidsthread_update_pcap_packet_count(yaidsPacketCounts_ptr packetCounts);
extern void yaidsthread_update_yara_packet_count(yaidsPacketCounts_ptr packetCounts);
extern void yaidsthread_update_alert_packet_count(yaidsPacketCounts_ptr packetCounts);
extern void yaidsthread_update_output_packet_count(yaidsPacketCounts_ptr packetCounts);
extern void yaidsthread_set_pcap_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config);
extern void yaidsthread_set_yara_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config);
extern void yaidsthread_set_output_finished(yaidsThreadStatuses_ptr threadStatuses, yaidsConfig_ptr config);
extern void yaidsthread_add_input_data(yaidsInputDataQueue_ptr dataQueue,
                                       yaidsPcapPacket_ptr packet);
extern yaidsInputDataNode
yaidsthread_get_input_data(yaidsInputDataQueue_ptr dataQueue);
extern void yaidsthread_add_output_data(yaidsOutputDataQueue_ptr dataQueue,
                                        yaidsPcapPacket_ptr packet,
                                        char *alert);
extern yaidsOutputDataNode
yaidsthread_get_output_data(yaidsOutputDataQueue_ptr dataQueue);
extern yaidsThreadReturn
yaidsthread_create_pcap_thread(yaidsInputThreadArgs_ptr threadArgs);
extern yaidsThreadReturn
yaidsthread_create_yara_thread(yaidsYaraThreadArgs_ptr threadArgs);
extern yaidsThreadReturn
yaidsthread_create_output_thread(yaidsOutputThreadArgs_ptr threadArgs);
extern yaidsThreadReturn
yaidsthread_create_timelimit_thread(yaidsTimelimitThreadArgs_ptr
                                    threadArgs);
extern yaidsThreadList_ptr yaidsthread_new_threadlist(yaidsConfig config);
extern yaidsThreadInfo_ptr yaidsthread_new_threadinfo(void);
extern int yaidsthread_run_threads(bool * yaidsRunning, yaidsConfig config,
                                   yaidsThreadList_ptr threadList,
                                   yaidsInputDataQueue_ptr yaidsInputQueue,
                                   yaidsOutputDataQueue_ptr
                                   yaidsOutputQueue,
                                   yaidsPcapHandle_ptr pcapHandle,
                                   yaidsYaraScanner_ptr yaraScanners);

extern void *yaidsthread_pcap_thread(void *args);
extern void *yaidsthread_yara_thread(void *args);
extern void *yaidsthread_output_thread(void *args);
extern void *yaidsthread_timelimit_thread(void *args);

#endif
