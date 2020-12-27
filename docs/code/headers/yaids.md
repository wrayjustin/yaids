---
title: yaids
permalink: code/headers/yaids
---
# yaids

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


[Macros](#define-members) | [Functions](#func-members) |
[Variables](#var-members)

yaids.h File Reference

`#include <stdbool.h>`  

Include dependency graph for yaids.h:

![](/images/yaids_8h__incl.png)


<span id="define-members"></span> Macros
----------------------------------------

\#define 

<a href="/code/headers/yaids#a94d83a44bef8b177de0f7bcdecb468f9" class="el">YAIDS_SUCCESS</a>   0

 

\#define 

<a href="/code/headers/yaids#a48a32948c1e2708d275c5834efc1ff4a" class="el">YAIDS_ERROR</a>   1

 

\#define 

<a href="/code/headers/yaids#ac4a4c62c75ddb8c047f3a27fec334d29" class="el">YAIDS_PENDING_CONFIG</a>   2

 

\#define 

<a href="/code/headers/yaids#a0ec55f51a12d4eb369dae6979e60ade0" class="el">YAIDS_MISSING_ARGUMENTS</a>   2

 

\#define 

<a href="/code/headers/yaids#a9f56e030f36c37753125bd5557eb4835" class="el">YAIDS_INVALID_ARGUMENTS</a>   3

 

\#define 

<a href="/code/headers/yaids#ab9eb16a7b7386bf5b3abdbd2e7e7f481" class="el">YAIDS_INVALID_MODE</a>   4

 

\#define 

<a href="/code/headers/yaids#a3830ccdf3c322441fff8ca831971af0d" class="el">YAIDS_NO_ACTION</a>   10

 

\#define 

<a href="/code/headers/yaids#a6371bdb9484059f2a641c29fc5fb875f" class="el">YAIDS_PERMISSION_DENIED</a>   20

 

\#define 

<a href="/code/headers/yaids#a25f6bbb476d745e8ca6a2cb7400c195e" class="el">YAIDS_FILE_DOES_NOT_EXIST</a>   21

 

\#define 

<a href="/code/headers/yaids#a97e03c5b4b681e332abb79bf23c67eb3" class="el">YAIDS_THREAD_ERROR</a>   30

 

\#define 

<a href="/code/headers/yaids#ae26ed2a91cc83df218598eee9f11bbd0" class="el">YAIDS_PCAP_ERROR</a>   40

 

\#define 

<a href="/code/headers/yaids#a5c2a692081af8bd199ddbbcd900140c5" class="el">YAIDS_PCAP_DEVICE_DOES_NOT_EXIST</a>   41

 

\#define 

<a href="/code/headers/yaids#aec25c1cbac59b0234f2af162e1453899" class="el">YAIDS_YARA_ERROR</a>   50

 

\#define 

<a href="/code/headers/yaids#af9fa6e80ad59c0cfab75fb69c53287f1" class="el">YAIDS_YARA_MATCH</a>   100

 

\#define 

<a href="/code/headers/yaids#a284efa63eb513c98b2843e32f8ec8324" class="el">YAIDS_YARA_NOMATCH</a>   101

 

\#define 

<a href="/code/headers/yaids#a8a2a23e666dac0c6a020ed9aa32f8e91" class="el">YAIDS_COMPLETE</a>   999

 

\#define 

<a href="/code/headers/yaids#ad5eba37c9b6bc42d2bfb0b6b8fe18268" class="el">sec_str_cpy</a>   strncpy

 

<span id="func-members"></span> Functions
-----------------------------------------

void 

<a href="/code/headers/yaids#a29c4beffccb285dcf5c5bc94e21f8eb9" class="el">yaids_signal</a>
(int signalValue)

 

bool 

<a href="/code/headers/yaids#a1e4ca5278100de34c5f7fe5c76100b57" class="el">verify_status</a>
(int statusCode)

 

int 

<a href="/code/headers/yaids#a3c04138a5bfe5d72780bb7e82a18e627" class="el">main</a>
(int argc, char \*\*argv)

 

<span id="var-members"></span> Variables
----------------------------------------

const char \* 

<a href="/code/headers/yaids#a23a6684c128721e25ac4cd8741b3f2fe" class="el">PROGRAM_NAME</a>

 

const char \* 

<a href="/code/headers/yaids#ab73101c87fe328a1140edd54fc0977bc" class="el">COPYRIGHT</a>

 

const char \* 

<a href="/code/headers/yaids#a020237f37d11115b38beb8a061600e5d" class="el">PROGRAM_SUBLINE</a>

 

const char \* 

<a href="/code/headers/yaids#a8cf1423775c5bf5410d540124a889f6d" class="el">PROGRAM_DESCRIPTION</a>

 

const char \* 

<a href="/code/headers/yaids#a9052ae5a9feced29ebe17d4e64bd9501" class="el">PROGRAM_VERSION</a>

 

bool 

<a href="/code/headers/yaids#ac3983a20897f50a952a4375eae247410" class="el">global_yaidsRunning</a>

 

Macro Definition Documentation
------------------------------

<span id="ad5eba37c9b6bc42d2bfb0b6b8fe18268"></span>

<span class="permalink">[◆ ](#ad5eba37c9b6bc42d2bfb0b6b8fe18268)</span>sec\_str\_cpy
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define sec_str_cpy   strncpy</td>
</tr>
</tbody>
</table>

<span id="a8a2a23e666dac0c6a020ed9aa32f8e91"></span>

<span class="permalink">[◆ ](#a8a2a23e666dac0c6a020ed9aa32f8e91)</span>YAIDS\_COMPLETE
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_COMPLETE   999</td>
</tr>
</tbody>
</table>

<span id="a48a32948c1e2708d275c5834efc1ff4a"></span>

<span class="permalink">[◆ ](#a48a32948c1e2708d275c5834efc1ff4a)</span>YAIDS\_ERROR
-----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_ERROR   1</td>
</tr>
</tbody>
</table>

<span id="a25f6bbb476d745e8ca6a2cb7400c195e"></span>

<span class="permalink">[◆ ](#a25f6bbb476d745e8ca6a2cb7400c195e)</span>YAIDS\_FILE\_DOES\_NOT\_EXIST
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_FILE_DOES_NOT_EXIST   21</td>
</tr>
</tbody>
</table>

<span id="a9f56e030f36c37753125bd5557eb4835"></span>

<span class="permalink">[◆ ](#a9f56e030f36c37753125bd5557eb4835)</span>YAIDS\_INVALID\_ARGUMENTS
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_INVALID_ARGUMENTS   3</td>
</tr>
</tbody>
</table>

<span id="ab9eb16a7b7386bf5b3abdbd2e7e7f481"></span>

<span class="permalink">[◆ ](#ab9eb16a7b7386bf5b3abdbd2e7e7f481)</span>YAIDS\_INVALID\_MODE
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_INVALID_MODE   4</td>
</tr>
</tbody>
</table>

<span id="a0ec55f51a12d4eb369dae6979e60ade0"></span>

<span class="permalink">[◆ ](#a0ec55f51a12d4eb369dae6979e60ade0)</span>YAIDS\_MISSING\_ARGUMENTS
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_MISSING_ARGUMENTS   2</td>
</tr>
</tbody>
</table>

<span id="a3830ccdf3c322441fff8ca831971af0d"></span>

<span class="permalink">[◆ ](#a3830ccdf3c322441fff8ca831971af0d)</span>YAIDS\_NO\_ACTION
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_NO_ACTION   10</td>
</tr>
</tbody>
</table>

<span id="a5c2a692081af8bd199ddbbcd900140c5"></span>

<span class="permalink">[◆ ](#a5c2a692081af8bd199ddbbcd900140c5)</span>YAIDS\_PCAP\_DEVICE\_DOES\_NOT\_EXIST
------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_PCAP_DEVICE_DOES_NOT_EXIST   41</td>
</tr>
</tbody>
</table>

<span id="ae26ed2a91cc83df218598eee9f11bbd0"></span>

<span class="permalink">[◆ ](#ae26ed2a91cc83df218598eee9f11bbd0)</span>YAIDS\_PCAP\_ERROR
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_PCAP_ERROR   40</td>
</tr>
</tbody>
</table>

<span id="ac4a4c62c75ddb8c047f3a27fec334d29"></span>

<span class="permalink">[◆ ](#ac4a4c62c75ddb8c047f3a27fec334d29)</span>YAIDS\_PENDING\_CONFIG
---------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_PENDING_CONFIG   2</td>
</tr>
</tbody>
</table>

<span id="a6371bdb9484059f2a641c29fc5fb875f"></span>

<span class="permalink">[◆ ](#a6371bdb9484059f2a641c29fc5fb875f)</span>YAIDS\_PERMISSION\_DENIED
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_PERMISSION_DENIED   20</td>
</tr>
</tbody>
</table>

<span id="a94d83a44bef8b177de0f7bcdecb468f9"></span>

<span class="permalink">[◆ ](#a94d83a44bef8b177de0f7bcdecb468f9)</span>YAIDS\_SUCCESS
-------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_SUCCESS   0</td>
</tr>
</tbody>
</table>

<span id="a97e03c5b4b681e332abb79bf23c67eb3"></span>

<span class="permalink">[◆ ](#a97e03c5b4b681e332abb79bf23c67eb3)</span>YAIDS\_THREAD\_ERROR
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_THREAD_ERROR   30</td>
</tr>
</tbody>
</table>

<span id="aec25c1cbac59b0234f2af162e1453899"></span>

<span class="permalink">[◆ ](#aec25c1cbac59b0234f2af162e1453899)</span>YAIDS\_YARA\_ERROR
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_YARA_ERROR   50</td>
</tr>
</tbody>
</table>

<span id="af9fa6e80ad59c0cfab75fb69c53287f1"></span>

<span class="permalink">[◆ ](#af9fa6e80ad59c0cfab75fb69c53287f1)</span>YAIDS\_YARA\_MATCH
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_YARA_MATCH   100</td>
</tr>
</tbody>
</table>

<span id="a284efa63eb513c98b2843e32f8ec8324"></span>

<span class="permalink">[◆ ](#a284efa63eb513c98b2843e32f8ec8324)</span>YAIDS\_YARA\_NOMATCH
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_YARA_NOMATCH   101</td>
</tr>
</tbody>
</table>

Function Documentation
----------------------

<span id="a3c04138a5bfe5d72780bb7e82a18e627"></span>

<span class="permalink">[◆ ](#a3c04138a5bfe5d72780bb7e82a18e627)</span>main()
-----------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int main</td>
<td>(</td>
<td>int </td>
<td><em>argc</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char ** </td>
<td><em>argv</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a1e4ca5278100de34c5f7fe5c76100b57"></span>

<span class="permalink">[◆ ](#a1e4ca5278100de34c5f7fe5c76100b57)</span>verify\_status()
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool verify_status</td>
<td>(</td>
<td>int </td>
<td><em>statusCode</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a29c4beffccb285dcf5c5bc94e21f8eb9"></span>

<span class="permalink">[◆ ](#a29c4beffccb285dcf5c5bc94e21f8eb9)</span>yaids\_signal()
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaids_signal</td>
<td>(</td>
<td>int </td>
<td><em>signalValue</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

Variable Documentation
----------------------

<span id="ab73101c87fe328a1140edd54fc0977bc"></span>

<span class="permalink">[◆ ](#ab73101c87fe328a1140edd54fc0977bc)</span>COPYRIGHT
--------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* COPYRIGHT</td>
</tr>
</tbody>
</table>

<span id="ac3983a20897f50a952a4375eae247410"></span>

<span class="permalink">[◆ ](#ac3983a20897f50a952a4375eae247410)</span>global\_yaidsRunning
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool global_yaidsRunning</td>
</tr>
</tbody>
</table>

<span id="a8cf1423775c5bf5410d540124a889f6d"></span>

<span class="permalink">[◆ ](#a8cf1423775c5bf5410d540124a889f6d)</span>PROGRAM\_DESCRIPTION
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_DESCRIPTION</td>
</tr>
</tbody>
</table>

<span id="a23a6684c128721e25ac4cd8741b3f2fe"></span>

<span class="permalink">[◆ ](#a23a6684c128721e25ac4cd8741b3f2fe)</span>PROGRAM\_NAME
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_NAME</td>
</tr>
</tbody>
</table>

<span id="a020237f37d11115b38beb8a061600e5d"></span>

<span class="permalink">[◆ ](#a020237f37d11115b38beb8a061600e5d)</span>PROGRAM\_SUBLINE
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_SUBLINE</td>
</tr>
</tbody>
</table>

<span id="a9052ae5a9feced29ebe17d4e64bd9501"></span>

<span class="permalink">[◆ ](#a9052ae5a9feced29ebe17d4e64bd9501)</span>PROGRAM\_VERSION
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_VERSION</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
