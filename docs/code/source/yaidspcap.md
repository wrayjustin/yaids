---
title: yaidspcap
permalink: code/source/yaidspcap
---
# yaidspcap

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><img src="/yaids.png" alt="Logo" /></td>
<td><div id="projectname">
YAIDS
</div></td>
</tr>
</tbody>
</table>


[Functions](#func-members)

yaidspcap.c File Reference

`#include <config.h>`  
`#include <ctype.h>`  
`#include <stdio.h>`  
`#include <stdlib.h>`  
`#include <unistd.h>`  
`#include <stdbool.h>`  
`#include <malloc.h>`  
`#include <yaids.h>`  
`#include <yaidstypes.h>`  
`#include <yaidsconf.h>`  
`#include <yaidsio.h>`  
`#include <yaidspcap.h>`  
`#include <yaidsyara.h>`  
`#include <yaidsthread.h>`  
`#include <pcap.h>`  
`#include <sys/socket.h>`  
`#include <arpa/inet.h>`  
`#include <net/ethernet.h>`  
`#include <netinet/in.h>`  
`#include <netinet/ether.h>`  
`#include <netinet/if_ether.h>`  
`#include <netinet/ip.h>`  
`#include <netinet/tcp.h>`  
`#include <netinet/udp.h>`  
`#include <ethertypes.h>`  

Include dependency graph for yaidspcap.c:

![](/images/yaidspcap_8c__incl.png)

<span id="func-members"></span> Functions
-----------------------------------------

void 

<a href="/code/source/yaidspcap#a5e712302c4e043cdc4672296d8c81350" class="el">yaidspcap_init</a>
(yaidsPcapHandle\_ptr pcapHandle)

 

yaidsPcapPacket\_ptr 

<a href="/code/source/yaidspcap#ace5902a3f5f3bec37096a0c430a2e7b6" class="el">yaidspcap_new_packet</a>
(int size)

 

int 

<a href="/code/source/yaidspcap#a43c5bb0d628ab0f5a83f0faae1782b8c" class="el">yaidspcap_create_handle</a>
(yaidsConfig\_ptr config, yaidsPcapHandle\_ptr pcapHandle)

 

void 

<a href="/code/source/yaidspcap#aee3298fdf3edb5c50d30b38713ad787e" class="el">yaidspcap_read_packets</a>
(yaidsPcapHandle\_ptr pcapHandle, yaidsPcapCallbackArgs\_ptr
callbackArgs)

 

void 

<a href="/code/source/yaidspcap#a523a3bd2d0dd085380b9a2fa5fea466b" class="el">yaidspcap_read_callback</a>
(u\_char \*args, const struct pcap\_pkthdr \*packetHeader, const u\_char
\*packetBody)

 

u\_char \* 

<a href="/code/source/yaidspcap#a89d6a31d637bdaffc15790daa086468d" class="el">yaidspcap_get_yara_packet_header</a>
(yaidsPcapPacketHeader\_ptr parsedPacketHeaders, u\_char
\*yaraPacketHeader)

 

yaidsPcapPacketHeaderFrame\_ptr 

<a href="/code/source/yaidspcap#abe880eda863f945d86f546fad8983af2" class="el">yaidspcap_parse_pcap_headers_frame</a>
(etherHeader\_ptr etherHeader)

 

yaidsPcapPacketHeaderNet\_ptr 

<a href="/code/source/yaidspcap#ab8af351604e8bd55a94b9175ee5a4f63" class="el">yaidspcap_parse_pcap_headers_net</a>
(etherHeader\_ptr etherHeader, ipHeader\_ptr ipHeader)

 

yaidsPcapPacketHeaderTransport\_ptr 

<a href="/code/source/yaidspcap#a69bd9b8a44bdb12e79b0ec7490f57130" class="el">yaidspcap_parse_pcap_headers_transport</a>
(yaidsPcapPacket\_ptr packet, ipHeader\_ptr ipHeader)

 

char \* 

<a href="/code/source/yaidspcap#ad3ba78c1742b6e7dcf1c94dd53b3c42d" class="el">yaidspcap_parse_pcap_headers_get_nettype</a>
(etherHeader\_ptr etherHeader)

 

char \* 

<a href="/code/source/yaidspcap#ac33324aea024413b8fe23bd162c89452" class="el">yaidspcap_parse_pcap_headers_get_transporttype</a>
(ipHeader\_ptr ipHeader)

 

void 

<a href="/code/source/yaidspcap#a5d3cd3ef039d37e3bfd1b70659fe6b3b" class="el">yaidspcap_parse_pcap_headers_results</a>
(yaidsPcapPacketHeader\_ptr parsedPacketHeaders,
yaidsPcapPacketHeaderFrame\_ptr frameHeader,
yaidsPcapPacketHeaderNet\_ptr netHeader,
yaidsPcapPacketHeaderTransport\_ptr transportHeader)

 

void 

<a href="/code/source/yaidspcap#a5a81eaf2fa95a68942e1370fe82896d0" class="el">yaidspcap_parse_pcap_headers</a>
(yaidsPcapPacket\_ptr packet, yaidsPcapPacketHeader\_ptr
parsedPacketHeaders)

 

FILE \* 

<a href="/code/source/yaidspcap#a71d20147f85765fb39a53d7853e1f37e" class="el">yaidspcap_open_output_pcap_file</a>
(yaidsPcapHandle\_ptr pcapHandle, yaidsConfig\_ptr config)

 

void 

<a href="/code/source/yaidspcap#a548ab1c54a6f9701d5b4f427d5859622" class="el">yaidspcap_write_packet</a>
(FILE \*pcapFileHandle, yaidsPcapPacket\_ptr packet)

 

void 

<a href="/code/source/yaidspcap#a68d248375c8b2291890aed45b36bbbbf" class="el">yaidspcap_flush_output</a>
(FILE \*pcapFileHandle)

 

char \* 

<a href="/code/source/yaidspcap#ad5d408082e8916bd7b02928f7568b93d" class="el">yaids_ether_ntoa</a>
(etherAddress\_ptr address)

 

char \* 

<a href="/code/source/yaidspcap#a623ca8a245b336d3068f0ad93e6a6292" class="el">yaids_ether_ntoa_r</a>
(etherAddress\_ptr address, char \*buffer)

 

Function Documentation
----------------------

<span id="ad5d408082e8916bd7b02928f7568b93d"></span>

<span class="permalink">[◆ ](#ad5d408082e8916bd7b02928f7568b93d)</span>yaids\_ether\_ntoa()
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaids_ether_ntoa</td>
<td>(</td>
<td>etherAddress_ptr </td>
<td><em>address</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a623ca8a245b336d3068f0ad93e6a6292"></span>

<span class="permalink">[◆ ](#a623ca8a245b336d3068f0ad93e6a6292)</span>yaids\_ether\_ntoa\_r()
----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaids_ether_ntoa_r</td>
<td>(</td>
<td>etherAddress_ptr </td>
<td><em>address</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>buffer</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a43c5bb0d628ab0f5a83f0faae1782b8c"></span>

<span class="permalink">[◆ ](#a43c5bb0d628ab0f5a83f0faae1782b8c)</span>yaidspcap\_create\_handle()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidspcap_create_handle</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a68d248375c8b2291890aed45b36bbbbf"></span>

<span class="permalink">[◆ ](#a68d248375c8b2291890aed45b36bbbbf)</span>yaidspcap\_flush\_output()
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_flush_output</td>
<td>(</td>
<td>FILE * </td>
<td><em>pcapFileHandle</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a89d6a31d637bdaffc15790daa086468d"></span>

<span class="permalink">[◆ ](#a89d6a31d637bdaffc15790daa086468d)</span>yaidspcap\_get\_yara\_packet\_header()
-------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>u_char* yaidspcap_get_yara_packet_header</td>
<td>(</td>
<td>yaidsPcapPacketHeader_ptr </td>
<td><em>parsedPacketHeaders</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>u_char * </td>
<td><em>yaraPacketHeader</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a5e712302c4e043cdc4672296d8c81350"></span>

<span class="permalink">[◆ ](#a5e712302c4e043cdc4672296d8c81350)</span>yaidspcap\_init()
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_init</td>
<td>(</td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ace5902a3f5f3bec37096a0c430a2e7b6"></span>

<span class="permalink">[◆ ](#ace5902a3f5f3bec37096a0c430a2e7b6)</span>yaidspcap\_new\_packet()
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsPcapPacket_ptr yaidspcap_new_packet</td>
<td>(</td>
<td>int </td>
<td><em>size</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a71d20147f85765fb39a53d7853e1f37e"></span>

<span class="permalink">[◆ ](#a71d20147f85765fb39a53d7853e1f37e)</span>yaidspcap\_open\_output\_pcap\_file()
------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>FILE* yaidspcap_open_output_pcap_file</td>
<td>(</td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsConfig_ptr </td>
<td><em>config</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a5a81eaf2fa95a68942e1370fe82896d0"></span>

<span class="permalink">[◆ ](#a5a81eaf2fa95a68942e1370fe82896d0)</span>yaidspcap\_parse\_pcap\_headers()
--------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_parse_pcap_headers</td>
<td>(</td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapPacketHeader_ptr </td>
<td><em>parsedPacketHeaders</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="abe880eda863f945d86f546fad8983af2"></span>

<span class="permalink">[◆ ](#abe880eda863f945d86f546fad8983af2)</span>yaidspcap\_parse\_pcap\_headers\_frame()
---------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsPcapPacketHeaderFrame_ptr yaidspcap_parse_pcap_headers_frame</td>
<td>(</td>
<td>etherHeader_ptr </td>
<td><em>etherHeader</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ad3ba78c1742b6e7dcf1c94dd53b3c42d"></span>

<span class="permalink">[◆ ](#ad3ba78c1742b6e7dcf1c94dd53b3c42d)</span>yaidspcap\_parse\_pcap\_headers\_get\_nettype()
----------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidspcap_parse_pcap_headers_get_nettype</td>
<td>(</td>
<td>etherHeader_ptr </td>
<td><em>etherHeader</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ac33324aea024413b8fe23bd162c89452"></span>

<span class="permalink">[◆ ](#ac33324aea024413b8fe23bd162c89452)</span>yaidspcap\_parse\_pcap\_headers\_get\_transporttype()
----------------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidspcap_parse_pcap_headers_get_transporttype</td>
<td>(</td>
<td>ipHeader_ptr </td>
<td><em>ipHeader</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ab8af351604e8bd55a94b9175ee5a4f63"></span>

<span class="permalink">[◆ ](#ab8af351604e8bd55a94b9175ee5a4f63)</span>yaidspcap\_parse\_pcap\_headers\_net()
-------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsPcapPacketHeaderNet_ptr yaidspcap_parse_pcap_headers_net</td>
<td>(</td>
<td>etherHeader_ptr </td>
<td><em>etherHeader</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>ipHeader_ptr </td>
<td><em>ipHeader</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a5d3cd3ef039d37e3bfd1b70659fe6b3b"></span>

<span class="permalink">[◆ ](#a5d3cd3ef039d37e3bfd1b70659fe6b3b)</span>yaidspcap\_parse\_pcap\_headers\_results()
-----------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_parse_pcap_headers_results</td>
<td>(</td>
<td>yaidsPcapPacketHeader_ptr </td>
<td><em>parsedPacketHeaders</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapPacketHeaderFrame_ptr </td>
<td><em>frameHeader</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsPcapPacketHeaderNet_ptr </td>
<td><em>netHeader</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapPacketHeaderTransport_ptr </td>
<td><em>transportHeader</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a69bd9b8a44bdb12e79b0ec7490f57130"></span>

<span class="permalink">[◆ ](#a69bd9b8a44bdb12e79b0ec7490f57130)</span>yaidspcap\_parse\_pcap\_headers\_transport()
-------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsPcapPacketHeaderTransport_ptr yaidspcap_parse_pcap_headers_transport</td>
<td>(</td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>ipHeader_ptr </td>
<td><em>ipHeader</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a523a3bd2d0dd085380b9a2fa5fea466b"></span>

<span class="permalink">[◆ ](#a523a3bd2d0dd085380b9a2fa5fea466b)</span>yaidspcap\_read\_callback()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_read_callback</td>
<td>(</td>
<td>u_char * </td>
<td><em>args</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>const struct pcap_pkthdr * </td>
<td><em>packetHeader</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>const u_char * </td>
<td><em>packetBody</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="aee3298fdf3edb5c50d30b38713ad787e"></span>

<span class="permalink">[◆ ](#aee3298fdf3edb5c50d30b38713ad787e)</span>yaidspcap\_read\_packets()
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_read_packets</td>
<td>(</td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapCallbackArgs_ptr </td>
<td><em>callbackArgs</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a548ab1c54a6f9701d5b4f427d5859622"></span>

<span class="permalink">[◆ ](#a548ab1c54a6f9701d5b4f427d5859622)</span>yaidspcap\_write\_packet()
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_write_packet</td>
<td>(</td>
<td>FILE * </td>
<td><em>pcapFileHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
