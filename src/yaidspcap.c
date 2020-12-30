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

#ifdef HAVE_STRLCPY
#include <bsd/string.h>
#endif

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
        (yaidsPcapPacket_ptr) calloc(sizeof(yaidsPcapPacket) +
                                     sizeof(struct pcap_pkthdr) +
                                     sizeof(yaidsPcapPacketHeader) + size +
                                     255 + size, sizeof(int));
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
        yaidsio_print_debug_line("Flushing Memory [PCAP Thread: %u]",
                                 (unsigned int) pthread_self());
#endif

    struct pcap_pkthdr *copyPacketHeader =
        calloc(sizeof(struct pcap_pkthdr), sizeof(int));
    yaidsPcapPacketHeader_ptr parsedPacketHeaders =
        (yaidsPcapPacketHeader_ptr)
        calloc(sizeof(yaidsPcapPacketHeader), sizeof(int));
    u_char *yaraPacket =
        calloc(PKT_PREPROC_HDR_SIZE + packetHeader->caplen, sizeof(int));

    copyPacketHeader->caplen = packetHeader->caplen;
    copyPacketHeader->len = packetHeader->len;
    copyPacketHeader->ts = packetHeader->ts;

    u_char *copyPacketBody = calloc(packetHeader->caplen, sizeof(char));
    memcpy(copyPacketBody, packetBody, packetHeader->caplen);

    yaidsPcapPacket_ptr yaidsPcapPacket =
        yaidspcap_new_packet(packetHeader->caplen);
    yaidsPcapPacket->alertCount = 0;
    yaidsPcapPacket->yaraFinished = false;
    yaidsPcapPacket->pcapWritten = false;
    yaidsPcapPacket->packetSize = packetHeader->caplen;
    yaidsPcapPacket->packetHeader = copyPacketHeader;
    yaidsPcapPacket->packetBody = copyPacketBody;


    yaidspcap_parse_pcap_headers(yaidsPcapPacket, parsedPacketHeaders);
    yaidsPcapPacket->parsedPacketHeaders = parsedPacketHeaders;

    yaidspcap_get_yara_packet_header(yaidsPcapPacket->parsedPacketHeaders,
                                     yaraPacket);
    memcpy(yaraPacket + PKT_PREPROC_HDR_SIZE, packetBody,
           yaidsPcapPacket->packetSize);
    yaidsPcapPacket->yaraPacket = yaraPacket;

    if (config->read_pcap_file)
        yaidsthread_update_pcap_packet_count(packetCounts);

    if (config->debug) {
        yaidsio_print_debug_line("Pakcet Captured: %p (Size: %d, TS: %d)",
                                 yaidsPcapPacket,
                                 yaidsPcapPacket->packetSize,
                                 (int) yaidsPcapPacket->packetHeader->
                                 ts.tv_sec);
        yaidsio_print_debug_line
            ("Adding Packet Count: PCAP [PC: %d | YC: %d | AC: %d | OC: %d]",
             packetCounts->pcapPacketCount, packetCounts->yaraPacketCount,
             packetCounts->alertPacketCount,
             packetCounts->outputPacketCount);
    }

    yaidsthread_add_input_data(yaidsInputQueue, yaidsPcapPacket);
}

extern u_char *yaidspcap_get_yara_packet_header(yaidsPcapPacketHeader_ptr
                                                parsedPacketHeaders,
                                                u_char * yaraPacketHeader)
{
    if (parsedPacketHeaders->transportExists) {
        snprintf((char *) yaraPacketHeader, PKT_PREPROC_HDR_SIZE,
                 "%c%-5d%-14s%-14s%-14s%-17s%-17s%-46s%-5s%-46s%-5s\n",
                 (char) parsedPacketHeaders->payloadOffset,
                 parsedPacketHeaders->originalPacketLength,
                 parsedPacketHeaders->frameType,
                 parsedPacketHeaders->netType,
                 parsedPacketHeaders->transportType,
                 parsedPacketHeaders->frameSource,
                 parsedPacketHeaders->frameDest,
                 parsedPacketHeaders->netSource,
                 parsedPacketHeaders->transportSource,
                 parsedPacketHeaders->netDest,
                 parsedPacketHeaders->transportDest);
    } else if (parsedPacketHeaders->netExists) {
        snprintf((char *) yaraPacketHeader, PKT_PREPROC_HDR_SIZE,
                 "%c%-5d%-14s%-14s%-14s%-17s%-17s%-51s%-51s\n",
                 (char) parsedPacketHeaders->payloadOffset,
                 parsedPacketHeaders->originalPacketLength,
                 parsedPacketHeaders->frameType,
                 parsedPacketHeaders->netType,
                 parsedPacketHeaders->transportType,
                 parsedPacketHeaders->frameSource,
                 parsedPacketHeaders->frameDest,
                 parsedPacketHeaders->netSource,
                 parsedPacketHeaders->netDest);
    } else if (parsedPacketHeaders->frameExists) {
        snprintf((char *) yaraPacketHeader, PKT_PREPROC_HDR_SIZE,
                 "%c%-5d%-14s%-14s%-14s%-17s%-133s\n",
                 (char) parsedPacketHeaders->payloadOffset,
                 parsedPacketHeaders->originalPacketLength,
                 parsedPacketHeaders->frameType,
                 parsedPacketHeaders->netType,
                 parsedPacketHeaders->transportType,
                 parsedPacketHeaders->frameSource,
                 parsedPacketHeaders->frameDest);
    } else {
        snprintf((char *) yaraPacketHeader, PKT_PREPROC_HDR_SIZE,
                 "%c%-5d%-14s%-164s",
                 (char) parsedPacketHeaders->payloadOffset,
                 parsedPacketHeaders->originalPacketLength,
                 parsedPacketHeaders->frameType,
                 parsedPacketHeaders->netType);
    }

    return yaraPacketHeader;
}

extern yaidsPcapPacketHeaderFrame_ptr
yaidspcap_parse_pcap_headers_frame(etherHeader_ptr etherHeader)
{
    yaidsPcapPacketHeaderFrame_ptr frameHeader;
    frameHeader = calloc(sizeof(yaidsPcapPacketHeaderFrame), sizeof(char));

    frameHeader->type[0] = '\0';
    frameHeader->source[0] = '\0';
    frameHeader->dest[0] = '\0';
    frameHeader->length = 14;

    char *frameSource;
    char *frameDest;

    frameSource =
        yaids_ether_ntoa((struct ether_addr *) etherHeader->ether_shost);
    frameDest =
        yaids_ether_ntoa((struct ether_addr *) etherHeader->ether_dhost);

    sec_str_cpy(frameHeader->type, "ETH", 12);
    sec_str_cpy(frameHeader->source, frameSource, INET6_ADDRSTRLEN);
    sec_str_cpy(frameHeader->dest, frameDest, INET6_ADDRSTRLEN);

    free(frameSource);
    free(frameDest);

    return frameHeader;
}

extern yaidsPcapPacketHeaderNet_ptr
yaidspcap_parse_pcap_headers_net(etherHeader_ptr etherHeader,
                                 ipHeader_ptr ipHeader)
{
    yaidsPcapPacketHeaderNet_ptr netHeader;
    netHeader = calloc(sizeof(yaidsPcapPacketHeaderNet), sizeof(char));

    netHeader->type[0] = '\0';
    netHeader->source[0] = '\0';
    netHeader->dest[0] = '\0';
    netHeader->length = 0;

    sec_str_cpy(netHeader->type,
                yaidspcap_parse_pcap_headers_get_nettype(etherHeader), 12);

    if (ipHeader != NULL) {
        char sourceIP[INET6_ADDRSTRLEN];
        char destIP[INET6_ADDRSTRLEN];

        inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIP, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ipHeader->ip_dst), destIP, INET_ADDRSTRLEN);

        netHeader->length = (ipHeader->ip_hl * 4);

        sec_str_cpy(netHeader->source, sourceIP, INET6_ADDRSTRLEN);
        sec_str_cpy(netHeader->dest, destIP, INET6_ADDRSTRLEN);
    }

    return netHeader;
}

extern yaidsPcapPacketHeaderTransport_ptr
yaidspcap_parse_pcap_headers_transport(yaidsPcapPacket_ptr packet,
                                       ipHeader_ptr ipHeader)
{
    yaidsPcapPacketHeaderTransport_ptr transportHeader;
    transportHeader =
        calloc(sizeof(yaidsPcapPacketHeaderTransport), sizeof(char));

    transportHeader->type[0] = '\0';
    transportHeader->source[0] = '\0';
    transportHeader->dest[0] = '\0';
    transportHeader->length = 0;

    sec_str_cpy(transportHeader->type,
                yaidspcap_parse_pcap_headers_get_transporttype(ipHeader),
                12);

    u_int sourcePort;
    u_int destPort;

    if (ipHeader->ip_p == IPPROTO_TCP) {
        tcpHeader_ptr tcpHeader;
        tcpHeader = (struct tcphdr *) (packet->packetBody +
                                       sizeof(struct ether_header) +
                                       sizeof(struct ip));

        sourcePort = ntohs(tcpHeader->source);
        destPort = ntohs(tcpHeader->dest);

        transportHeader->length = (tcpHeader->doff * 4);

        snprintf(transportHeader->source, 8, "%d", sourcePort);
        snprintf(transportHeader->dest, 8, "%d", destPort);

    } else if (ipHeader->ip_p == IPPROTO_UDP) {
        udpHeader_ptr udpHeader;
        udpHeader = (struct udphdr *) (packet->packetBody +
                                       sizeof(struct ether_header) +
                                       sizeof(struct ip));

        sourcePort = ntohs(udpHeader->source);
        destPort = ntohs(udpHeader->dest);

        transportHeader->length = 8;

        snprintf(transportHeader->source, 8, "%d", sourcePort);
        snprintf(transportHeader->dest, 8, "%d", destPort);
    }

    return transportHeader;
}

extern char *yaidspcap_parse_pcap_headers_get_nettype(etherHeader_ptr etherHeader)      //LGTM[cpp/poorly-documented-function] - Lengthy SWITCH
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

extern char *yaidspcap_parse_pcap_headers_get_transporttype(ipHeader_ptr
                                                            ipHeader)
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

extern void yaidspcap_parse_pcap_headers_results(yaidsPcapPacketHeader_ptr
                                                 parsedPacketHeaders,
                                                 yaidsPcapPacketHeaderFrame_ptr
                                                 frameHeader,
                                                 yaidsPcapPacketHeaderNet_ptr
                                                 netHeader,
                                                 yaidsPcapPacketHeaderTransport_ptr
                                                 transportHeader)
{
    if (transportHeader != NULL) {
        parsedPacketHeaders->frameExists = true;
        parsedPacketHeaders->netExists = true;
        parsedPacketHeaders->transportExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s/%s/%s",
                 frameHeader->type, netHeader->type,
                 transportHeader->type);

        sec_str_cpy(parsedPacketHeaders->frameType, frameHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->frameSource, frameHeader->source,
                    INET6_ADDRSTRLEN + 1);
        sec_str_cpy(parsedPacketHeaders->frameDest, frameHeader->dest,
                    INET6_ADDRSTRLEN + 1);

        sec_str_cpy(parsedPacketHeaders->netType, netHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->netSource, netHeader->source,
                    INET6_ADDRSTRLEN + 1);
        sec_str_cpy(parsedPacketHeaders->netDest, netHeader->dest,
                    INET6_ADDRSTRLEN + 1);

        sec_str_cpy(parsedPacketHeaders->transportType,
                    transportHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->transportSource,
                    transportHeader->source, 10);
        sec_str_cpy(parsedPacketHeaders->transportDest,
                    transportHeader->dest, 10);

        parsedPacketHeaders->payloadOffset =
            frameHeader->length + netHeader->length +
            transportHeader->length;
    } else if (netHeader != NULL) {
        parsedPacketHeaders->frameExists = true;
        parsedPacketHeaders->netExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s/%s",
                 frameHeader->type, netHeader->type);

        sec_str_cpy(parsedPacketHeaders->frameType, frameHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->frameSource, frameHeader->source,
                    INET6_ADDRSTRLEN + 1);
        sec_str_cpy(parsedPacketHeaders->frameDest, frameHeader->dest,
                    INET6_ADDRSTRLEN + 1);

        sec_str_cpy(parsedPacketHeaders->netType, netHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->netSource, netHeader->source,
                    INET6_ADDRSTRLEN + 1);
        sec_str_cpy(parsedPacketHeaders->netDest, netHeader->dest,
                    INET6_ADDRSTRLEN + 1);

        sec_str_cpy(parsedPacketHeaders->transportType, "UNKN", 14);

        parsedPacketHeaders->payloadOffset =
            frameHeader->length + netHeader->length;
    } else if (frameHeader != NULL) {
        parsedPacketHeaders->frameExists = true;

        snprintf(parsedPacketHeaders->typeList, 42, "%s",
                 frameHeader->type);

        sec_str_cpy(parsedPacketHeaders->frameType, frameHeader->type, 14);
        sec_str_cpy(parsedPacketHeaders->frameSource, frameHeader->source,
                    INET6_ADDRSTRLEN + 1);
        sec_str_cpy(parsedPacketHeaders->frameDest, frameHeader->dest,
                    INET6_ADDRSTRLEN + 1);

        sec_str_cpy(parsedPacketHeaders->netType, "UNKN", 14);
        sec_str_cpy(parsedPacketHeaders->transportType, "UNKN", 14);

        parsedPacketHeaders->payloadOffset = frameHeader->length;
    } else {
        parsedPacketHeaders->payloadOffset = 0;
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

        etherHeader = (etherHeader_ptr) packet->packetBody;
        frameHeader = yaidspcap_parse_pcap_headers_frame(etherHeader);

        if (ntohs(etherHeader->ether_type) == ETHERTYPE_IP
            || ntohs(etherHeader->ether_type) == ETHERTYPE_IPV6) {
            ipHeader =
                (struct ip *) (packet->packetBody +
                               sizeof(struct ether_header));

            netHeader =
                yaidspcap_parse_pcap_headers_net(etherHeader, ipHeader);
            transportHeader =
                yaidspcap_parse_pcap_headers_transport(packet, ipHeader);
        } else {
            netHeader =
                yaidspcap_parse_pcap_headers_net(etherHeader, ipHeader);
        }
    } else if (packet->packetHeader->len == ETH_HEADER_SIZE) {
        sec_str_cpy(parsedPacketHeaders->typeList, "ETH", 10);
    } else {
        sec_str_cpy(parsedPacketHeaders->typeList, "UNKN", 10);
    }

    yaidspcap_parse_pcap_headers_results(parsedPacketHeaders, frameHeader,
                                         netHeader, transportHeader);

    parsedPacketHeaders->originalPacketLength = packet->packetHeader->len;

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

extern char *yaids_ether_ntoa(etherAddress_ptr address)
{
    char *fullAddress;
    fullAddress = calloc(18, sizeof(char));
    return yaids_ether_ntoa_r(address, fullAddress);
}

extern char *yaids_ether_ntoa_r(etherAddress_ptr address, char *buffer)
{
    snprintf(buffer, 18, "%02X:%02X:%02X:%02X:%02X:%02X",
             address->ether_addr_octet[0], address->ether_addr_octet[1],
             address->ether_addr_octet[2], address->ether_addr_octet[3],
             address->ether_addr_octet[4], address->ether_addr_octet[5]);
    return buffer;
}
