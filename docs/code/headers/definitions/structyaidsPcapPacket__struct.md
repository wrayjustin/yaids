---
title: structyaidsPcapPacket__struct
permalink: code/headers/definitions/structyaidsPcapPacket__struct
---
# structyaidsPcapPacket__struct

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


yaidsPcapPacket\_struct Struct Reference

`#include <yaidstypes.h>`

Collaboration diagram for yaidsPcapPacket\_struct:

![Collaboration graph](/images/structyaidsPcapPacket__struct__coll__graph.png)


<span id="pub-attribs"></span> Public Attributes
------------------------------------------------

bool 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a82da52da11aa9df10a0418f60f1a6fc0" class="el">yaraFinished</a>

 

bool 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#ab514caa0b2819cb8aa839fc4de625c9f" class="el">pcapWritten</a>

 

int 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a448ffb0db641a0250693f0744553fee1" class="el">alertCount</a>

 

int 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#ae1777dbbdb191a1812e75960f5e09f9e" class="el">packetSize</a>

 

const struct pcap\_pkthdr \* 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a46dd80f931f413c395bb7160566ad4fe" class="el">packetHeader</a>

 

const u\_char \* 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a209f36caa875f01145f31a9f7bae2a3c" class="el">packetBody</a>

 

u\_char \* 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a01b4cd559fb0dac3e2e63d3800775899" class="el">yaraPacket</a>

 

<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> 

<a href="/code/headers/definitions/structyaidsPcapPacket__struct#a5a7b429855a2f85d9f24ab4a73578d26" class="el">parsedPacketHeaders</a>

 

Member Data Documentation
-------------------------

<span id="a448ffb0db641a0250693f0744553fee1"></span>

<span class="permalink">[◆ ](#a448ffb0db641a0250693f0744553fee1)</span>alertCount
---------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsPcapPacket_struct::alertCount</td>
</tr>
</tbody>
</table>

<span id="a209f36caa875f01145f31a9f7bae2a3c"></span>

<span class="permalink">[◆ ](#a209f36caa875f01145f31a9f7bae2a3c)</span>packetBody
---------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const u_char* yaidsPcapPacket_struct::packetBody</td>
</tr>
</tbody>
</table>

<span id="a46dd80f931f413c395bb7160566ad4fe"></span>

<span class="permalink">[◆ ](#a46dd80f931f413c395bb7160566ad4fe)</span>packetHeader
-----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const struct pcap_pkthdr* yaidsPcapPacket_struct::packetHeader</td>
</tr>
</tbody>
</table>

<span id="ae1777dbbdb191a1812e75960f5e09f9e"></span>

<span class="permalink">[◆ ](#ae1777dbbdb191a1812e75960f5e09f9e)</span>packetSize
---------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsPcapPacket_struct::packetSize</td>
</tr>
</tbody>
</table>

<span id="a5a7b429855a2f85d9f24ab4a73578d26"></span>

<span class="permalink">[◆ ](#a5a7b429855a2f85d9f24ab4a73578d26)</span>parsedPacketHeaders
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td><a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> yaidsPcapPacket_struct::parsedPacketHeaders</td>
</tr>
</tbody>
</table>

<span id="ab514caa0b2819cb8aa839fc4de625c9f"></span>

<span class="permalink">[◆ ](#ab514caa0b2819cb8aa839fc4de625c9f)</span>pcapWritten
----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool yaidsPcapPacket_struct::pcapWritten</td>
</tr>
</tbody>
</table>

<span id="a82da52da11aa9df10a0418f60f1a6fc0"></span>

<span class="permalink">[◆ ](#a82da52da11aa9df10a0418f60f1a6fc0)</span>yaraFinished
-----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool yaidsPcapPacket_struct::yaraFinished</td>
</tr>
</tbody>
</table>

<span id="a01b4cd559fb0dac3e2e63d3800775899"></span>

<span class="permalink">[◆ ](#a01b4cd559fb0dac3e2e63d3800775899)</span>yaraPacket
---------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>u_char* yaidsPcapPacket_struct::yaraPacket</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

The documentation for this struct was generated from the following file:

-   include/<a href="/code/headers/yaidstypes" class="el">yaidstypes.h</a>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
