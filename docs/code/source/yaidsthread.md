---
title: yaidsthread
permalink: code/source/yaidsthread
---
# yaidsthread

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

yaidsthread.c File Reference

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
`#include <pthread.h>`  
`#include <pcap.h>`  
`#include <signal.h>`  
`#include <sys/prctl.h>`  
`#include <sys/types.h>`  
`#include <sys/stat.h>`  
`#include <fcntl.h>`  

Include dependency graph for yaidsthread.c:

![](/images/yaidsthread_8c__incl.png)

<span id="func-members"></span> Functions
-----------------------------------------

yaidsPacketCounts\_ptr 

<a href="/code/source/yaidsthread#a6a933ee1ae422d055ce24e97343d6a4e" class="el">yaidsthread_new_packet_counts</a>
(void)

 

yaidsThreadStatuses\_ptr 

<a href="/code/source/yaidsthread#a988d25f0e0e90b04e5c5ca8a253e00c7" class="el">yaidsthread_new_thread_statuses</a>
(void)

 

yaidsInputDataQueue\_ptr 

<a href="/code/source/yaidsthread#a475063005017f81d2689ea411e728852" class="el">yaidsthread_new_input_queue</a>
(void)

 

yaidsInputDataNode\_ptr 

<a href="/code/source/yaidsthread#aec57d9b8d9d89d910c580acc1a00a6f8" class="el">yaidsthread_new_input_data</a>
(yaidsPcapPacket\_ptr packet)

 

yaidsInputThreadArgs\_ptr 

<a href="/code/source/yaidsthread#a1325d9214f8b6f7e3cb9a46c24aa7034" class="el">yaidsthread_new_input_thread_args</a>
(yaidsInputDataQueue\_ptr dataQueue, yaidsPcapHandle\_ptr pcapHandle,
yaidsConfig\_ptr config, yaidsPacketCounts\_ptr packetCounts,
yaidsThreadStatuses\_ptr threadStatuses)

 

yaidsTimelimitThreadArgs\_ptr 

<a href="/code/source/yaidsthread#a1efcabff9f50cb25235b7633195c5db8" class="el">yaidsthread_new_timelimit_thread_args</a>
(bool \*yaidsRunning, yaidsConfig\_ptr config)

 

yaidsOutputDataQueue\_ptr 

<a href="/code/source/yaidsthread#a6f5d602f913a4c1aad64cd7a658281bd" class="el">yaidsthread_new_output_queue</a>
(void)

 

yaidsOutputDataNode\_ptr 

<a href="/code/source/yaidsthread#aac229c33966244673412c5cc26256a11" class="el">yaidsthread_new_output_data</a>
(yaidsPcapPacket\_ptr packet, char \*alert)

 

yaidsOutputThreadArgs\_ptr 

<a href="/code/source/yaidsthread#a6a1c4398bade4b4a7e1f41b514432872" class="el">yaidsthread_new_output_thread_args</a>
(yaidsOutputDataQueue\_ptr dataQueue, yaidsPcapHandle\_ptr pcapHandle,
yaidsConfig\_ptr config, yaidsPacketCounts\_ptr packetCounts,
yaidsThreadStatuses\_ptr threadStatuses)

 

yaidsYaraThreadArgs\_ptr 

<a href="/code/source/yaidsthread#ab233f6b72db40463f89a05e088433fdb" class="el">yaidsthread_new_yara_thread_args</a>
(yaidsInputDataQueue\_ptr inputDataQueue, yaidsOutputDataQueue\_ptr
outputDataQueue, yaidsYaraScanner\_ptr yaraScanner, yaidsConfig\_ptr
config, yaidsPacketCounts\_ptr packetCounts, yaidsThreadStatuses\_ptr
threadStatuses)

 

void 

<a href="/code/source/yaidsthread#aaf4517c8531ad7f9047220be9e766ae9" class="el">yaidsthread_update_pcap_packet_count</a>
(yaidsPacketCounts\_ptr packetCounts)

 

void 

<a href="/code/source/yaidsthread#a982775bb31404e4c377c83d9e05f476e" class="el">yaidsthread_update_yara_packet_count</a>
(yaidsPacketCounts\_ptr packetCounts)

 

void 

<a href="/code/source/yaidsthread#a54b1026e8384b016b67df82dcf0f1755" class="el">yaidsthread_update_alert_packet_count</a>
(yaidsPacketCounts\_ptr packetCounts)

 

void 

<a href="/code/source/yaidsthread#a6546a88ba8192b7da283b1adbb644d67" class="el">yaidsthread_update_output_packet_count</a>
(yaidsPacketCounts\_ptr packetCounts)

 

void 

<a href="/code/source/yaidsthread#a6f2a001be78db3dc06929356a50fd3f8" class="el">yaidsthread_set_pcap_finished</a>
(yaidsThreadStatuses\_ptr threadStatuses, yaidsConfig\_ptr config)

 

void 

<a href="/code/source/yaidsthread#ab132d969ced522101add67bf7b970903" class="el">yaidsthread_set_yara_finished</a>
(yaidsThreadStatuses\_ptr threadStatuses, yaidsConfig\_ptr config)

 

void 

<a href="/code/source/yaidsthread#acb8a3ee01dadcec309268f73e8df1def" class="el">yaidsthread_set_output_finished</a>
(yaidsThreadStatuses\_ptr threadStatuses, yaidsConfig\_ptr config)

 

void 

<a href="/code/source/yaidsthread#a9dd9b96734c3d9f72c58b3d8ebf69070" class="el">yaidsthread_add_input_data</a>
(yaidsInputDataQueue\_ptr dataQueue, yaidsPcapPacket\_ptr packet)

 

yaidsInputDataNode 

<a href="/code/source/yaidsthread#aef69ad3066889a2a88760f93be494a1b" class="el">yaidsthread_get_input_data</a>
(yaidsInputDataQueue\_ptr dataQueue)

 

void 

<a href="/code/source/yaidsthread#aebee0adbdc704f68fbdddb9e22028298" class="el">yaidsthread_add_output_data</a>
(yaidsOutputDataQueue\_ptr dataQueue, yaidsPcapPacket\_ptr packet, char
\*alert)

 

yaidsOutputDataNode 

<a href="/code/source/yaidsthread#ae2b2e424ad69425f5901b63a5dc4ee8a" class="el">yaidsthread_get_output_data</a>
(yaidsOutputDataQueue\_ptr dataQueue)

 

yaidsThreadReturn 

<a href="/code/source/yaidsthread#aae0f14acca0e4c3a07ee23af9dace2c3" class="el">yaidsthread_create_pcap_thread</a>
(yaidsInputThreadArgs\_ptr threadArgs)

 

yaidsThreadReturn 

<a href="/code/source/yaidsthread#a7411c65656b15681dff491360d36deab" class="el">yaidsthread_create_yara_thread</a>
(yaidsYaraThreadArgs\_ptr threadArgs)

 

yaidsThreadReturn 

<a href="/code/source/yaidsthread#a82c079c907e1c216d634bd05569df759" class="el">yaidsthread_create_output_thread</a>
(yaidsOutputThreadArgs\_ptr threadArgs)

 

yaidsThreadReturn 

<a href="/code/source/yaidsthread#a280e7b978e356e3e206c4e4ec5d62a69" class="el">yaidsthread_create_timelimit_thread</a>
(yaidsTimelimitThreadArgs\_ptr threadArgs)

 

void \* 

<a href="/code/source/yaidsthread#a84e71ea87509d932aed4ebb8a0be8876" class="el">yaidsthread_pcap_thread</a>
(void \*args)

 

void \* 

<a href="/code/source/yaidsthread#ae829130bbd02b253c32286fe1a215d8f" class="el">yaidsthread_yara_thread</a>
(void \*args)

 

void \* 

<a href="/code/source/yaidsthread#a317c18d64dbb6cb5235202452edf98fb" class="el">yaidsthread_output_thread</a>
(void \*args)

 

void \* 

<a href="/code/source/yaidsthread#a6e0481a7d3d56e4fc647b4c2e4649f14" class="el">yaidsthread_timelimit_thread</a>
(void \*args)

 

yaidsThreadList\_ptr 

<a href="/code/source/yaidsthread#ac38b8ef3fc98bbf1f4f1031a02615ac0" class="el">yaidsthread_new_threadlist</a>
(yaidsConfig\_ptr config)

 

yaidsThreadInfo\_ptr 

<a href="/code/source/yaidsthread#a3b6a788e515bf8733db99521c5f81b98" class="el">yaidsthread_new_threadinfo</a>
(void)

 

int 

<a href="/code/source/yaidsthread#af095cc8df152960f2916e679ed87ce57" class="el">yaidsthread_start_input_threads</a>
(yaidsConfig\_ptr config, yaidsThreadList\_ptr threadList,
yaidsThreadStatuses\_ptr threadStatuses, yaidsPcapHandle\_ptr
pcapHandle, yaidsInputDataQueue\_ptr yaidsInputQueue,
yaidsPacketCounts\_ptr packetCounts)

 

int 

<a href="/code/source/yaidsthread#a7175dab16d3c6ba7116dea31deb4db5b" class="el">yaidsthread_start_yara_threads</a>
(yaidsConfig\_ptr config, yaidsThreadList\_ptr threadList,
yaidsThreadStatuses\_ptr threadStatuses, yaidsInputDataQueue\_ptr
yaidsInputQueue, yaidsOutputDataQueue\_ptr yaidsOutputQueue,
yaidsYaraScanner\_ptr yaraScanners, yaidsPacketCounts\_ptr packetCounts)

 

int 

<a href="/code/source/yaidsthread#ad3ff05632e8d28bbabd366eda68c7d9b" class="el">yaidsthread_start_output_threads</a>
(yaidsConfig\_ptr config, yaidsThreadList\_ptr threadList,
yaidsThreadStatuses\_ptr threadStatuses, yaidsPcapHandle\_ptr
pcapHandle, yaidsOutputDataQueue\_ptr yaidsOutputQueue,
yaidsPacketCounts\_ptr packetCounts, int scannerThreadCount)

 

int 

<a href="/code/source/yaidsthread#a06eb89b53753082fcd95cb1fc58d710c" class="el">yaidsthread_start_timelimit_threads</a>
(yaidsConfig\_ptr config, yaidsThreadList\_ptr threadList, bool
\*yaidsRunning, int scannerThreadCount)

 

int 

<a href="/code/source/yaidsthread#ab93f99f828b9cf7cfb83adff1466f82a" class="el">yaidsthread_run_threads</a>
(bool \*yaidsRunning, yaidsConfig config, yaidsThreadList\_ptr
threadList, yaidsInputDataQueue\_ptr yaidsInputQueue,
yaidsOutputDataQueue\_ptr yaidsOutputQueue, yaidsPcapHandle\_ptr
pcapHandle, yaidsYaraScanner\_ptr yaraScanners)

 

Function Documentation
----------------------

<span id="a9dd9b96734c3d9f72c58b3d8ebf69070"></span>

<span class="permalink">[◆ ](#a9dd9b96734c3d9f72c58b3d8ebf69070)</span>yaidsthread\_add\_input\_data()
------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_add_input_data</td>
<td>(</td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>dataQueue</em>,</td>
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

<span id="aebee0adbdc704f68fbdddb9e22028298"></span>

<span class="permalink">[◆ ](#aebee0adbdc704f68fbdddb9e22028298)</span>yaidsthread\_add\_output\_data()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_add_output_data</td>
<td>(</td>
<td>yaidsOutputDataQueue_ptr </td>
<td><em>dataQueue</em>,</td>
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
<td>char * </td>
<td><em>alert</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a82c079c907e1c216d634bd05569df759"></span>

<span class="permalink">[◆ ](#a82c079c907e1c216d634bd05569df759)</span>yaidsthread\_create\_output\_thread()
------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadReturn yaidsthread_create_output_thread</td>
<td>(</td>
<td>yaidsOutputThreadArgs_ptr </td>
<td><em>threadArgs</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="aae0f14acca0e4c3a07ee23af9dace2c3"></span>

<span class="permalink">[◆ ](#aae0f14acca0e4c3a07ee23af9dace2c3)</span>yaidsthread\_create\_pcap\_thread()
----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadReturn yaidsthread_create_pcap_thread</td>
<td>(</td>
<td>yaidsInputThreadArgs_ptr </td>
<td><em>threadArgs</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a280e7b978e356e3e206c4e4ec5d62a69"></span>

<span class="permalink">[◆ ](#a280e7b978e356e3e206c4e4ec5d62a69)</span>yaidsthread\_create\_timelimit\_thread()
---------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadReturn yaidsthread_create_timelimit_thread</td>
<td>(</td>
<td>yaidsTimelimitThreadArgs_ptr </td>
<td><em>threadArgs</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a7411c65656b15681dff491360d36deab"></span>

<span class="permalink">[◆ ](#a7411c65656b15681dff491360d36deab)</span>yaidsthread\_create\_yara\_thread()
----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadReturn yaidsthread_create_yara_thread</td>
<td>(</td>
<td>yaidsYaraThreadArgs_ptr </td>
<td><em>threadArgs</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="aef69ad3066889a2a88760f93be494a1b"></span>

<span class="permalink">[◆ ](#aef69ad3066889a2a88760f93be494a1b)</span>yaidsthread\_get\_input\_data()
------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsInputDataNode yaidsthread_get_input_data</td>
<td>(</td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>dataQueue</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ae2b2e424ad69425f5901b63a5dc4ee8a"></span>

<span class="permalink">[◆ ](#ae2b2e424ad69425f5901b63a5dc4ee8a)</span>yaidsthread\_get\_output\_data()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsOutputDataNode yaidsthread_get_output_data</td>
<td>(</td>
<td>yaidsOutputDataQueue_ptr </td>
<td><em>dataQueue</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="aec57d9b8d9d89d910c580acc1a00a6f8"></span>

<span class="permalink">[◆ ](#aec57d9b8d9d89d910c580acc1a00a6f8)</span>yaidsthread\_new\_input\_data()
------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsInputDataNode_ptr yaidsthread_new_input_data</td>
<td>(</td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a475063005017f81d2689ea411e728852"></span>

<span class="permalink">[◆ ](#a475063005017f81d2689ea411e728852)</span>yaidsthread\_new\_input\_queue()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsInputDataQueue_ptr yaidsthread_new_input_queue</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a1325d9214f8b6f7e3cb9a46c24aa7034"></span>

<span class="permalink">[◆ ](#a1325d9214f8b6f7e3cb9a46c24aa7034)</span>yaidsthread\_new\_input\_thread\_args()
--------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsInputThreadArgs_ptr yaidsthread_new_input_thread_args</td>
<td>(</td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>dataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="aac229c33966244673412c5cc26256a11"></span>

<span class="permalink">[◆ ](#aac229c33966244673412c5cc26256a11)</span>yaidsthread\_new\_output\_data()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsOutputDataNode_ptr yaidsthread_new_output_data</td>
<td>(</td>
<td>yaidsPcapPacket_ptr </td>
<td><em>packet</em>,</td>
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

<span id="a6f5d602f913a4c1aad64cd7a658281bd"></span>

<span class="permalink">[◆ ](#a6f5d602f913a4c1aad64cd7a658281bd)</span>yaidsthread\_new\_output\_queue()
--------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsOutputDataQueue_ptr yaidsthread_new_output_queue</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a6a1c4398bade4b4a7e1f41b514432872"></span>

<span class="permalink">[◆ ](#a6a1c4398bade4b4a7e1f41b514432872)</span>yaidsthread\_new\_output\_thread\_args()
---------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsOutputThreadArgs_ptr yaidsthread_new_output_thread_args</td>
<td>(</td>
<td>yaidsOutputDataQueue_ptr </td>
<td><em>dataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a6a933ee1ae422d055ce24e97343d6a4e"></span>

<span class="permalink">[◆ ](#a6a933ee1ae422d055ce24e97343d6a4e)</span>yaidsthread\_new\_packet\_counts()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsPacketCounts_ptr yaidsthread_new_packet_counts</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a988d25f0e0e90b04e5c5ca8a253e00c7"></span>

<span class="permalink">[◆ ](#a988d25f0e0e90b04e5c5ca8a253e00c7)</span>yaidsthread\_new\_thread\_statuses()
-----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadStatuses_ptr yaidsthread_new_thread_statuses</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a3b6a788e515bf8733db99521c5f81b98"></span>

<span class="permalink">[◆ ](#a3b6a788e515bf8733db99521c5f81b98)</span>yaidsthread\_new\_threadinfo()
-----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadInfo_ptr yaidsthread_new_threadinfo</td>
<td>(</td>
<td>void </td>
<td></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ac38b8ef3fc98bbf1f4f1031a02615ac0"></span>

<span class="permalink">[◆ ](#ac38b8ef3fc98bbf1f4f1031a02615ac0)</span>yaidsthread\_new\_threadlist()
-----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsThreadList_ptr yaidsthread_new_threadlist</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a1efcabff9f50cb25235b7633195c5db8"></span>

<span class="permalink">[◆ ](#a1efcabff9f50cb25235b7633195c5db8)</span>yaidsthread\_new\_timelimit\_thread\_args()
------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsTimelimitThreadArgs_ptr yaidsthread_new_timelimit_thread_args</td>
<td>(</td>
<td>bool * </td>
<td><em>yaidsRunning</em>,</td>
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

<span id="ab233f6b72db40463f89a05e088433fdb"></span>

<span class="permalink">[◆ ](#ab233f6b72db40463f89a05e088433fdb)</span>yaidsthread\_new\_yara\_thread\_args()
-------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>yaidsYaraThreadArgs_ptr yaidsthread_new_yara_thread_args</td>
<td>(</td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>inputDataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsOutputDataQueue_ptr </td>
<td><em>outputDataQueue</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yaraScanner</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a317c18d64dbb6cb5235202452edf98fb"></span>

<span class="permalink">[◆ ](#a317c18d64dbb6cb5235202452edf98fb)</span>yaidsthread\_output\_thread()
----------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void* yaidsthread_output_thread</td>
<td>(</td>
<td>void * </td>
<td><em>args</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a84e71ea87509d932aed4ebb8a0be8876"></span>

<span class="permalink">[◆ ](#a84e71ea87509d932aed4ebb8a0be8876)</span>yaidsthread\_pcap\_thread()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void* yaidsthread_pcap_thread</td>
<td>(</td>
<td>void * </td>
<td><em>args</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ab93f99f828b9cf7cfb83adff1466f82a"></span>

<span class="permalink">[◆ ](#ab93f99f828b9cf7cfb83adff1466f82a)</span>yaidsthread\_run\_threads()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_run_threads</td>
<td>(</td>
<td>bool * </td>
<td><em>yaidsRunning</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsConfig </td>
<td><em>config</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadList_ptr </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>yaidsInputQueue</em>,</td>
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
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsYaraScanner_ptr </td>
<td><em>yaraScanners</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="acb8a3ee01dadcec309268f73e8df1def"></span>

<span class="permalink">[◆ ](#acb8a3ee01dadcec309268f73e8df1def)</span>yaidsthread\_set\_output\_finished()
-----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_set_output_finished</td>
<td>(</td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
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

<span id="a6f2a001be78db3dc06929356a50fd3f8"></span>

<span class="permalink">[◆ ](#a6f2a001be78db3dc06929356a50fd3f8)</span>yaidsthread\_set\_pcap\_finished()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_set_pcap_finished</td>
<td>(</td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
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

<span id="ab132d969ced522101add67bf7b970903"></span>

<span class="permalink">[◆ ](#ab132d969ced522101add67bf7b970903)</span>yaidsthread\_set\_yara\_finished()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_set_yara_finished</td>
<td>(</td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
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

<span id="af095cc8df152960f2916e679ed87ce57"></span>

<span class="permalink">[◆ ](#af095cc8df152960f2916e679ed87ce57)</span>yaidsthread\_start\_input\_threads()
-----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_start_input_threads</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsThreadList_ptr </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>yaidsInputQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="ad3ff05632e8d28bbabd366eda68c7d9b"></span>

<span class="permalink">[◆ ](#ad3ff05632e8d28bbabd366eda68c7d9b)</span>yaidsthread\_start\_output\_threads()
------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_start_output_threads</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsThreadList_ptr </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsPcapHandle_ptr </td>
<td><em>pcapHandle</em>,</td>
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
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>int </td>
<td><em>scannerThreadCount</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a06eb89b53753082fcd95cb1fc58d710c"></span>

<span class="permalink">[◆ ](#a06eb89b53753082fcd95cb1fc58d710c)</span>yaidsthread\_start\_timelimit\_threads()
---------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_start_timelimit_threads</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsThreadList_ptr </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>bool * </td>
<td><em>yaidsRunning</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>int </td>
<td><em>scannerThreadCount</em> </td>
</tr>
<tr class="odd">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a7175dab16d3c6ba7116dea31deb4db5b"></span>

<span class="permalink">[◆ ](#a7175dab16d3c6ba7116dea31deb4db5b)</span>yaidsthread\_start\_yara\_threads()
----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_start_yara_threads</td>
<td>(</td>
<td>yaidsConfig_ptr </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsThreadList_ptr </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsThreadStatuses_ptr </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td>yaidsInputDataQueue_ptr </td>
<td><em>yaidsInputQueue</em>,</td>
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
<td>yaidsYaraScanner_ptr </td>
<td><em>yaraScanners</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em> </td>
</tr>
<tr class="even">
<td></td>
<td>)</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

<span id="a6e0481a7d3d56e4fc647b4c2e4649f14"></span>

<span class="permalink">[◆ ](#a6e0481a7d3d56e4fc647b4c2e4649f14)</span>yaidsthread\_timelimit\_thread()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void* yaidsthread_timelimit_thread</td>
<td>(</td>
<td>void * </td>
<td><em>args</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a54b1026e8384b016b67df82dcf0f1755"></span>

<span class="permalink">[◆ ](#a54b1026e8384b016b67df82dcf0f1755)</span>yaidsthread\_update\_alert\_packet\_count()
------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_update_alert_packet_count</td>
<td>(</td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a6546a88ba8192b7da283b1adbb644d67"></span>

<span class="permalink">[◆ ](#a6546a88ba8192b7da283b1adbb644d67)</span>yaidsthread\_update\_output\_packet\_count()
-------------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_update_output_packet_count</td>
<td>(</td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="aaf4517c8531ad7f9047220be9e766ae9"></span>

<span class="permalink">[◆ ](#aaf4517c8531ad7f9047220be9e766ae9)</span>yaidsthread\_update\_pcap\_packet\_count()
-----------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_update_pcap_packet_count</td>
<td>(</td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="a982775bb31404e4c377c83d9e05f476e"></span>

<span class="permalink">[◆ ](#a982775bb31404e4c377c83d9e05f476e)</span>yaidsthread\_update\_yara\_packet\_count()
-----------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_update_yara_packet_count</td>
<td>(</td>
<td>yaidsPacketCounts_ptr </td>
<td><em>packetCounts</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

<span id="ae829130bbd02b253c32286fe1a215d8f"></span>

<span class="permalink">[◆ ](#ae829130bbd02b253c32286fe1a215d8f)</span>yaidsthread\_yara\_thread()
--------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void* yaidsthread_yara_thread</td>
<td>(</td>
<td>void * </td>
<td><em>args</em></td>
<td>)</td>
<td></td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
