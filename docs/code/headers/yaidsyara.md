---
title: yaidsyara
permalink: code/headers/yaidsyara
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

yaidsyara.h File Reference


<span id="func-members"></span> Functions
-----------------------------------------

int 

<a href="/code/headers/yaidsyara#a668c22ffcacfb36061bea78aa9958d06" class="el">yaidsyara_yara_initialize</a>
(void)

 

int 

<a href="/code/headers/yaidsyara#a929e7a0475aca82cd4d8dbcd05a98397" class="el">yaidsyara_yara_finalize</a>
(void)

 

void 

<a href="/code/headers/yaidsyara#aebeff2b23a6564788e4395b349d6e812" class="el">yaidsyara_init</a>
(<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yara)

 

int 

<a href="/code/headers/yaidsyara#a7d81b162c1e445bf1f4683dbce0c9e59" class="el">yaidsyara_create_scanner</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yara)

 

int 

<a href="/code/headers/yaidsyara#a0fb432093f5328c9b931ac833e8f2777" class="el">yaidsyara_create_scanners</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yaraScanners)

 

void 

<a href="/code/headers/yaidsyara#abb83ed12a041003f42b4fd12e6926379" class="el">yaidsyara_scan_packet</a>
(<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yaraScanner,
<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet,
<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
yaidsOutputQueue,
<a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a>
callbackArgs,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

int 

<a href="/code/headers/yaidsyara#a2b251a76e5dd7edd7d4fad2120dc73ba" class="el">yaidsyara_scanner_callback</a>
(YR\_SCAN\_CONTEXT \*scanContext, int status, void \*rule, void \*args)

 

char \* 

<a href="/code/headers/yaidsyara#a6ce4ac134eef99840d2e34494127e787" class="el">yaidsyara_scanner_callback_get_alert</a>
(<a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a>
callbackArgs, YR\_RULE \*yaraRule, YR\_SCAN\_CONTEXT \*scanContext)

 

void 

<a href="/code/headers/yaidsyara#af4b6d0143640347d06ed0da5f321957c" class="el">yaidsyara_scanner_callback_get_alert_line</a>
(<a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a>
callbackArgs,
<a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a>
parsedPacketHeaders, char \*alertString, int alertStringMax, char
\*timeString, char \*ruleName, char \*metaMatch, char \*stringMatch)

 

char \* 

<a href="/code/headers/yaidsyara#a3f7df8a696f5072f393c2cf348d5c2f4" class="el">yaidsyara_scanner_callback_get_match_meta</a>
(YR\_SCAN\_CONTEXT \*scanContext, YR\_RULE \*yaraRule)

 

char \* 

<a href="/code/headers/yaidsyara#a4067b6cbbac50dab4b645bc41e98ad11" class="el">yaidsyara_scanner_callback_get_match_string</a>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
<td><em>yaraScanner</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
<td><em>packet</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> </td>
<td><em>yaidsOutputQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a> </td>
<td><em>callbackArgs</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a> </td>
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

<span id="af4b6d0143640347d06ed0da5f321957c"></span>

<span class="permalink">[◆ ](#af4b6d0143640347d06ed0da5f321957c)</span>yaidsyara\_scanner\_callback\_get\_alert\_line()
-----------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsyara_scanner_callback_get_alert_line</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#aa4acf913104abdae7ed98afff431e337" class="el">yaidsYaraCallbackArgs_ptr</a> </td>
<td><em>callbackArgs</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a334a3d558c87c55c4c0d8bd3e0809fa0" class="el">yaidsPcapPacketHeader_ptr</a> </td>
<td><em>parsedPacketHeaders</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>alertString</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>int </td>
<td><em>alertStringMax</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>timeString</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>ruleName</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>metaMatch</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>stringMatch</em> </td>
</tr>
<tr class="odd">
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
