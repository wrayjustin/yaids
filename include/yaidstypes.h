/*
 *  yaidstypes.h - YAIDS Type Definition Headers
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

#ifndef yaidstypes
#define yaidstypes

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pcap.h>
#include <yara.h>
#include <netinet/in.h>

typedef struct yaidsConfig_struct yaidsConfig;
typedef struct yaidsInputDataNode_struct yaidsInputDataNode;
typedef struct yaidsInputDataQueue_struct yaidsInputDataQueue;
typedef struct yaidsInputThreadArgs_struct yaidsInputThreadArgs;
typedef struct yaidsOutputDataNode_struct yaidsOutputDataNode;
typedef struct yaidsOutputDataQueue_struct yaidsOutputDataQueue;
typedef struct yaidsOutputThreadArgs_struct yaidsOutputThreadArgs;
typedef struct yaidsPacketCounts_struct yaidsPacketCounts;
typedef struct yaidsPcapCallbackArgs_struct yaidsPcapCallbackArgs;
typedef struct yaidsPcapHandle_struct yaidsPcapHandle;
typedef struct yaidsPcapPacket_struct yaidsPcapPacket;
typedef struct yaidsPcapPacketHeader_struct yaidsPcapPacketHeader;
typedef struct yaidsPcapPacketHeaderFrame_struct yaidsPcapPacketHeaderFrame;
typedef struct yaidsPcapPacketHeaderNet_struct yaidsPcapPacketHeaderNet;
typedef struct yaidsPcapPacketHeaderTransport_struct yaidsPcapPacketHeaderTransport;
typedef struct yaidsThreadInfo_struct yaidsThreadInfo;
typedef struct yaidsThreadList_struct yaidsThreadList;
typedef struct yaidsThreadReturn_struct yaidsThreadReturn;
typedef struct yaidsThreadStatuses_struct yaidsThreadStatuses;
typedef struct yaidsTimelimitThreadArgs_struct yaidsTimelimitThreadArgs;
typedef struct yaidsYaraCallbackArgs_struct yaidsYaraCallbackArgs;
typedef struct yaidsYaraScanner_struct yaidsYaraScanner;
typedef struct yaidsYaraThreadArgs_struct yaidsYaraThreadArgs;

typedef yaidsConfig *yaidsConfig_ptr;
typedef yaidsInputDataNode *yaidsInputDataNode_ptr;
typedef yaidsInputDataQueue *yaidsInputDataQueue_ptr;
typedef yaidsInputThreadArgs *yaidsInputThreadArgs_ptr;
typedef yaidsOutputDataNode *yaidsOutputDataNode_ptr;
typedef yaidsOutputDataQueue *yaidsOutputDataQueue_ptr;
typedef yaidsOutputThreadArgs *yaidsOutputThreadArgs_ptr;
typedef yaidsPacketCounts *yaidsPacketCounts_ptr;
typedef yaidsPcapCallbackArgs *yaidsPcapCallbackArgs_ptr;
typedef yaidsPcapHandle *yaidsPcapHandle_ptr;
typedef yaidsPcapPacket *yaidsPcapPacket_ptr;
typedef yaidsPcapPacketHeader *yaidsPcapPacketHeader_ptr;
typedef yaidsPcapPacketHeaderFrame *yaidsPcapPacketHeaderFrame_ptr;
typedef yaidsPcapPacketHeaderNet *yaidsPcapPacketHeaderNet_ptr;
typedef yaidsPcapPacketHeaderTransport *yaidsPcapPacketHeaderTransport_ptr;
typedef yaidsThreadInfo *yaidsThreadInfo_ptr;
typedef yaidsThreadList *yaidsThreadList_ptr;
typedef yaidsThreadReturn *yaidsThreadReturn_ptr;
typedef yaidsThreadStatuses *yaidsThreadStatuses_ptr;
typedef yaidsTimelimitThreadArgs *yaidsTimelimitThreadArgs_ptr;
typedef yaidsYaraCallbackArgs *yaidsYaraCallbackArgs_ptr;
typedef yaidsYaraScanner *yaidsYaraScanner_ptr;
typedef yaidsYaraThreadArgs *yaidsYaraThreadArgs_ptr;

typedef struct ether_header *etherHeader_ptr;
typedef struct ip *ipHeader_ptr;
typedef struct tcphdr *tcpHeader_ptr;
typedef struct udphdr *udpHeader_ptr;

typedef struct yaidsConfig_struct {
    int status;
    int debug;
    int threads;
    int timelimit;
    int read_pcap_file;
    int silent_mode;
    int output_mode;
    int flush_mode;
    int fast_alert_mode;
    char *pcapDevice;
    char *yaraRulesFile;
    char *outputPrefix;
    char *outputPath;
    char *pcapInputFile;
    char *outputAlertFile;
    char *outputPcapFile;
} yaidsConfig;

typedef struct yaidsThreadStatuses_struct {
    bool pcapThreadsFinished;
    bool yaraThreadsFinished;
    bool outputThreadsFinished;
} yaidsThreadStatuses;

typedef struct yaidsPacketCounts_struct {
    int pcapPacketCount;
    int yaraPacketCount;
    int alertPacketCount;
    int outputPacketCount;
} yaidsPacketCounts;

typedef struct yaidsPcapHandle_struct {
    int threadId;
    int pcapStatus;
    int pcapTimeout;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *pcapHandle;
} yaidsPcapHandle;

typedef struct yaidsYaraScanner_struct {
    int threadId;
    YR_RULES *yaraRules;
    YR_SCANNER *yaraScanner;
} yaidsYaraScanner;

typedef struct yaidsThreadReturn_struct {
    pthread_t threadId;
    int threadStatus;
} yaidsThreadReturn;

typedef struct yaidsThreadInfo_struct {
    pthread_t threadId;
    int threadType;
} yaidsThreadInfo;

typedef struct yaidsThreadList_struct {
    yaidsThreadInfo_ptr threadInfo;
} yaidsThreadList;

typedef struct yaidsInputDataNode_struct {
    struct yaidsInputDataNode_struct *nextNode;
    yaidsPcapPacket_ptr data;
} yaidsInputDataNode;

typedef struct yaidsInputDataQueue_struct {
    yaidsInputDataNode_ptr firstNode;
    yaidsInputDataNode_ptr lastNode;
} yaidsInputDataQueue;

typedef struct yaidsInputThreadArgs_struct {
    yaidsInputDataQueue_ptr dataQueue;
    yaidsPcapHandle_ptr pcapHandle;
    yaidsConfig_ptr config;
    yaidsPacketCounts_ptr packetCounts;
    yaidsThreadStatuses_ptr threadStatuses;
} yaidsInputThreadArgs;

typedef struct yaidsOutputDataNode_struct {
    struct yaidsOutputDataNode_struct *nextNode;
    yaidsPcapPacket_ptr data;
    char *alert;
} yaidsOutputDataNode;

typedef struct yaidsOutputDataQueue_struct {
    yaidsOutputDataNode_ptr firstNode;
    yaidsOutputDataNode_ptr lastNode;
} yaidsOutputDataQueue;

typedef struct yaidsOutputThreadArgs_struct {
    yaidsOutputDataQueue_ptr dataQueue;
    yaidsPcapHandle_ptr pcapHandle;
    yaidsConfig_ptr config;
    yaidsPacketCounts_ptr packetCounts;
    yaidsThreadStatuses_ptr threadStatuses;
} yaidsOutputThreadArgs;

typedef struct yaidsYaraThreadArgs_struct {
    yaidsInputDataQueue_ptr inputDataQueue;
    yaidsOutputDataQueue_ptr outputDataQueue;
    yaidsYaraScanner_ptr yaraScanner;
    yaidsConfig_ptr config;
    yaidsPacketCounts_ptr packetCounts;
    yaidsThreadStatuses_ptr threadStatuses;
} yaidsYaraThreadArgs;

typedef struct yaidsPcapCallbackArgs_struct {
    yaidsInputDataQueue_ptr dataQueue;
    yaidsConfig_ptr config;
    yaidsPacketCounts_ptr packetCounts;
} yaidsPcapCallbackArgs;

typedef struct yaidsYaraCallbackArgs_struct {
    yaidsPcapPacket_ptr packet;
    yaidsOutputDataQueue_ptr outputDataQueue;
    yaidsConfig_ptr config;
    yaidsPacketCounts_ptr packetCounts;
} yaidsYaraCallbackArgs;

typedef struct yaidsTimelimitThreadArgs_struct {
    bool *yaidsRunning;
    yaidsConfig_ptr config;
} yaidsTimelimitThreadArgs;

typedef struct yaidsPcapPacket_struct {
    bool alert;
    int packetSize;
    const struct pcap_pkthdr *packetHeader;
    const u_char *packetBody;
} yaidsPcapPacket;

typedef struct yaidsPcapPacketHeader_struct {
    bool frameExists;
    bool netExists;
    bool transportExists;
    char typeList[42];
    char frameSource[INET6_ADDRSTRLEN + 1];
    char frameDest[INET6_ADDRSTRLEN + 1];
    char netSource[INET6_ADDRSTRLEN + 1];
    char netDest[INET6_ADDRSTRLEN + 1];
    char transportSource[10];
    char transportDest[10];
} yaidsPcapPacketHeader;

typedef struct yaidsPcapPacketHeaderFrame_struct {
    char type[14];
    char source[INET6_ADDRSTRLEN + 1];
    char dest[INET6_ADDRSTRLEN + 1];
} yaidsPcapPacketHeaderFrame;

typedef struct yaidsPcapPacketHeaderNet_struct {
    char type[14];
    char source[INET6_ADDRSTRLEN + 1];
    char dest[INET6_ADDRSTRLEN + 1];
} yaidsPcapPacketHeaderNet;

typedef struct yaidsPcapPacketHeaderTransport_struct {
    char type[14];
    char source[10];
    char dest[10];
} yaidsPcapPacketHeaderTransport;

#endif
