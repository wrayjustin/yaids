---
title: yaidspcap
permalink: code/headers/yaidspcap
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


[Macros](#define-members) | [Functions](#func-members)

yaidspcap.h File Reference

`#include <pcap.h>`  

Include dependency graph for yaidspcap.h:

![](/images/yaidspcap_8h__incl.png)


<span id="define-members"></span> Macros
----------------------------------------

\#define 

<a href="/code/headers/yaidspcap#a3106835123967aabc7080e171ce08c5d" class="el">ETH_HEADER_SIZE</a>   14

 

\#define 

<a href="/code/headers/yaidspcap#a0fe4f2bb2f6199a68a7c09c66192349c" class="el">PKT_PREPROC_HDR_SIZE</a>   255

 

<span id="func-members"></span> Functions
-----------------------------------------

void 

<a href="/code/headers/yaidspcap#a5e712302c4e043cdc4672296d8c81350" class="el">yaidspcap_init</a>
(<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle)

 

<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> 

<a href="/code/headers/yaidspcap#ace5902a3f5f3bec37096a0c430a2e7b6" class="el">yaidspcap_new_packet</a>
(int size)

 

int 

<a href="/code/headers/yaidspcap#a43c5bb0d628ab0f5a83f0faae1782b8c" class="el">yaidspcap_create_handle</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle)

 

void 

<a href="/code/headers/yaidspcap#aee3298fdf3edb5c50d30b38713ad787e" class="el">yaidspcap_read_packets</a>
(<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a825a0af79113da5b1689b527b092c1a7" class="el">yaidsPcapCallbackArgs_ptr</a>
callbackArgs)

 

void 

<a href="/code/headers/yaidspcap#a523a3bd2d0dd085380b9a2fa5fea466b" class="el">yaidspcap_read_callback</a>
(u\_char \*args, const struct pcap\_pkthdr \*packetHeader, const u\_char
\*packetBody)

 

u\_char \* 

<a href="/code/headers/yaidspcap#a89d6a31d637bdaffc15790daa086468d" class="el">yaidspcap_get_yara_packet_header</a>
(<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a>
parsedPacketHeaders, u\_char \*yaraPacketHeader)

 

<a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a> 

<a href="/code/headers/yaidspcap#abe880eda863f945d86f546fad8983af2" class="el">yaidspcap_parse_pcap_headers_frame</a>
(<a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a>
etherHeader)

 

<a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a> 

<a href="/code/headers/yaidspcap#ab8af351604e8bd55a94b9175ee5a4f63" class="el">yaidspcap_parse_pcap_headers_net</a>
(<a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a>
etherHeader,
<a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a>
ipHeader)

 

<a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a> 

<a href="/code/headers/yaidspcap#a69bd9b8a44bdb12e79b0ec7490f57130" class="el">yaidspcap_parse_pcap_headers_transport</a>
(<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet,
<a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a>
ipHeader)

 

char \* 

<a href="/code/headers/yaidspcap#ad3ba78c1742b6e7dcf1c94dd53b3c42d" class="el">yaidspcap_parse_pcap_headers_get_nettype</a>
(<a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a>
etherHeader)

 

char \* 

<a href="/code/headers/yaidspcap#ac33324aea024413b8fe23bd162c89452" class="el">yaidspcap_parse_pcap_headers_get_transporttype</a>
(<a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a>
ipHeader)

 

void 

<a href="/code/headers/yaidspcap#a5d3cd3ef039d37e3bfd1b70659fe6b3b" class="el">yaidspcap_parse_pcap_headers_results</a>
(<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a>
parsedPacketHeaders,
<a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a>
frameHeader,
<a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a>
netHeader,
<a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a>
transportHeader)

 

void 

<a href="/code/headers/yaidspcap#a5a81eaf2fa95a68942e1370fe82896d0" class="el">yaidspcap_parse_pcap_headers</a>
(<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet,
<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a>
parsedPacketHeaders)

 

FILE \* 

<a href="/code/headers/yaidspcap#a71d20147f85765fb39a53d7853e1f37e" class="el">yaidspcap_open_output_pcap_file</a>
(<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

void 

<a href="/code/headers/yaidspcap#a548ab1c54a6f9701d5b4f427d5859622" class="el">yaidspcap_write_packet</a>
(FILE \*pcapFileHandle,
<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet)

 

void 

<a href="/code/headers/yaidspcap#a68d248375c8b2291890aed45b36bbbbf" class="el">yaidspcap_flush_output</a>
(FILE \*pcapFileHandle)

 

void 

<a href="/code/headers/yaidspcap#ad4c2e7bdcb8a9eb5f6d7ef894bc6c047" class="el">yaidspcap_finish</a>
(void)

 

char \* 

<a href="/code/headers/yaidspcap#ad5d408082e8916bd7b02928f7568b93d" class="el">yaids_ether_ntoa</a>
(<a href="/code/headers/yaidstypes#ae4f647cb95d4f79f32fd2f0fc754a584" class="el">etherAddress_ptr</a>
address)

 

char \* 

<a href="/code/headers/yaidspcap#a623ca8a245b336d3068f0ad93e6a6292" class="el">yaids_ether_ntoa_r</a>
(<a href="/code/headers/yaidstypes#ae4f647cb95d4f79f32fd2f0fc754a584" class="el">etherAddress_ptr</a>
address, char \*buffer)

 

Macro Definition Documentation
------------------------------

<span id="a3106835123967aabc7080e171ce08c5d"></span>

<span class="permalink">[◆ ](#a3106835123967aabc7080e171ce08c5d)</span>ETH\_HEADER\_SIZE
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define ETH_HEADER_SIZE   14</td>
</tr>
</tbody>
</table>

<span id="a0fe4f2bb2f6199a68a7c09c66192349c"></span>

<span class="permalink">[◆ ](#a0fe4f2bb2f6199a68a7c09c66192349c)</span>PKT\_PREPROC\_HDR\_SIZE
----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define PKT_PREPROC_HDR_SIZE   255</td>
</tr>
</tbody>
</table>

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
<td><a href="/code/headers/yaidstypes#ae4f647cb95d4f79f32fd2f0fc754a584" class="el">etherAddress_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#ae4f647cb95d4f79f32fd2f0fc754a584" class="el">etherAddress_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
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

<span id="ad4c2e7bdcb8a9eb5f6d7ef894bc6c047"></span>

<span class="permalink">[◆ ](#ad4c2e7bdcb8a9eb5f6d7ef894bc6c047)</span>yaidspcap\_finish()
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidspcap_finish</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
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
<td><a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> yaidspcap_new_packet</td>
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
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
<td><em>packet</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a> yaidspcap_parse_pcap_headers_frame</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a> yaidspcap_parse_pcap_headers_net</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a> </td>
<td><em>etherHeader</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> </td>
<td><em>parsedPacketHeaders</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a> </td>
<td><em>frameHeader</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a> </td>
<td><em>netHeader</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a> yaidspcap_parse_pcap_headers_transport</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
<td><em>packet</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a825a0af79113da5b1689b527b092c1a7" class="el">yaidsPcapCallbackArgs_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
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
