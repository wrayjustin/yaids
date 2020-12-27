---
title: yaidstypes
permalink: code/headers/yaidstypes
---
# yaidstypes

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


[Classes](#nested-classes) | [Typedefs](#typedef-members)

yaidstypes.h File Reference

`#include <ctype.h>`  
`#include <stdio.h>`  
`#include <stdlib.h>`  
`#include <unistd.h>`  
`#include <stdbool.h>`  
`#include <pcap.h>`  
`#include <yara.h>`  
`#include <netinet/in.h>`  

Include dependency graph for yaidstypes.h:

![](/images/yaidstypes_8h__incl.png)


<span id="nested-classes"></span> Classes
-----------------------------------------

struct  

<a href="/code/headers/definitions/structyaidsConfig__struct" class="el">yaidsConfig_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsThreadStatuses__struct" class="el">yaidsThreadStatuses_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPacketCounts__struct" class="el">yaidsPacketCounts_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapHandle__struct" class="el">yaidsPcapHandle_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsYaraScanner__struct" class="el">yaidsYaraScanner_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsThreadReturn__struct" class="el">yaidsThreadReturn_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsThreadInfo__struct" class="el">yaidsThreadInfo_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsThreadList__struct" class="el">yaidsThreadList_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsInputDataNode__struct" class="el">yaidsInputDataNode_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsInputDataQueue__struct" class="el">yaidsInputDataQueue_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsInputThreadArgs__struct" class="el">yaidsInputThreadArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsOutputDataNode__struct" class="el">yaidsOutputDataNode_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsOutputDataQueue__struct" class="el">yaidsOutputDataQueue_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsOutputThreadArgs__struct" class="el">yaidsOutputThreadArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsYaraThreadArgs__struct" class="el">yaidsYaraThreadArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapCallbackArgs__struct" class="el">yaidsPcapCallbackArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsYaraCallbackArgs__struct" class="el">yaidsYaraCallbackArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsTimelimitThreadArgs__struct" class="el">yaidsTimelimitThreadArgs_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapPacket__struct" class="el">yaidsPcapPacket_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct" class="el">yaidsPcapPacketHeader_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapPacketHeaderFrame__struct" class="el">yaidsPcapPacketHeaderFrame_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapPacketHeaderNet__struct" class="el">yaidsPcapPacketHeaderNet_struct</a>

 

struct  

<a href="/code/headers/definitions/structyaidsPcapPacketHeaderTransport__struct" class="el">yaidsPcapPacketHeaderTransport_struct</a>

 

<span id="typedef-members"></span> Typedefs
-------------------------------------------

typedef struct
<a href="/code/headers/definitions/structyaidsConfig__struct" class="el">yaidsConfig_struct</a> 

<a href="/code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsInputDataNode__struct" class="el">yaidsInputDataNode_struct</a> 

<a href="/code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsInputDataQueue__struct" class="el">yaidsInputDataQueue_struct</a> 

<a href="/code/headers/yaidstypes#a9416c3f3d37c4814c8589ce2e543ced1" class="el">yaidsInputDataQueue</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsInputThreadArgs__struct" class="el">yaidsInputThreadArgs_struct</a> 

<a href="/code/headers/yaidstypes#af53f00f8c3b8c5933df21d5c7c8e89b7" class="el">yaidsInputThreadArgs</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsOutputDataNode__struct" class="el">yaidsOutputDataNode_struct</a> 

<a href="/code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsOutputDataQueue__struct" class="el">yaidsOutputDataQueue_struct</a> 

<a href="/code/headers/yaidstypes#a8a36b30b7f7872be775abbd981b3465f" class="el">yaidsOutputDataQueue</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsOutputThreadArgs__struct" class="el">yaidsOutputThreadArgs_struct</a> 

<a href="/code/headers/yaidstypes#a439e91d690d4202764f88303b2f8b2fa" class="el">yaidsOutputThreadArgs</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPacketCounts__struct" class="el">yaidsPacketCounts_struct</a> 

<a href="/code/headers/yaidstypes#a4af6b5c88027339afb92dcc79195d292" class="el">yaidsPacketCounts</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapCallbackArgs__struct" class="el">yaidsPcapCallbackArgs_struct</a> 

<a href="/code/headers/yaidstypes#a1e3c31fcc01fff2f3ffe3f3f8a0a5788" class="el">yaidsPcapCallbackArgs</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapHandle__struct" class="el">yaidsPcapHandle_struct</a> 

<a href="/code/headers/yaidstypes#a3e08f70a7402496739a5a38b38a8faea" class="el">yaidsPcapHandle</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapPacket__struct" class="el">yaidsPcapPacket_struct</a> 

<a href="/code/headers/yaidstypes#a457ce0d8c685ca0941dc578db3ba1ce9" class="el">yaidsPcapPacket</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct" class="el">yaidsPcapPacketHeader_struct</a> 

<a href="/code/headers/yaidstypes#aea55c17402dd740b2776830781639699" class="el">yaidsPcapPacketHeader</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapPacketHeaderFrame__struct" class="el">yaidsPcapPacketHeaderFrame_struct</a> 

<a href="/code/headers/yaidstypes#a64717bb04254e372be57f6845439fea5" class="el">yaidsPcapPacketHeaderFrame</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapPacketHeaderNet__struct" class="el">yaidsPcapPacketHeaderNet_struct</a> 

<a href="/code/headers/yaidstypes#a48efc5671f472686cc3f59cfc3f85142" class="el">yaidsPcapPacketHeaderNet</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsPcapPacketHeaderTransport__struct" class="el">yaidsPcapPacketHeaderTransport_struct</a> 

<a href="/code/headers/yaidstypes#a5099093658d242bb84350d0bb5419b74" class="el">yaidsPcapPacketHeaderTransport</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsThreadInfo__struct" class="el">yaidsThreadInfo_struct</a> 

<a href="/code/headers/yaidstypes#a5b58a4556454efcb808e03e8ed82d694" class="el">yaidsThreadInfo</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsThreadList__struct" class="el">yaidsThreadList_struct</a> 

<a href="/code/headers/yaidstypes#ae21dce6821977e760cf977353f49ce03" class="el">yaidsThreadList</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsThreadReturn__struct" class="el">yaidsThreadReturn_struct</a> 

<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsThreadStatuses__struct" class="el">yaidsThreadStatuses_struct</a> 

<a href="/code/headers/yaidstypes#a694f1fbdc4be7263d8d00db00b38b957" class="el">yaidsThreadStatuses</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsTimelimitThreadArgs__struct" class="el">yaidsTimelimitThreadArgs_struct</a> 

<a href="/code/headers/yaidstypes#aec4f4a6d262531800b69c36adbbb9aee" class="el">yaidsTimelimitThreadArgs</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsYaraCallbackArgs__struct" class="el">yaidsYaraCallbackArgs_struct</a> 

<a href="/code/headers/yaidstypes#a7660cbddc6e6e0a31070ac16988ece6a" class="el">yaidsYaraCallbackArgs</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsYaraScanner__struct" class="el">yaidsYaraScanner_struct</a> 

<a href="/code/headers/yaidstypes#a6a1290596928663cd2b8765b3fc124de" class="el">yaidsYaraScanner</a>

 

typedef struct
<a href="/code/headers/definitions/structyaidsYaraThreadArgs__struct" class="el">yaidsYaraThreadArgs_struct</a> 

<a href="/code/headers/yaidstypes#a25dc61de27086a9385c2333c9fb7f11a" class="el">yaidsYaraThreadArgs</a>

 

typedef
<a href="/code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a>
\* 

<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a>
\* 

<a href="/code/headers/yaidstypes#a19f71db535637ca80e5dc18dc95d92d3" class="el">yaidsInputDataNode_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a9416c3f3d37c4814c8589ce2e543ced1" class="el">yaidsInputDataQueue</a>
\* 

<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#af53f00f8c3b8c5933df21d5c7c8e89b7" class="el">yaidsInputThreadArgs</a>
\* 

<a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a>
\* 

<a href="/code/headers/yaidstypes#a2aa07c15f3e1d6bab8bc194f82a43e72" class="el">yaidsOutputDataNode_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a8a36b30b7f7872be775abbd981b3465f" class="el">yaidsOutputDataQueue</a>
\* 

<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a439e91d690d4202764f88303b2f8b2fa" class="el">yaidsOutputThreadArgs</a>
\* 

<a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a4af6b5c88027339afb92dcc79195d292" class="el">yaidsPacketCounts</a>
\* 

<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a1e3c31fcc01fff2f3ffe3f3f8a0a5788" class="el">yaidsPcapCallbackArgs</a>
\* 

<a href="/code/headers/yaidstypes#a825a0af79113da5b1689b527b092c1a7" class="el">yaidsPcapCallbackArgs_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a3e08f70a7402496739a5a38b38a8faea" class="el">yaidsPcapHandle</a>
\* 

<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a457ce0d8c685ca0941dc578db3ba1ce9" class="el">yaidsPcapPacket</a>
\* 

<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#aea55c17402dd740b2776830781639699" class="el">yaidsPcapPacketHeader</a>
\* 

<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a64717bb04254e372be57f6845439fea5" class="el">yaidsPcapPacketHeaderFrame</a>
\* 

<a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a48efc5671f472686cc3f59cfc3f85142" class="el">yaidsPcapPacketHeaderNet</a>
\* 

<a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a5099093658d242bb84350d0bb5419b74" class="el">yaidsPcapPacketHeaderTransport</a>
\* 

<a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a5b58a4556454efcb808e03e8ed82d694" class="el">yaidsThreadInfo</a>
\* 

<a href="/code/headers/yaidstypes#a41f17220799de0556349c9ee5245771f" class="el">yaidsThreadInfo_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#ae21dce6821977e760cf977353f49ce03" class="el">yaidsThreadList</a>
\* 

<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a>
\* 

<a href="/code/headers/yaidstypes#ad0778ec0b19a3f8946f3eb241104d00c" class="el">yaidsThreadReturn_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a694f1fbdc4be7263d8d00db00b38b957" class="el">yaidsThreadStatuses</a>
\* 

<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#aec4f4a6d262531800b69c36adbbb9aee" class="el">yaidsTimelimitThreadArgs</a>
\* 

<a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a7660cbddc6e6e0a31070ac16988ece6a" class="el">yaidsYaraCallbackArgs</a>
\* 

<a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a6a1290596928663cd2b8765b3fc124de" class="el">yaidsYaraScanner</a>
\* 

<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>

 

typedef
<a href="/code/headers/yaidstypes#a25dc61de27086a9385c2333c9fb7f11a" class="el">yaidsYaraThreadArgs</a>
\* 

<a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a>

 

typedef struct ether\_header \* 

<a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a>

 

typedef struct ip \* 

<a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a>

 

typedef struct tcphdr \* 

<a href="/code/headers/yaidstypes#af6a9a12a2433610fce8076835a3ba62d" class="el">tcpHeader_ptr</a>

 

typedef struct udphdr \* 

<a href="/code/headers/yaidstypes#a9f30cfd3ab718d9c37e3f2fc7d7bbb97" class="el">udpHeader_ptr</a>

 

Typedef Documentation
---------------------

<span id="a34b4c345014c857bc9f48312a919f7c4"></span>

<span class="permalink">[◆ ](#a34b4c345014c857bc9f48312a919f7c4)</span>etherHeader\_ptr
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct ether_header* <a href="/code/headers/yaidstypes#a34b4c345014c857bc9f48312a919f7c4" class="el">etherHeader_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a417d06d1cf7d4f1c873447e417602d83"></span>

<span class="permalink">[◆ ](#a417d06d1cf7d4f1c873447e417602d83)</span>ipHeader\_ptr
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct ip* <a href="/code/headers/yaidstypes#a417d06d1cf7d4f1c873447e417602d83" class="el">ipHeader_ptr</a></td>
</tr>
</tbody>
</table>

<span id="af6a9a12a2433610fce8076835a3ba62d"></span>

<span class="permalink">[◆ ](#af6a9a12a2433610fce8076835a3ba62d)</span>tcpHeader\_ptr
-------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct tcphdr* <a href="/code/headers/yaidstypes#af6a9a12a2433610fce8076835a3ba62d" class="el">tcpHeader_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a9f30cfd3ab718d9c37e3f2fc7d7bbb97"></span>

<span class="permalink">[◆ ](#a9f30cfd3ab718d9c37e3f2fc7d7bbb97)</span>udpHeader\_ptr
-------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct udphdr* <a href="/code/headers/yaidstypes#a9f30cfd3ab718d9c37e3f2fc7d7bbb97" class="el">udpHeader_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a84cc20039333a5a366f5b6d6b46a446b"></span>

<span class="permalink">[◆ ](#a84cc20039333a5a366f5b6d6b46a446b)</span>yaidsConfig
----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsConfig__struct" class="el">yaidsConfig_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a></td>
</tr>
</tbody>
</table>

<span id="a3ff4e6a77ab1ce71098854bbc6459802"></span>

<span class="permalink">[◆ ](#a3ff4e6a77ab1ce71098854bbc6459802)</span>yaidsConfig\_ptr
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a>* <a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a800a876dd63642e3db6c1ed28e185907"></span>

<span class="permalink">[◆ ](#a800a876dd63642e3db6c1ed28e185907)</span>yaidsInputDataNode
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsInputDataNode__struct" class="el">yaidsInputDataNode_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a></td>
</tr>
</tbody>
</table>

<span id="a19f71db535637ca80e5dc18dc95d92d3"></span>

<span class="permalink">[◆ ](#a19f71db535637ca80e5dc18dc95d92d3)</span>yaidsInputDataNode\_ptr
----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a>* <a href="/code/headers/yaidstypes#a19f71db535637ca80e5dc18dc95d92d3" class="el">yaidsInputDataNode_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a9416c3f3d37c4814c8589ce2e543ced1"></span>

<span class="permalink">[◆ ](#a9416c3f3d37c4814c8589ce2e543ced1)</span>yaidsInputDataQueue
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsInputDataQueue__struct" class="el">yaidsInputDataQueue_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a9416c3f3d37c4814c8589ce2e543ced1" class="el">yaidsInputDataQueue</a></td>
</tr>
</tbody>
</table>

<span id="a4b52561086d9bbae2b7e5a24b7767bf0"></span>

<span class="permalink">[◆ ](#a4b52561086d9bbae2b7e5a24b7767bf0)</span>yaidsInputDataQueue\_ptr
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a9416c3f3d37c4814c8589ce2e543ced1" class="el">yaidsInputDataQueue</a>* <a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a></td>
</tr>
</tbody>
</table>

<span id="af53f00f8c3b8c5933df21d5c7c8e89b7"></span>

<span class="permalink">[◆ ](#af53f00f8c3b8c5933df21d5c7c8e89b7)</span>yaidsInputThreadArgs
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsInputThreadArgs__struct" class="el">yaidsInputThreadArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#af53f00f8c3b8c5933df21d5c7c8e89b7" class="el">yaidsInputThreadArgs</a></td>
</tr>
</tbody>
</table>

<span id="a9566a88b439b34380a64a35dd380a588"></span>

<span class="permalink">[◆ ](#a9566a88b439b34380a64a35dd380a588)</span>yaidsInputThreadArgs\_ptr
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#af53f00f8c3b8c5933df21d5c7c8e89b7" class="el">yaidsInputThreadArgs</a>* <a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a4926527e9fc83914c36bed059daf777f"></span>

<span class="permalink">[◆ ](#a4926527e9fc83914c36bed059daf777f)</span>yaidsOutputDataNode
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsOutputDataNode__struct" class="el">yaidsOutputDataNode_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a></td>
</tr>
</tbody>
</table>

<span id="a2aa07c15f3e1d6bab8bc194f82a43e72"></span>

<span class="permalink">[◆ ](#a2aa07c15f3e1d6bab8bc194f82a43e72)</span>yaidsOutputDataNode\_ptr
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a>* <a href="/code/headers/yaidstypes#a2aa07c15f3e1d6bab8bc194f82a43e72" class="el">yaidsOutputDataNode_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a8a36b30b7f7872be775abbd981b3465f"></span>

<span class="permalink">[◆ ](#a8a36b30b7f7872be775abbd981b3465f)</span>yaidsOutputDataQueue
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsOutputDataQueue__struct" class="el">yaidsOutputDataQueue_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a8a36b30b7f7872be775abbd981b3465f" class="el">yaidsOutputDataQueue</a></td>
</tr>
</tbody>
</table>

<span id="a4964c6268238c2f5248ecf200bbafb12"></span>

<span class="permalink">[◆ ](#a4964c6268238c2f5248ecf200bbafb12)</span>yaidsOutputDataQueue\_ptr
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a8a36b30b7f7872be775abbd981b3465f" class="el">yaidsOutputDataQueue</a>* <a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a439e91d690d4202764f88303b2f8b2fa"></span>

<span class="permalink">[◆ ](#a439e91d690d4202764f88303b2f8b2fa)</span>yaidsOutputThreadArgs
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsOutputThreadArgs__struct" class="el">yaidsOutputThreadArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a439e91d690d4202764f88303b2f8b2fa" class="el">yaidsOutputThreadArgs</a></td>
</tr>
</tbody>
</table>

<span id="a9492ae9a8c7b48ba7ad8a8c8ab909a62"></span>

<span class="permalink">[◆ ](#a9492ae9a8c7b48ba7ad8a8c8ab909a62)</span>yaidsOutputThreadArgs\_ptr
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a439e91d690d4202764f88303b2f8b2fa" class="el">yaidsOutputThreadArgs</a>* <a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a4af6b5c88027339afb92dcc79195d292"></span>

<span class="permalink">[◆ ](#a4af6b5c88027339afb92dcc79195d292)</span>yaidsPacketCounts
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPacketCounts__struct" class="el">yaidsPacketCounts_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a4af6b5c88027339afb92dcc79195d292" class="el">yaidsPacketCounts</a></td>
</tr>
</tbody>
</table>

<span id="a0d30b24cf3be4d088d00205e27aa0130"></span>

<span class="permalink">[◆ ](#a0d30b24cf3be4d088d00205e27aa0130)</span>yaidsPacketCounts\_ptr
---------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a4af6b5c88027339afb92dcc79195d292" class="el">yaidsPacketCounts</a>* <a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a1e3c31fcc01fff2f3ffe3f3f8a0a5788"></span>

<span class="permalink">[◆ ](#a1e3c31fcc01fff2f3ffe3f3f8a0a5788)</span>yaidsPcapCallbackArgs
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapCallbackArgs__struct" class="el">yaidsPcapCallbackArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a1e3c31fcc01fff2f3ffe3f3f8a0a5788" class="el">yaidsPcapCallbackArgs</a></td>
</tr>
</tbody>
</table>

<span id="a825a0af79113da5b1689b527b092c1a7"></span>

<span class="permalink">[◆ ](#a825a0af79113da5b1689b527b092c1a7)</span>yaidsPcapCallbackArgs\_ptr
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a1e3c31fcc01fff2f3ffe3f3f8a0a5788" class="el">yaidsPcapCallbackArgs</a>* <a href="/code/headers/yaidstypes#a825a0af79113da5b1689b527b092c1a7" class="el">yaidsPcapCallbackArgs_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a3e08f70a7402496739a5a38b38a8faea"></span>

<span class="permalink">[◆ ](#a3e08f70a7402496739a5a38b38a8faea)</span>yaidsPcapHandle
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapHandle__struct" class="el">yaidsPcapHandle_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a3e08f70a7402496739a5a38b38a8faea" class="el">yaidsPcapHandle</a></td>
</tr>
</tbody>
</table>

<span id="a8582f875a3bead293c87b8bce98ed503"></span>

<span class="permalink">[◆ ](#a8582f875a3bead293c87b8bce98ed503)</span>yaidsPcapHandle\_ptr
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a3e08f70a7402496739a5a38b38a8faea" class="el">yaidsPcapHandle</a>* <a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a457ce0d8c685ca0941dc578db3ba1ce9"></span>

<span class="permalink">[◆ ](#a457ce0d8c685ca0941dc578db3ba1ce9)</span>yaidsPcapPacket
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapPacket__struct" class="el">yaidsPcapPacket_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a457ce0d8c685ca0941dc578db3ba1ce9" class="el">yaidsPcapPacket</a></td>
</tr>
</tbody>
</table>

<span id="a77be557f4c3954726bc8f85105cf5130"></span>

<span class="permalink">[◆ ](#a77be557f4c3954726bc8f85105cf5130)</span>yaidsPcapPacket\_ptr
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a457ce0d8c685ca0941dc578db3ba1ce9" class="el">yaidsPcapPacket</a>* <a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a></td>
</tr>
</tbody>
</table>

<span id="aea55c17402dd740b2776830781639699"></span>

<span class="permalink">[◆ ](#aea55c17402dd740b2776830781639699)</span>yaidsPcapPacketHeader
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapPacketHeader__struct" class="el">yaidsPcapPacketHeader_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#aea55c17402dd740b2776830781639699" class="el">yaidsPcapPacketHeader</a></td>
</tr>
</tbody>
</table>

<span id="a334a3d558c87c55c4c0d8bd3e0809fa0"></span>

<span class="permalink">[◆ ](#a334a3d558c87c55c4c0d8bd3e0809fa0)</span>yaidsPcapPacketHeader\_ptr
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#aea55c17402dd740b2776830781639699" class="el">yaidsPcapPacketHeader</a>* <a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a64717bb04254e372be57f6845439fea5"></span>

<span class="permalink">[◆ ](#a64717bb04254e372be57f6845439fea5)</span>yaidsPcapPacketHeaderFrame
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapPacketHeaderFrame__struct" class="el">yaidsPcapPacketHeaderFrame_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a64717bb04254e372be57f6845439fea5" class="el">yaidsPcapPacketHeaderFrame</a></td>
</tr>
</tbody>
</table>

<span id="ac0235680350ff37ff9d6b7311c6a2b9e"></span>

<span class="permalink">[◆ ](#ac0235680350ff37ff9d6b7311c6a2b9e)</span>yaidsPcapPacketHeaderFrame\_ptr
------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a64717bb04254e372be57f6845439fea5" class="el">yaidsPcapPacketHeaderFrame</a>* <a href="/code/headers/yaidstypes#ac0235680350ff37ff9d6b7311c6a2b9e" class="el">yaidsPcapPacketHeaderFrame_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a48efc5671f472686cc3f59cfc3f85142"></span>

<span class="permalink">[◆ ](#a48efc5671f472686cc3f59cfc3f85142)</span>yaidsPcapPacketHeaderNet
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapPacketHeaderNet__struct" class="el">yaidsPcapPacketHeaderNet_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a48efc5671f472686cc3f59cfc3f85142" class="el">yaidsPcapPacketHeaderNet</a></td>
</tr>
</tbody>
</table>

<span id="a9b92131e19fbda6ddb020e78e1a87980"></span>

<span class="permalink">[◆ ](#a9b92131e19fbda6ddb020e78e1a87980)</span>yaidsPcapPacketHeaderNet\_ptr
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a48efc5671f472686cc3f59cfc3f85142" class="el">yaidsPcapPacketHeaderNet</a>* <a href="/code/headers/yaidstypes#a9b92131e19fbda6ddb020e78e1a87980" class="el">yaidsPcapPacketHeaderNet_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a5099093658d242bb84350d0bb5419b74"></span>

<span class="permalink">[◆ ](#a5099093658d242bb84350d0bb5419b74)</span>yaidsPcapPacketHeaderTransport
-----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsPcapPacketHeaderTransport__struct" class="el">yaidsPcapPacketHeaderTransport_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a5099093658d242bb84350d0bb5419b74" class="el">yaidsPcapPacketHeaderTransport</a></td>
</tr>
</tbody>
</table>

<span id="ae162149b838e9cd64829af902943104f"></span>

<span class="permalink">[◆ ](#ae162149b838e9cd64829af902943104f)</span>yaidsPcapPacketHeaderTransport\_ptr
----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a5099093658d242bb84350d0bb5419b74" class="el">yaidsPcapPacketHeaderTransport</a>* <a href="/code/headers/yaidstypes#ae162149b838e9cd64829af902943104f" class="el">yaidsPcapPacketHeaderTransport_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a5b58a4556454efcb808e03e8ed82d694"></span>

<span class="permalink">[◆ ](#a5b58a4556454efcb808e03e8ed82d694)</span>yaidsThreadInfo
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsThreadInfo__struct" class="el">yaidsThreadInfo_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a5b58a4556454efcb808e03e8ed82d694" class="el">yaidsThreadInfo</a></td>
</tr>
</tbody>
</table>

<span id="a41f17220799de0556349c9ee5245771f"></span>

<span class="permalink">[◆ ](#a41f17220799de0556349c9ee5245771f)</span>yaidsThreadInfo\_ptr
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a5b58a4556454efcb808e03e8ed82d694" class="el">yaidsThreadInfo</a>* <a href="/code/headers/yaidstypes#a41f17220799de0556349c9ee5245771f" class="el">yaidsThreadInfo_ptr</a></td>
</tr>
</tbody>
</table>

<span id="ae21dce6821977e760cf977353f49ce03"></span>

<span class="permalink">[◆ ](#ae21dce6821977e760cf977353f49ce03)</span>yaidsThreadList
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsThreadList__struct" class="el">yaidsThreadList_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#ae21dce6821977e760cf977353f49ce03" class="el">yaidsThreadList</a></td>
</tr>
</tbody>
</table>

<span id="ae354da9323e110104a59143d2c01234b"></span>

<span class="permalink">[◆ ](#ae354da9323e110104a59143d2c01234b)</span>yaidsThreadList\_ptr
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#ae21dce6821977e760cf977353f49ce03" class="el">yaidsThreadList</a>* <a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a101b6c8fdbd95b1e05b41e3ced0ec917"></span>

<span class="permalink">[◆ ](#a101b6c8fdbd95b1e05b41e3ced0ec917)</span>yaidsThreadReturn
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsThreadReturn__struct" class="el">yaidsThreadReturn_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a></td>
</tr>
</tbody>
</table>

<span id="ad0778ec0b19a3f8946f3eb241104d00c"></span>

<span class="permalink">[◆ ](#ad0778ec0b19a3f8946f3eb241104d00c)</span>yaidsThreadReturn\_ptr
---------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a>* <a href="/code/headers/yaidstypes#ad0778ec0b19a3f8946f3eb241104d00c" class="el">yaidsThreadReturn_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a694f1fbdc4be7263d8d00db00b38b957"></span>

<span class="permalink">[◆ ](#a694f1fbdc4be7263d8d00db00b38b957)</span>yaidsThreadStatuses
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsThreadStatuses__struct" class="el">yaidsThreadStatuses_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a694f1fbdc4be7263d8d00db00b38b957" class="el">yaidsThreadStatuses</a></td>
</tr>
</tbody>
</table>

<span id="a8cb52dabc859ccd49ea273f505b6f0e8"></span>

<span class="permalink">[◆ ](#a8cb52dabc859ccd49ea273f505b6f0e8)</span>yaidsThreadStatuses\_ptr
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a694f1fbdc4be7263d8d00db00b38b957" class="el">yaidsThreadStatuses</a>* <a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a></td>
</tr>
</tbody>
</table>

<span id="aec4f4a6d262531800b69c36adbbb9aee"></span>

<span class="permalink">[◆ ](#aec4f4a6d262531800b69c36adbbb9aee)</span>yaidsTimelimitThreadArgs
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsTimelimitThreadArgs__struct" class="el">yaidsTimelimitThreadArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#aec4f4a6d262531800b69c36adbbb9aee" class="el">yaidsTimelimitThreadArgs</a></td>
</tr>
</tbody>
</table>

<span id="a1a3e1eb23151c7cb06f1f5729093cb40"></span>

<span class="permalink">[◆ ](#a1a3e1eb23151c7cb06f1f5729093cb40)</span>yaidsTimelimitThreadArgs\_ptr
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#aec4f4a6d262531800b69c36adbbb9aee" class="el">yaidsTimelimitThreadArgs</a>* <a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a7660cbddc6e6e0a31070ac16988ece6a"></span>

<span class="permalink">[◆ ](#a7660cbddc6e6e0a31070ac16988ece6a)</span>yaidsYaraCallbackArgs
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsYaraCallbackArgs__struct" class="el">yaidsYaraCallbackArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a7660cbddc6e6e0a31070ac16988ece6a" class="el">yaidsYaraCallbackArgs</a></td>
</tr>
</tbody>
</table>

<span id="aa4acf913104abdae7ed98afff431e337"></span>

<span class="permalink">[◆ ](#aa4acf913104abdae7ed98afff431e337)</span>yaidsYaraCallbackArgs\_ptr
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a7660cbddc6e6e0a31070ac16988ece6a" class="el">yaidsYaraCallbackArgs</a>* <a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a6a1290596928663cd2b8765b3fc124de"></span>

<span class="permalink">[◆ ](#a6a1290596928663cd2b8765b3fc124de)</span>yaidsYaraScanner
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsYaraScanner__struct" class="el">yaidsYaraScanner_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a6a1290596928663cd2b8765b3fc124de" class="el">yaidsYaraScanner</a></td>
</tr>
</tbody>
</table>

<span id="ab9497140a5558e69b16fdf399a77e483"></span>

<span class="permalink">[◆ ](#ab9497140a5558e69b16fdf399a77e483)</span>yaidsYaraScanner\_ptr
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a6a1290596928663cd2b8765b3fc124de" class="el">yaidsYaraScanner</a>* <a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a></td>
</tr>
</tbody>
</table>

<span id="a25dc61de27086a9385c2333c9fb7f11a"></span>

<span class="permalink">[◆ ](#a25dc61de27086a9385c2333c9fb7f11a)</span>yaidsYaraThreadArgs
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef struct <a href="/code/headers/definitions//code/headers/structyaidsYaraThreadArgs__struct" class="el">yaidsYaraThreadArgs_struct</a> <a href="/code/headers/definitions//code/headers/yaidstypes#a25dc61de27086a9385c2333c9fb7f11a" class="el">yaidsYaraThreadArgs</a></td>
</tr>
</tbody>
</table>

<span id="a80abae2dda4b7446a0d572c7e0fb36a8"></span>

<span class="permalink">[◆ ](#a80abae2dda4b7446a0d572c7e0fb36a8)</span>yaidsYaraThreadArgs\_ptr
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>typedef <a href="/code/headers/yaidstypes#a25dc61de27086a9385c2333c9fb7f11a" class="el">yaidsYaraThreadArgs</a>* <a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a></td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
