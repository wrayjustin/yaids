/*
 *  yaidspcap.c - YAIDS PCAP Source Code
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
#include <pcap.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <ethertypes.h>

extern void yaidspcap_init(yaidsPcapHandle_ptr pcapHandle)
{
    (*pcapHandle).threadId = 0;
    (*pcapHandle).pcapStatus = YAIDS_PCAP_ERROR;
    (*pcapHandle).pcapTimeout = 100;
}

extern yaidsPcapPacket_ptr yaidspcap_new_packet(int size)
{
    yaidsPcapPacket_ptr packet;
    packet =
        (yaidsPcapPacket_ptr) calloc(sizeof(yaidsPcapPacket_ptr) +
                                     sizeof(struct pcap_pkthdr) + size,
                                     sizeof(int));
    return packet;
}

extern int yaidspcap_create_handle(yaidsConfig config,
                                   yaidsPcapHandle_ptr pcapHandle)
{
    yaidspcap_init(pcapHandle);

    if (config.read_pcap_file) {
        pcapHandle->pcapHandle =
            pcap_open_offline(config.pcapInputFile,
                              pcapHandle->errorBuffer);
    } else {
        pcapHandle->pcapHandle =
            pcap_open_live(config.pcapDevice, BUFSIZ, 0,
                           pcapHandle->pcapTimeout,
                           pcapHandle->errorBuffer);
    }

    if (pcapHandle->pcapHandle == NULL) {
        yaidsio_print_error_line("PCAP ERROR: %s",
                                 pcapHandle->errorBuffer);
        pcapHandle->pcapStatus = YAIDS_PCAP_ERROR;
        return YAIDS_PCAP_ERROR;
    } else {
        pcapHandle->pcapStatus = YAIDS_SUCCESS;
        return YAIDS_SUCCESS;
    }
}

extern void yaidspcap_read_packets(yaidsPcapHandle_ptr pcapHandle,
                                   yaidsPcapCallbackArgs_ptr callbackArgs)
{
    pcap_loop(pcapHandle->pcapHandle, 0, yaidspcap_read_callback,
              (u_char *) callbackArgs);
}

extern void yaidspcap_read_callback(u_char * args,
                                    const struct pcap_pkthdr *packetHeader,
                                    const u_char * packetBody)
{
    yaidsPcapCallbackArgs_ptr callbackArgs =
        (yaidsPcapCallbackArgs_ptr) args;
    yaidsInputDataQueue_ptr yaidsInputQueue = callbackArgs->dataQueue;
    yaidsConfig_ptr config = callbackArgs->config;
    yaidsPacketCounts_ptr packetCounts = callbackArgs->packetCounts;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
    malloc_trim(32);
#pragma GCC diagnostic pop

    if (config->debug > 1)
        yaidsio_print_debug_line("Flushing Memory [PCAP Thread: %u]",
                                 pthread_self());

    struct pcap_pkthdr *copyPacketHeader =
        calloc(sizeof(struct pcap_pkthdr), sizeof(int));
    copyPacketHeader->caplen = packetHeader->caplen;
    copyPacketHeader->len = packetHeader->len;
    copyPacketHeader->ts = packetHeader->ts;

    yaidsPcapPacket_ptr yaidsPcapPacket =
        yaidspcap_new_packet(packetHeader->caplen);
    yaidsPcapPacket->alert = false;
    yaidsPcapPacket->packetSize = packetHeader->caplen;
    yaidsPcapPacket->packetHeader = packetHeader;
    yaidsPcapPacket->packetHeader = copyPacketHeader;
    yaidsPcapPacket->packetBody = packetBody;

    if (config->debug)
        yaidsio_print_debug_line("Pakcet Captured: %p (Size: %d)",
                                 yaidsPcapPacket,
                                 yaidsPcapPacket->packetSize);

    if (config->read_pcap_file) yaidsthread_update_pcap_packet_count(packetCounts);
    yaidsthread_add_input_data(yaidsInputQueue, yaidsPcapPacket);
    
    free(copyPacketHeader);
}

extern void yaidspcap_parse_pcap_headers(yaidsPcapPacket_ptr packet,
                                         yaidsPcapPacketHeader_ptr
                                         parsedPacketHeaders)
{
    int frameSourceSize;
    int frameDestSize;
    int netSourceSize;
    int netDestSize;
    int transportSourceSize;
    int transportDestSize;
    char *transportSource;
    char *transportDest;
    char *typeList;
    char *frameSource;
    char *frameDest;
    char *netSource;
    char *netDest;
    char *frameType;
    char *netType;
    char *transportType;

    typeList = calloc(32, sizeof(char));
    frameSource = NULL;
    frameDest = NULL;
    netSource = NULL;
    netDest = NULL;
    transportSource = calloc(8, sizeof(char));
    transportDest = calloc(8, sizeof(char));
    frameType = calloc(10, sizeof(char));
    netType = calloc(12, sizeof(char));
    transportType = calloc(10, sizeof(char));

    parsedPacketHeaders->frameExists = false;
    parsedPacketHeaders->netExists = false;
    parsedPacketHeaders->transportExists = false;

    strncpy(parsedPacketHeaders->typeList, "UNKN", 4);
    parsedPacketHeaders->typeList[strlen("UNKN") + 1] = '\0';
    parsedPacketHeaders->typeList[31] = '\0';
    parsedPacketHeaders->frameSource[0] = '\0';
    parsedPacketHeaders->frameDest[0] = '\0';
    parsedPacketHeaders->netSource[0] = '\0';
    parsedPacketHeaders->netDest[0] = '\0';
    parsedPacketHeaders->transportSource[0] = '\0';
    parsedPacketHeaders->transportDest[0] = '\0';

    if (packet->packetHeader->caplen > ETH_HEADER_SIZE) {
        struct ether_header *etherHeader;
        struct ip *ipHeader;

        etherHeader = (struct ether_header *) packet->packetBody;

        strncpy(frameType, "ETH", 10);
        frameSource =
            ether_ntoa((struct ether_addr *) etherHeader->ether_shost);
        frameDest =
            ether_ntoa((struct ether_addr *) etherHeader->ether_dhost);

        switch (ntohs(etherHeader->ether_type)) {
            case ETHERTYPE_IP:
                strncpy(netType, "IP", 12);
                break;
            case ETHERTYPE_8021AD:
                strncpy(netType, "8021AD", 12);
                break;
            case ETHERTYPE_8021Q:
                strncpy(netType, "8021Q", 12);
                break;
            case ETHERTYPE_8021QINQ:
                strncpy(netType, "8021QINQ", 12);
                break;
            case ETHERTYPE_AARP:
                strncpy(netType, "AARP", 12);
                break;
            case ETHERTYPE_ARP:
                strncpy(netType, "ARP", 12);
                break;
            case ETHERTYPE_ATALK:
                strncpy(netType, "ATALK", 12);
                break;
            case ETHERTYPE_DECDNS:
                strncpy(netType, "DECDNS", 12);
                break;
            case ETHERTYPE_DECDTS:
                strncpy(netType, "DECDTS", 12);
                break;
            case ETHERTYPE_DN:
                strncpy(netType, "DN", 12);
                break;
            case ETHERTYPE_IPV6:
                strncpy(netType, "IPV6", 12);
                break;
            case ETHERTYPE_IPX:
                strncpy(netType, "IPX", 12);
                break;
            case ETHERTYPE_LANBRIDGE:
                strncpy(netType, "LANBRIDGE", 12);
                break;
            case ETHERTYPE_LAT:
                strncpy(netType, "LAT", 12);
                break;
            case ETHERTYPE_LOOPBACK:
                strncpy(netType, "LOOPBACK", 12);
                break;
            case ETHERTYPE_MOPDL:
                strncpy(netType, "MOPDL", 12);
                break;
            case ETHERTYPE_MOPRC:
                strncpy(netType, "MOPRC", 12);
                break;
            case ETHERTYPE_MPLS:
                strncpy(netType, "MPLS", 12);
                break;
            case ETHERTYPE_MPLS_MULTI:
                strncpy(netType, "MPLS_MULTI", 12);
                break;
            case ETHERTYPE_NS:
                strncpy(netType, "NS", 12);
                break;
            case ETHERTYPE_PPP:
                strncpy(netType, "PPP", 12);
                break;
            case ETHERTYPE_PPPOED:
                strncpy(netType, "PPPOED", 12);
                break;
            case ETHERTYPE_PPPOES:
                strncpy(netType, "PPPOES", 12);
                break;
            case ETHERTYPE_PUP:
                strncpy(netType, "PUP", 12);
                break;
            case ETHERTYPE_REVARP:
                strncpy(netType, "REVARP", 12);
                break;
            case ETHERTYPE_SCA:
                strncpy(netType, "SCA", 12);
                break;
            case ETHERTYPE_SPRITE:
                strncpy(netType, "SPRITE", 12);
                break;
            case ETHERTYPE_TEB:
                strncpy(netType, "TEB", 12);
                break;
            case ETHERTYPE_TRAIL:
                strncpy(netType, "TRAIL", 12);
                break;
            case ETHERTYPE_VEXP:
                strncpy(netType, "VEXP", 12);
                break;
            case ETHERTYPE_VPROD:
                strncpy(netType, "VPROD", 12);
                break;
            default:
                strncpy(netType, "UNKN", 12);
                break;
        }

        if (ntohs(etherHeader->ether_type) == ETHERTYPE_IP
            || ntohs(etherHeader->ether_type) == ETHERTYPE_IPV6) {
            char sourceIP[INET6_ADDRSTRLEN];
            char destIP[INET6_ADDRSTRLEN];

            ipHeader =
                (struct ip *) (packet->packetBody +
                               sizeof(struct ether_header));

            inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIP,
                      INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &(ipHeader->ip_dst), destIP,
                      INET_ADDRSTRLEN);

            netSource = sourceIP;
            netDest = destIP;

            switch (ipHeader->ip_p) {
                case IPPROTO_TCP:
                    strncpy(transportType, "TCP", 10);
                    break;
                case IPPROTO_UDP:
                    strncpy(transportType, "UDP", 10);
                    break;
                case IPPROTO_ICMP:
                    strncpy(transportType, "ICMP", 10);
                    break;
                default:
                    strncpy(transportType, "UNKN", 10);
                    break;
            }

            if ((ipHeader->ip_p == IPPROTO_TCP)
                || (ipHeader->ip_p == IPPROTO_UDP)) {
                u_int sourcePort;
                u_int destPort;

                if (ipHeader->ip_p == IPPROTO_TCP) {
                    struct tcphdr *tcpHeader;
                    tcpHeader =
                        (struct tcphdr *) (packet->packetBody +
                                           sizeof(struct ether_header) +
                                           sizeof(struct ip));
                    sourcePort = ntohs(tcpHeader->source);
                    destPort = ntohs(tcpHeader->dest);
                } else {
                    struct udphdr *udpHeader;
                    udpHeader =
                        (struct udphdr *) (packet->packetBody +
                                           sizeof(struct ether_header) +
                                           sizeof(struct ip));
                    sourcePort = ntohs(udpHeader->source);
                    destPort = ntohs(udpHeader->dest);
                }

                snprintf(transportSource, 8, "%d", sourcePort);
                snprintf(transportDest, 8, "%d", destPort);
            }
        }
    } else {
        strncpy(frameType, "ETH", 10);
    }

    memset(typeList, 0, 32 * (sizeof(parsedPacketHeaders->typeList[0])));
    if (transportType != NULL
        && (strncmp(transportType, "", 10) != YAIDS_SUCCESS)
        && (strncmp(netType, "UNKN", 10) != YAIDS_SUCCESS)) {
        snprintf(typeList, 32, "%s/%s/%s", frameType, netType,
                 transportType);
    } else if (netType != NULL
               && (strncmp(frameType, "UNKN", 10) != YAIDS_SUCCESS)) {
        snprintf(typeList, 32, "%s/%s", frameType, netType);
    } else {
        snprintf(typeList, 32, "%s", frameType);
    }

    if (frameType != NULL
        && (strncmp(frameType, "ETH", 10) == YAIDS_SUCCESS)
        && frameSource != NULL && frameDest != NULL) {
        parsedPacketHeaders->frameExists = true;

        memset(parsedPacketHeaders->typeList, 0,
               32 * (sizeof parsedPacketHeaders->typeList[0]));
        strncpy(parsedPacketHeaders->typeList, typeList,
                fmin(32, strlen(typeList)));

        memset(parsedPacketHeaders->frameSource, 0,
               (INET6_ADDRSTRLEN +
                1) * (sizeof parsedPacketHeaders->frameSource[0]));
        strncpy(parsedPacketHeaders->frameSource, frameSource,
                fmin((INET6_ADDRSTRLEN + 1), strlen(frameSource)));
        frameSourceSize =
            fmin(((INET6_ADDRSTRLEN + 1) - 1), strlen(frameSource)) + 1;
        parsedPacketHeaders->frameSource[frameSourceSize] = '\0';
        parsedPacketHeaders->frameSource[INET6_ADDRSTRLEN] = '\0';

        memset(parsedPacketHeaders->frameDest, 0,
               (INET6_ADDRSTRLEN +
                1) * (sizeof parsedPacketHeaders->frameDest[0]));
        strncpy(parsedPacketHeaders->frameDest, frameDest,
                fmin((INET6_ADDRSTRLEN + 1), strlen(frameDest)));
        frameDestSize =
            fmin(((INET6_ADDRSTRLEN + 1) - 1), strlen(frameDest)) + 1;
        parsedPacketHeaders->frameDest[frameDestSize] = '\0';
        parsedPacketHeaders->frameDest[INET6_ADDRSTRLEN] = '\0';

        if ((netType != NULL && netSource != NULL && netDest != NULL)
            && ((strncmp(netType, "IP", 10) == YAIDS_SUCCESS)
                || (strncmp(frameType, "IPV6", 10) == YAIDS_SUCCESS))) {
            parsedPacketHeaders->netExists = true;

            memset(parsedPacketHeaders->netSource, 0,
                   (INET6_ADDRSTRLEN +
                    1) * (sizeof parsedPacketHeaders->netSource[0]));
            strncpy(parsedPacketHeaders->netSource, netSource,
                    fmin((INET6_ADDRSTRLEN + 1), strlen(netSource)));
            netSourceSize =
                fmin(((INET6_ADDRSTRLEN + 1) - 1), strlen(netSource)) + 1;
            parsedPacketHeaders->netSource[netSourceSize] = '\0';
            parsedPacketHeaders->netSource[INET6_ADDRSTRLEN] = '\0';

            memset(parsedPacketHeaders->netDest, 0,
                   (INET6_ADDRSTRLEN +
                    1) * (sizeof parsedPacketHeaders->netDest[0]));
            strncpy(parsedPacketHeaders->netDest, netDest,
                    fmin((INET6_ADDRSTRLEN + 1), strlen(netDest)));
            netDestSize =
                fmin(((INET6_ADDRSTRLEN + 1) - 1), strlen(netDest)) + 1;
            parsedPacketHeaders->netDest[netDestSize] = '\0';
            parsedPacketHeaders->netDest[INET6_ADDRSTRLEN] = '\0';

            if ((transportType != NULL && transportSource != NULL
                 && transportDest != NULL)
                && ((strncmp(transportType, "TCP", 10) == YAIDS_SUCCESS)
                    || (strncmp(transportType, "UDP", 10) ==
                        YAIDS_SUCCESS))) {
                parsedPacketHeaders->transportExists = true;

                memset(parsedPacketHeaders->transportSource, 0,
                       8 *
                       (sizeof parsedPacketHeaders->transportSource[0]));
                strncpy(parsedPacketHeaders->transportSource,
                        transportSource, fmin(8, strlen(transportSource)));
                transportSourceSize =
                    fmin((8 - 1), strlen(transportSource)) + 1;
                parsedPacketHeaders->transportSource[transportSourceSize] =
                    '\0';
                parsedPacketHeaders->transportSource[7] = '\0';

                memset(parsedPacketHeaders->transportDest, 0,
                       8 * (sizeof parsedPacketHeaders->transportDest[0]));
                strncpy(parsedPacketHeaders->transportDest, transportDest,
                        fmin(8, strlen(transportDest)));
                transportDestSize =
                    fmin((8 - 1), strlen(transportDest)) + 1;
                parsedPacketHeaders->transportDest[transportDestSize] =
                    '\0';
                parsedPacketHeaders->transportDest[7] = '\0';
            }
        }
    }

    free(typeList);
    free(transportSource);
    free(transportDest);
    free(frameType);
    free(netType);
    free(transportType);
}

extern FILE *yaidspcap_open_output_pcap_file(yaidsPcapHandle_ptr
                                             pcapHandle,
                                             yaidsConfig_ptr config)
{
    return (FILE *) pcap_dump_open_append(pcapHandle->pcapHandle,
                                          config->outputPcapFile);
}

extern void yaidspcap_write_packet(FILE * pcapFileHandle,
                                   yaidsPcapPacket_ptr packet)
{
    pcap_dump((u_char *) pcapFileHandle, packet->packetHeader,
              packet->packetBody);
}

extern void yaidspcap_flush_output(FILE * pcapFileHandle)
{
    pcap_dump_flush((pcap_dumper_t *) pcapFileHandle);
}
