---
title: yaidsio
permalink: code/source/yaidsio
---
# yaidsio

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

yaidsio.c File Reference

`#include <config.h>`  
`#include <ctype.h>`  
`#include <stdio.h>`  
`#include <stdlib.h>`  
`#include <unistd.h>`  
`#include <stdbool.h>`  
`#include <time.h>`  
`#include <yaids.h>`  
`#include <yaidstypes.h>`  
`#include <yaidsconf.h>`  
`#include <yaidsio.h>`  
`#include <yaidspcap.h>`  
`#include <yaidsyara.h>`  
`#include <yaidsthread.h>`  
`#include <stdarg.h>`  

Include dependency graph for yaidsio.c:

![](/images/yaidsio_8c__incl.png)

<span id="func-members"></span> Functions
-----------------------------------------

void 

<a href="/code/source/yaidsio#a879ccfb90790c473fe04c7e6a1bea613" class="el">yaidsio_print_debug_line</a>
(const char \*format,...)

 

void 

<a href="/code/source/yaidsio#af63c7031bc3a37af2a70738b7059a063" class="el">yaidsio_print_error_line</a>
(const char \*format,...)

 

void 

<a href="/code/source/yaidsio#a23b79aba2df12200763af0be5387786c" class="el">yaidsio_print_std_line</a>
(const char \*format,...)

 

void 

<a href="/code/source/yaidsio#a58e360bcffe20bf0664bc9d1587e8460" class="el">yaidsio_print_std_string</a>
(const char \*format,...)

 

void 

<a href="/code/source/yaidsio#a1bdb0329f4fab634301db2a74ab72e32" class="el">yaidsio_print_horizontal_line</a>
(int chars)

 

void 

<a href="/code/source/yaidsio#a8c6a19bd018efb5db7bda6e07d95eb29" class="el">yaidsio_print_header</a>
(void)

 

void 

<a href="/code/source/yaidsio#a143e12ad61ce7b849c846d508278e79a" class="el">yaidsio_print_arg_line</a>
(char \*opt, char \*type, char \*desc)

 

void 

<a href="/code/source/yaidsio#a39dfc9c8fba3c68055b4433daa8d9d48" class="el">yaidsio_help</a>
(char \*exe)

 

void 

<a href="/code/source/yaidsio#a3431e753355830ae686dafcfca60a954" class="el">yaidsio_version</a>
(void)

 

yaidsConfig 

<a href="/code/source/yaidsio#a7ad0aca400a0708adb753c0cd57e0877" class="el">yaidsio_getopts</a>
(int argc, char \*\*argv)

 

void 

<a href="/code/source/yaidsio#a3cdd534b42c68b3e16ca7b2a728de5cb" class="el">yaidsio_print_config_debug</a>
(yaidsConfig\_ptr config)

 

void 

<a href="/code/source/yaidsio#ad8414f91d2dd549cf72e8769052b7826" class="el">yaidsio_exit_error</a>
(int errorCode)

 

void 

<a href="/code/source/yaidsio#a2062fbeaec8471232ce313b88ce55ec2" class="el">yaidsio_print_started</a>
(void)

 

void 

<a href="/code/source/yaidsio#a9c1cd1bb40858f1d0b2afacaa0f26bc7" class="el">yaidsio_print_exiting</a>
(void)

 

void 

<a href="/code/source/yaidsio#abb7b39f678377c1585d2f4d4117632c8" class="el">yaidsio_print_alert</a>
(char \*alert)

 

void 

<a href="/code/source/yaidsio#aea8fa96ecbb33a55012f073d67febb40" class="el">yaidsio_write_alert</a>
(FILE \*alertFileHandle, char \*alert)

 

void 

<a href="/code/source/yaidsio#ae85c8e4bf73b1d89dfd672960f50d937" class="el">yaidsio_write_pcap</a>
(FILE \*pcapFileHandle, yaidsPcapPacket\_ptr packet)

 

char \* 

<a href="/code/source/yaidsio#af7244fc5e1ac35a8fba101b2cf1b9625" class="el">yaidsio_read_file</a>
(char \*fileName)

 

Function Documentation
----------------------

<span id="ad8414f91d2dd549cf72e8769052b7826"></span>

<span class="permalink">[◆ ](#ad8414f91d2dd549cf72e8769052b7826)</span>yaidsio\_exit\_error()
---------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_exit_error</td>
<td>(</td>
<td>int </td>
<td><em>errorCode</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a7ad0aca400a0708adb753c0cd57e0877"></span>

<span class="permalink">[◆ ](#a7ad0aca400a0708adb753c0cd57e0877)</span>yaidsio\_getopts()
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsConfig yaidsio_getopts</td>
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

<span id="a39dfc9c8fba3c68055b4433daa8d9d48"></span>

<span class="permalink">[◆ ](#a39dfc9c8fba3c68055b4433daa8d9d48)</span>yaidsio\_help()
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_help</td>
<td>(</td>
<td>char * </td>
<td><em>exe</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="abb7b39f678377c1585d2f4d4117632c8"></span>

<span class="permalink">[◆ ](#abb7b39f678377c1585d2f4d4117632c8)</span>yaidsio\_print\_alert()
----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_alert</td>
<td>(</td>
<td>char * </td>
<td><em>alert</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a143e12ad61ce7b849c846d508278e79a"></span>

<span class="permalink">[◆ ](#a143e12ad61ce7b849c846d508278e79a)</span>yaidsio\_print\_arg\_line()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_arg_line</td>
<td>(</td>
<td>char * </td>
<td><em>opt</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>type</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>char * </td>
<td><em>desc</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a3cdd534b42c68b3e16ca7b2a728de5cb"></span>

<span class="permalink">[◆ ](#a3cdd534b42c68b3e16ca7b2a728de5cb)</span>yaidsio\_print\_config\_debug()
------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_config_debug</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a879ccfb90790c473fe04c7e6a1bea613"></span>

<span class="permalink">[◆ ](#a879ccfb90790c473fe04c7e6a1bea613)</span>yaidsio\_print\_debug\_line()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_debug_line</td>
<td>(</td>
<td>const char * </td>
<td><em>format</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td> </td>
<td><em>...</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="af63c7031bc3a37af2a70738b7059a063"></span>

<span class="permalink">[◆ ](#af63c7031bc3a37af2a70738b7059a063)</span>yaidsio\_print\_error\_line()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_error_line</td>
<td>(</td>
<td>const char * </td>
<td><em>format</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td> </td>
<td><em>...</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a9c1cd1bb40858f1d0b2afacaa0f26bc7"></span>

<span class="permalink">[◆ ](#a9c1cd1bb40858f1d0b2afacaa0f26bc7)</span>yaidsio\_print\_exiting()
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_exiting</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a8c6a19bd018efb5db7bda6e07d95eb29"></span>

<span class="permalink">[◆ ](#a8c6a19bd018efb5db7bda6e07d95eb29)</span>yaidsio\_print\_header()
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_header</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a1bdb0329f4fab634301db2a74ab72e32"></span>

<span class="permalink">[◆ ](#a1bdb0329f4fab634301db2a74ab72e32)</span>yaidsio\_print\_horizontal\_line()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_horizontal_line</td>
<td>(</td>
<td>int </td>
<td><em>chars</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a2062fbeaec8471232ce313b88ce55ec2"></span>

<span class="permalink">[◆ ](#a2062fbeaec8471232ce313b88ce55ec2)</span>yaidsio\_print\_started()
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_started</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a23b79aba2df12200763af0be5387786c"></span>

<span class="permalink">[◆ ](#a23b79aba2df12200763af0be5387786c)</span>yaidsio\_print\_std\_line()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_std_line</td>
<td>(</td>
<td>const char * </td>
<td><em>format</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td> </td>
<td><em>...</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a58e360bcffe20bf0664bc9d1587e8460"></span>

<span class="permalink">[◆ ](#a58e360bcffe20bf0664bc9d1587e8460)</span>yaidsio\_print\_std\_string()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_print_std_string</td>
<td>(</td>
<td>const char * </td>
<td><em>format</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td> </td>
<td><em>...</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="af7244fc5e1ac35a8fba101b2cf1b9625"></span>

<span class="permalink">[◆ ](#af7244fc5e1ac35a8fba101b2cf1b9625)</span>yaidsio\_read\_file()
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char* yaidsio_read_file</td>
<td>(</td>
<td>char * </td>
<td><em>fileName</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a3431e753355830ae686dafcfca60a954"></span>

<span class="permalink">[◆ ](#a3431e753355830ae686dafcfca60a954)</span>yaidsio\_version()
-----------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_version</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="aea8fa96ecbb33a55012f073d67febb40"></span>

<span class="permalink">[◆ ](#aea8fa96ecbb33a55012f073d67febb40)</span>yaidsio\_write\_alert()
----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_write_alert</td>
<td>(</td>
<td>FILE * </td>
<td><em>alertFileHandle</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>char * </td>
<td><em>alert</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="ae85c8e4bf73b1d89dfd672960f50d937"></span>

<span class="permalink">[◆ ](#ae85c8e4bf73b1d89dfd672960f50d937)</span>yaidsio\_write\_pcap()
---------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsio_write_pcap</td>
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
