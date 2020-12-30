---
title: yaidsyara
permalink: code/source/yaidsyara
---
# yaidsyara

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

yaidsyara.c File Reference

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
`#include <yara/types.h>`  

Include dependency graph for yaidsyara.c:

![](/images/yaidsyara_8c__incl.png)

<span id="func-members"></span> Functions
-----------------------------------------

int 

<a href="/code/source/yaidsyara#a668c22ffcacfb36061bea78aa9958d06" class="el">yaidsyara_yara_initialize</a>
(void)

 

int 

<a href="/code/source/yaidsyara#a929e7a0475aca82cd4d8dbcd05a98397" class="el">yaidsyara_yara_finalize</a>
(void)

 

void 

<a href="/code/source/yaidsyara#aebeff2b23a6564788e4395b349d6e812" class="el">yaidsyara_init</a>
(yaidsYaraScanner\_ptr yara)

 

int 

<a href="/code/source/yaidsyara#a7d81b162c1e445bf1f4683dbce0c9e59" class="el">yaidsyara_create_scanner</a>
(yaidsConfig\_ptr config, yaidsYaraScanner\_ptr yara)

 

int 

<a href="/code/source/yaidsyara#a0fb432093f5328c9b931ac833e8f2777" class="el">yaidsyara_create_scanners</a>
(yaidsConfig\_ptr config, yaidsYaraScanner\_ptr yaraScanners)

 

void 

<a href="/code/source/yaidsyara#abb83ed12a041003f42b4fd12e6926379" class="el">yaidsyara_scan_packet</a>
(yaidsYaraScanner\_ptr yaraScanner, yaidsPcapPacket\_ptr packet,
yaidsOutputDataQueue\_ptr yaidsOutputQueue, yaidsYaraCallbackArgs\_ptr
callbackArgs, yaidsConfig\_ptr config)

 

int 

<a href="/code/source/yaidsyara#a2b251a76e5dd7edd7d4fad2120dc73ba" class="el">yaidsyara_scanner_callback</a>
(YR\_SCAN\_CONTEXT \*scanContext, int status, void \*rule, void \*args)

 

char \* 

<a href="/code/source/yaidsyara#a6ce4ac134eef99840d2e34494127e787" class="el">yaidsyara_scanner_callback_get_alert</a>
(yaidsYaraCallbackArgs\_ptr callbackArgs, YR\_RULE \*yaraRule,
YR\_SCAN\_CONTEXT \*scanContext)

 

void 

<a href="/code/source/yaidsyara#a629966c3ca5d57152c35f3b22c1aa56a" class="el">yaidsyara_scanner_callback_get_alert_line</a>
(yaidsYaraCallbackArgs\_ptr callbackArgs, char \*alertString, int
alertStringMax, char \*timeString, char \*ruleName, char \*metaMatch,
char \*stringMatch)

 

char \* 

<a href="/code/source/yaidsyara#a3f7df8a696f5072f393c2cf348d5c2f4" class="el">yaidsyara_scanner_callback_get_match_meta</a>
(YR\_SCAN\_CONTEXT \*scanContext, YR\_RULE \*yaraRule)

 

char \* 

<a href="/code/source/yaidsyara#a4067b6cbbac50dab4b645bc41e98ad11" class="el">yaidsyara_scanner_callback_get_match_string</a>
(YR\_SCAN\_CONTEXT \*scanContext, YR\_RULE \*yaraRule)

 

Function Documentation
----------------------

<span id="a7d81b162c1e445bf1f4683dbce0c9e59"></span>

<span class="permalink">[◆ ](#a7d81b162c1e445bf1f4683dbce0c9e59)</span>yaidsyara\_create\_scanner()
---------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsyara_create_scanner</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yara</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a0fb432093f5328c9b931ac833e8f2777"></span>

<span class="permalink">[◆ ](#a0fb432093f5328c9b931ac833e8f2777)</span>yaidsyara\_create\_scanners()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsyara_create_scanners</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yaraScanners</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="aebeff2b23a6564788e4395b349d6e812"></span>

<span class="permalink">[◆ ](#aebeff2b23a6564788e4395b349d6e812)</span>yaidsyara\_init()
----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsyara_init</td>
<td>(</td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yara</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="abb83ed12a041003f42b4fd12e6926379"></span>

<span class="permalink">[◆ ](#abb83ed12a041003f42b4fd12e6926379)</span>yaidsyara\_scan\_packet()
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsyara_scan_packet</td>
<td>(</td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yaraScanner</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsOutputDataQueue_ptr </td>
<td><em>yaidsOutputQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsYaraCallbackArgs_ptr </td>
<td><em>callbackArgs</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsConfig_ptr </td>
<td><em>config</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a2b251a76e5dd7edd7d4fad2120dc73ba"></span>

<span class="permalink">[◆ ](#a2b251a76e5dd7edd7d4fad2120dc73ba)</span>yaidsyara\_scanner\_callback()
-----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsyara_scanner_callback</td>
<td>(</td>
<td>YR_SCAN_CONTEXT * </td>
<td><em>scanContext</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>int </td>
<td><em>status</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>void * </td>
<td><em>rule</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>void * </td>
<td><em>args</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a6ce4ac134eef99840d2e34494127e787"></span>

<span class="permalink">[◆ ](#a6ce4ac134eef99840d2e34494127e787)</span>yaidsyara\_scanner\_callback\_get\_alert()
-----------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidsyara_scanner_callback_get_alert</td>
<td>(</td>
<td>yaidsYaraCallbackArgs_ptr </td>
<td><em>callbackArgs</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>YR_RULE * </td>
<td><em>yaraRule</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>YR_SCAN_CONTEXT * </td>
<td><em>scanContext</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a629966c3ca5d57152c35f3b22c1aa56a"></span>

<span class="permalink">[◆ ](#a629966c3ca5d57152c35f3b22c1aa56a)</span>yaidsyara\_scanner\_callback\_get\_alert\_line()
-----------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsyara_scanner_callback_get_alert_line</td>
<td>(</td>
<td>yaidsYaraCallbackArgs_ptr </td>
<td><em>callbackArgs</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>alertString</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>int </td>
<td><em>alertStringMax</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>timeString</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>ruleName</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>metaMatch</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>stringMatch</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a3f7df8a696f5072f393c2cf348d5c2f4"></span>

<span class="permalink">[◆ ](#a3f7df8a696f5072f393c2cf348d5c2f4)</span>yaidsyara\_scanner\_callback\_get\_match\_meta()
-----------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidsyara_scanner_callback_get_match_meta</td>
<td>(</td>
<td>YR_SCAN_CONTEXT * </td>
<td><em>scanContext</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>YR_RULE * </td>
<td><em>yaraRule</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a4067b6cbbac50dab4b645bc41e98ad11"></span>

<span class="permalink">[◆ ](#a4067b6cbbac50dab4b645bc41e98ad11)</span>yaidsyara\_scanner\_callback\_get\_match\_string()
-------------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidsyara_scanner_callback_get_match_string</td>
<td>(</td>
<td>YR_SCAN_CONTEXT * </td>
<td><em>scanContext</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>YR_RULE * </td>
<td><em>yaraRule</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a929e7a0475aca82cd4d8dbcd05a98397"></span>

<span class="permalink">[◆ ](#a929e7a0475aca82cd4d8dbcd05a98397)</span>yaidsyara\_yara\_finalize()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsyara_yara_finalize</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a668c22ffcacfb36061bea78aa9958d06"></span>

<span class="permalink">[◆ ](#a668c22ffcacfb36061bea78aa9958d06)</span>yaidsyara\_yara\_initialize()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsyara_yara_initialize</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
