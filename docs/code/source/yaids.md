---
title: yaids
permalink: code/source/yaids
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


[Functions](#func-members) | [Variables](#var-members)

yaids.c File Reference

`#include <config.h>`  
`#include <ctype.h>`  
`#include <stdio.h>`  
`#include <stdlib.h>`  
`#include <unistd.h>`  
`#include <stdbool.h>`  
`#include <yaids.h>`  
`#include <yaidstypes.h>`  
`#include <yaidsconf.h>`  
`#include <yaidsio.h>`  
`#include <yaidspcap.h>`  
`#include <yaidsyara.h>`  
`#include <yaidsthread.h>`  
`#include <yara.h>`  
`#include <signal.h>`  

Include dependency graph for yaids.c:

![](/images/yaids_8c__incl.png)

<span id="func-members"></span> Functions
-----------------------------------------

void 

<a href="/code/source/yaids#a29c4beffccb285dcf5c5bc94e21f8eb9" class="el">yaids_signal</a>
(int signalValue)

 

bool 

<a href="/code/source/yaids#a1e4ca5278100de34c5f7fe5c76100b57" class="el">verify_status</a>
(int statusCode)

 

int 

<a href="/code/source/yaids#a3c04138a5bfe5d72780bb7e82a18e627" class="el">main</a>
(int argc, char \*\*argv)

 

<span id="var-members"></span> Variables
----------------------------------------

const char \* 

<a href="/code/source/yaids#a23a6684c128721e25ac4cd8741b3f2fe" class="el">PROGRAM_NAME</a>
= "YAIDS"

 

const char \* 

<a href="/code/source/yaids#ab73101c87fe328a1140edd54fc0977bc" class="el">COPYRIGHT</a>

 

const char \* 

<a href="/code/source/yaids#a020237f37d11115b38beb8a061600e5d" class="el">PROGRAM_SUBLINE</a>

 

const char \* 

<a href="/code/source/yaids#a8cf1423775c5bf5410d540124a889f6d" class="el">PROGRAM_DESCRIPTION</a>

 

const char \* 

<a href="/code/source/yaids#a9052ae5a9feced29ebe17d4e64bd9501" class="el">PROGRAM_VERSION</a>
= PACKAGE\_VERSION

 

bool 

<a href="/code/source/yaids#ac3983a20897f50a952a4375eae247410" class="el">global_yaidsRunning</a>
= true

 

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

**Initial value:**

=

<span class="stringliteral">"COPYRIGHT (C) Justin M. Wray | Licensed:
BSD 3-Clause"</span>

<span id="ac3983a20897f50a952a4375eae247410"></span>

<span class="permalink">[◆ ](#ac3983a20897f50a952a4375eae247410)</span>global\_yaidsRunning
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool global_yaidsRunning = true</td>
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

**Initial value:**

=

<span class="stringliteral">"An Intrusion Detection System (IDS),
utilizing Yara rules, and multi-threading"</span>

<span id="a23a6684c128721e25ac4cd8741b3f2fe"></span>

<span class="permalink">[◆ ](#a23a6684c128721e25ac4cd8741b3f2fe)</span>PROGRAM\_NAME
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_NAME = "YAIDS"</td>
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

**Initial value:**

=

<span class="stringliteral">"Yara as an Intrusion Detection System / Yet
Another Intrusion Detection System"</span>

<span id="a9052ae5a9feced29ebe17d4e64bd9501"></span>

<span class="permalink">[◆ ](#a9052ae5a9feced29ebe17d4e64bd9501)</span>PROGRAM\_VERSION
---------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>const char* PROGRAM_VERSION = PACKAGE_VERSION</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
