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

#include <config.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc.h>
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

extern int yaidspcap_create_handle(yaidsConfig_ptr config,
                                   yaidsPcapHandle_ptr pcapHandle)
{
    yaidspcap_init(pcapHandle);

    if (config->read_pcap_file) {
        pcapHandle->pcapHandle =
            pcap_open_offline(config->pcapInputFile,
                              pcapHandle->errorBuffer);
    } else {
        pcapHandle->pcapHandle =
            pcap_open_live(config->pcapDevice, BUFSIZ, 0,
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

#ifdef HAVE_MALLOC_TRIM
        malloc_trim(32);

        if (config->debug > 1)
            yaidsio_print_debug_line("Flushing Memory [Output Thread: %u]",
                                     (unsigned int)pthread_self());
#endif

    if (config->debug > 1)
        yaidsio_print_debug_line("Flushing Memory [PCAP Thread: %u]",
                                 (int)pthread_self());

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
        yaidsio_print_debug_line("Pakcet Captured: %p (Size: %d, TS: %d)",
                                 yaidsPcapPacket,
                                 yaidsPcapPacket->packetSize, (int)yaidsPcapPacket->packetHeader->ts.tv_sec);

    if (config->read_pcap_file) yaidsthread_update_pcap_packet_count(packetCounts);
    yaidsthread_add_input_data(yaidsInputQueue, yaidsPcapPacket);
}

extern yaidsPcapPacketHeaderFrame_ptr yaidspcap_parse_pcap_headers_frame(etherHeader_ptr etherHeader)
{
    yaidsPcapPacketHeaderFrame_ptr frameHeader;
    frameHeader = calloc(sizeof(yaidsPcapPacketHeaderFrame), sizeof(char));

    frameHeader->type[0] = '\0';
    frameHeader->source[0] = '\0';
    frameHeader->dest[0] = '\0';

    strncpy(frameHeader->type, "ETH", 12);
    strncpy(frameHeader->source, ether_ntoa((struct ether_addr *) etherHeader->ether_shost), INET6_ADDRSTRLEN);
    strncpy(frameHeader->dest, ether_ntoa((struct ether_addr *) etherHeader->ether_dhost), INET6_ADDRSTRLEN);

    return frameHeader;
}

extern yaidsPcapPacketHeaderNet_ptr yaidspcap_parse_pcap_headers_net(etherHeader_ptr etherHeader, ipHeader_ptr ipHeader)
{
    yaidsPcapPacketHeaderNet_ptr netHeader;
    netHeader = calloc(sizeof(yaidsPcapPacketHeaderNet), sizeof(char));

    netHeader->type[0] = '\0';
    netHeader->source[0] = '\0';
    netHeader->dest[0] = '\0';

    strncpy(netHeader->type, yaidspcap_parse_pcap_headers_get_nettype(etherHeader), 12);

    if (ipHeader != NULL) {
        char sourceIP[INET6_ADDRSTRLEN];
        char destIP[INET6_ADDRSTRLEN];

        inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIP,
                  INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ipHeader->ip_dst), destIP,
                  INET_ADDRSTRLEN);

    strncpy(netHeader->source, sourceIP, INET6_ADDRSTRLEN);
    strncpy(netHeader->dest, destIP, INET6_ADDRSTRLEN);
    }

    return netHeader;
}

extern yaidsPcapPacketHeaderTransport_ptr yaidspcap_parse_pcap_headers_transport(yaidsPcapPacket_ptr packet, ipHeader_ptr ipHeader)
{
    yaidsPcapPacketHeaderTransport_ptr transportHeader;
    transportHeader = calloc(sizeof(yaidsPcapPacketHeaderTransport), sizeof(char));

    transportHeader->type[0] = '\0';
    transportHeader->source[0] = '\0';
    transportHeader->dest[0] = '\0';

    strncpy(transportHeader->type, yaidspcap_parse_pcap_headers_get_transporttype(ipHeader), 12);

    u_int sourcePort;
    u_int destPort;

    if (ipHeader->ip_p == IPPROTO_TCP) {
        tcpHeader_ptr tcpHeader;
        tcpHeader = (struct tcphdr *) (packet->packetBody +
                               sizeof(struct ether_header) +
                               sizeof(struct ip));

        sourcePort = ntohs(tcpHeader->source);
        destPort = ntohs(tcpHeader->dest);

        snprintf(transportHeader->source, 8, "%d", sourcePort);
        snprintf(transportHeader->dest, 8, "%d", destPort);

    } else if (ipHeader->ip_p == IPPROTO_UDP) {
        udpHeader_ptr udpHeader;
        udpHeader = (struct udphdr *) (packet->packetBody +
                               sizeof(struct ether_header) +
                               sizeof(struct ip));

        sourcePort = ntohs(udpHeader->source);
        destPort = ntohs(udpHeader->dest);

        snprintf(transportHeader->source, 8, "%d", sourcePort);
        snprintf(transportHeader->dest, 8, "%d", destPort);
    }

    return transportHeader;
}

extern char* yaidspcap_parse_pcap_headers_get_nettype(etherHeader_ptr etherHeader) //LGTM[cpp/poorly-documented-function] - Lengthy SWITCH
{
    switch (ntohs(etherHeader->ether_type)) {
        case ETHERTYPE_IP:
            return "IP";
            break;
        case ETHERTYPE_8021AD:
            return "8021AD";
            break;
        case ETHERTYPE_8021Q:
            return "8021Q";
            break;
        case ETHERTYPE_8021QINQ:
            return "8021QINQ";
            break;
        case ETHERTYPE_AARP:
            return "AARP";
            break;
        case ETHERTYPE_ARP:
            return "ARP";
            break;
        case ETHERTYPE_ATALK:
            return "ATALK";
            break;
        case ETHERTYPE_DECDNS:
            return "DECDNS";
            break;
        case ETHERTYPE_DECDTS:
            return "DECDTS";
            break;
        case ETHERTYPE_DN:
            return "DN";
            break;
        case ETHERTYPE_IPV6:
            return "IPV6";
            break;
        case ETHERTYPE_IPX:
            return "IPX";
            break;
        case ETHERTYPE_LANBRIDGE:
            return "LANBRIDGE";
            break;
        case ETHERTYPE_LAT:
            return "LAT";
            break;
        case ETHERTYPE_LOOPBACK:
            return "LOOPBACK";
            break;
        case ETHERTYPE_MOPDL:
            return "MOPDL";
            break;
        case ETHERTYPE_MOPRC:
            return "MOPRC";
            break;
        case ETHERTYPE_MPLS:
            return "MPLS";
            break;
        case ETHERTYPE_MPLS_MULTI:
            return "MPLS_MULTI";
            break;
        case ETHERTYPE_NS:
            return "NS";
            break;
        case ETHERTYPE_PPP:
            return "PPP";
            break;
        case ETHERTYPE_PPPOED:
            return "PPPOED";
            break;
        case ETHERTYPE_PPPOES:
            return "PPPOES";
            break;
        case ETHERTYPE_PUP:
            return "PUP";
            break;
        case ETHERTYPE_REVARP:
            return "REVARP";
            break;
        case ETHERTYPE_SCA:
            return "SCA";
            break;
        case ETHERTYPE_SPRITE:
            return "SPRITE";
            break;
        case ETHERTYPE_TEB:
            return "TEB";
            break;
        case ETHERTYPE_TRAIL:
            return "TRAIL";
            break;
        case ETHERTYPE_VEXP:
            return "VEXP";
            break;
        case ETHERTYPE_VPROD:
            return "VPROD";
            break;
        default:
            return "UNKN";
            break;
    }
}

extern char* yaidspcap_parse_pcap_headers_get_transporttype(ipHeader_ptr ipHeader)
{
    switch (ipHeader->ip_p) {
        case IPPROTO_TCP:
            return "TCP";
            break;
        case IPPROTO_UDP:
            return "UDP";
            break;
        case IPPROTO_ICMP:
            return "ICMP";
            break;
        default:
            return "UNKN";
            break;
    }
}

extern void yaidspcap_parse_pcap_headers_results(yaidsPcapPacketHeader_ptr parsedPacketHeaders, yaidsPcapPacketHeaderFrame_ptr frameHeader, yaidsPcapPacketHeaderNet_ptr netHeader, yaidsPcapPacketHeaderTransport_ptr transportHeader)
{
    if (transportHeader != NULL) {
        parsedPacketHeaders->frameExists = true;
        parsedPacketHeaders->netExists = true;
        parsedPacketHeaders->transportExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s/%s/%s", frameHeader->type, netHeader->type,
                 transportHeader->type);

        strncpy(parsedPacketHeaders->frameSource, frameHeader->source, INET6_ADDRSTRLEN + 1);
        strncpy(parsedPacketHeaders->frameDest, frameHeader->dest, INET6_ADDRSTRLEN + 1);

        strncpy(parsedPacketHeaders->netSource, netHeader->source, INET6_ADDRSTRLEN + 1);
        strncpy(parsedPacketHeaders->netDest, netHeader->dest, INET6_ADDRSTRLEN + 1);

        strncpy(parsedPacketHeaders->transportSource, transportHeader->source, 10);
        strncpy(parsedPacketHeaders->transportDest, transportHeader->dest, 10);
    } else if (netHeader != NULL) {
        parsedPacketHeaders->frameExists = true;
        parsedPacketHeaders->netExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s/%s", frameHeader->type, netHeader->type);

        strncpy(parsedPacketHeaders->frameSource, frameHeader->source, INET6_ADDRSTRLEN + 1);
        strncpy(parsedPacketHeaders->frameDest, frameHeader->dest, INET6_ADDRSTRLEN + 1);

        strncpy(parsedPacketHeaders->netSource, netHeader->source, INET6_ADDRSTRLEN + 1);
        strncpy(parsedPacketHeaders->netDest, netHeader->dest, INET6_ADDRSTRLEN + 1);
    } else if (frameHeader != NULL) {
        parsedPacketHeaders->frameExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s", frameHeader->type);

        strncpy(parsedPacketHeaders->frameSource, frameHeader->source, INET6_ADDRSTRLEN + 1);
        strncpy(parsedPacketHeaders->frameDest, frameHeader->dest, INET6_ADDRSTRLEN + 1);
    }
}

extern void yaidspcap_parse_pcap_headers(yaidsPcapPacket_ptr packet,
                                         yaidsPcapPacketHeader_ptr
                                         parsedPacketHeaders)
{
    parsedPacketHeaders->frameExists = false;
    parsedPacketHeaders->netExists = false;
    parsedPacketHeaders->transportExists = false;

    yaidsPcapPacketHeaderFrame_ptr frameHeader;
    yaidsPcapPacketHeaderNet_ptr netHeader;
    yaidsPcapPacketHeaderTransport_ptr transportHeader;
    frameHeader = NULL;
    netHeader = NULL;
    transportHeader = NULL;

    if (packet->packetHeader->len > ETH_HEADER_SIZE) {
        etherHeader_ptr etherHeader;
        ipHeader_ptr ipHeader;

        etherHeader = NULL;
        ipHeader = NULL;

        etherHeader = (etherHeader_ptr)packet->packetBody;
        frameHeader = yaidspcap_parse_pcap_headers_frame(etherHeader);

        if (ntohs(etherHeader->ether_type) == ETHERTYPE_IP
            || ntohs(etherHeader->ether_type) == ETHERTYPE_IPV6) {
            ipHeader =
            (struct ip *) (packet->packetBody +
                           sizeof(struct ether_header));

            netHeader = yaidspcap_parse_pcap_headers_net(etherHeader, ipHeader);
            transportHeader = yaidspcap_parse_pcap_headers_transport(packet, ipHeader);
        } else {
            netHeader = yaidspcap_parse_pcap_headers_net(etherHeader, ipHeader);
        }
    } else if (packet->packetHeader->len == ETH_HEADER_SIZE) {
        strncpy(parsedPacketHeaders->typeList, "ETH", 10);
    } else {
        strncpy(parsedPacketHeaders->typeList, "UNKN", 10);
    }

    yaidspcap_parse_pcap_headers_results(parsedPacketHeaders, frameHeader, netHeader, transportHeader);

    free(frameHeader);
    free(netHeader);
    free(transportHeader);
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
