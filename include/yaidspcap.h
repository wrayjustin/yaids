/*
 *  yaidspcap.h - YAIDS PCAP Headers
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

#include <pcap.h>

#ifndef yaidspcap
#define yaidspcap

#define ETH_HEADER_SIZE                     14

extern void yaidspcap_init(yaidsPcapHandle_ptr pcapHandle);
extern yaidsPcapPacket_ptr yaidspcap_new_packet(int size);
extern int yaidspcap_create_handle(yaidsConfig_ptr config,
                                   yaidsPcapHandle_ptr pcapHandle);
extern void yaidspcap_read_packets(yaidsPcapHandle_ptr pcapHandle,
                                   yaidsPcapCallbackArgs_ptr callbackArgs);
extern void yaidspcap_read_callback(u_char * args,
                                    const struct pcap_pkthdr *packetHeader,
                                    const u_char * packetBody);
extern yaidsPcapPacketHeaderFrame_ptr yaidspcap_parse_pcap_headers_frame(etherHeader_ptr etherHeader);
extern yaidsPcapPacketHeaderNet_ptr yaidspcap_parse_pcap_headers_net(etherHeader_ptr etherHeader, ipHeader_ptr ipHeader);
extern yaidsPcapPacketHeaderTransport_ptr yaidspcap_parse_pcap_headers_transport(yaidsPcapPacket_ptr packet, ipHeader_ptr ipHeader);
extern char* yaidspcap_parse_pcap_headers_get_nettype(etherHeader_ptr etherHeader);
extern char* yaidspcap_parse_pcap_headers_get_transporttype(ipHeader_ptr ipHeader);
extern void yaidspcap_parse_pcap_headers_results(yaidsPcapPacketHeader_ptr parsedPacketHeaders, yaidsPcapPacketHeaderFrame_ptr frameHeader, yaidsPcapPacketHeaderNet_ptr netHeader, yaidsPcapPacketHeaderTransport_ptr transportHeader);
extern void yaidspcap_parse_pcap_headers(yaidsPcapPacket_ptr packet,
                                         yaidsPcapPacketHeader_ptr
                                         parsedPacketHeaders);
extern FILE *yaidspcap_open_output_pcap_file(yaidsPcapHandle_ptr
                                             pcapHandle,
                                             yaidsConfig_ptr config);
extern void yaidspcap_write_packet(FILE * pcapFileHandle,
                                   yaidsPcapPacket_ptr packet);
extern void yaidspcap_flush_output(FILE * pcapFileHandle);
extern void yaidspcap_finish(void);

#endif
