---
title: yaidsthread
permalink: code/headers/yaidsthread
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


[Macros](#define-members) | [Functions](#func-members) |
[Variables](#var-members)

yaidsthread.h File Reference


<span id="define-members"></span> Macros
----------------------------------------

\#define 

<a href="/code/headers/yaidsthread#acbf6b1f2542e5e92006f309706938417" class="el">YAIDS_THREAD_INPUT_PCAP</a>   1

 

\#define 

<a href="/code/headers/yaidsthread#ae3303f2eb92ae79d642937f07983aa02" class="el">YAIDS_THREAD_OUTPUT</a>   2

 

\#define 

<a href="/code/headers/yaidsthread#a0f14b38758c6f398ff6da5c6bb2e1f37" class="el">YAIDS_THREAD_YARA</a>   3

 

\#define 

<a href="/code/headers/yaidsthread#a2d3ce31d23bcc2a8d8d6ef43913f901d" class="el">YAIDS_THREAD_TIMELIMIT</a>   4

 

\#define 

<a href="/code/headers/yaidsthread#ac5295b130e8c6687f59112422c696682" class="el">MAX_OUTPUT_ELEMENT_SIZE</a>   60

 

\#define 

<a href="/code/headers/yaidsthread#a0be2f525350902ce32274365d7a89906" class="el">MAX_OUTPUT_SINGLE_SIZE</a>   20

 

<span id="func-members"></span> Functions
-----------------------------------------

<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> 

<a href="/code/headers/yaidsthread#a6a933ee1ae422d055ce24e97343d6a4e" class="el">yaidsthread_new_packet_counts</a>
(void)

 

<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> 

<a href="/code/headers/yaidsthread#a988d25f0e0e90b04e5c5ca8a253e00c7" class="el">yaidsthread_new_thread_statuses</a>
(void)

 

<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> 

<a href="/code/headers/yaidsthread#a475063005017f81d2689ea411e728852" class="el">yaidsthread_new_input_queue</a>
(void)

 

<a href="/code/headers/yaidstypes#a19f71db535637ca80e5dc18dc95d92d3" class="el">yaidsInputDataNode_ptr</a> 

<a href="/code/headers/yaidsthread#aec57d9b8d9d89d910c580acc1a00a6f8" class="el">yaidsthread_new_input_data</a>
(<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet)

 

<a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a> 

<a href="/code/headers/yaidsthread#a1325d9214f8b6f7e3cb9a46c24aa7034" class="el">yaidsthread_new_input_thread_args</a>
(<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
dataQueue,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses)

 

<a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a> 

<a href="/code/headers/yaidsthread#a1efcabff9f50cb25235b7633195c5db8" class="el">yaidsthread_new_timelimit_thread_args</a>
(bool \*yaidsRunning,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> 

<a href="/code/headers/yaidsthread#a6f5d602f913a4c1aad64cd7a658281bd" class="el">yaidsthread_new_output_queue</a>
(void)

 

<a href="/code/headers/yaidstypes#a2aa07c15f3e1d6bab8bc194f82a43e72" class="el">yaidsOutputDataNode_ptr</a> 

<a href="/code/headers/yaidsthread#aac229c33966244673412c5cc26256a11" class="el">yaidsthread_new_output_data</a>
(<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet, char \*alert)

 

<a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a> 

<a href="/code/headers/yaidsthread#a6a1c4398bade4b4a7e1f41b514432872" class="el">yaidsthread_new_output_thread_args</a>
(<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
dataQueue,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses)

 

<a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a> 

<a href="/code/headers/yaidsthread#ab233f6b72db40463f89a05e088433fdb" class="el">yaidsthread_new_yara_thread_args</a>
(<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
inputDataQueue,
<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
outputDataQueue,
<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yaraScanner,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses)

 

void 

<a href="/code/headers/yaidsthread#aaf4517c8531ad7f9047220be9e766ae9" class="el">yaidsthread_update_pcap_packet_count</a>
(<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

void 

<a href="/code/headers/yaidsthread#a982775bb31404e4c377c83d9e05f476e" class="el">yaidsthread_update_yara_packet_count</a>
(<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

void 

<a href="/code/headers/yaidsthread#a54b1026e8384b016b67df82dcf0f1755" class="el">yaidsthread_update_alert_packet_count</a>
(<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

void 

<a href="/code/headers/yaidsthread#a6546a88ba8192b7da283b1adbb644d67" class="el">yaidsthread_update_output_packet_count</a>
(<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

void 

<a href="/code/headers/yaidsthread#a6f2a001be78db3dc06929356a50fd3f8" class="el">yaidsthread_set_pcap_finished</a>
(<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

void 

<a href="/code/headers/yaidsthread#ab132d969ced522101add67bf7b970903" class="el">yaidsthread_set_yara_finished</a>
(<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

void 

<a href="/code/headers/yaidsthread#acb8a3ee01dadcec309268f73e8df1def" class="el">yaidsthread_set_output_finished</a>
(<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

void 

<a href="/code/headers/yaidsthread#a9dd9b96734c3d9f72c58b3d8ebf69070" class="el">yaidsthread_add_input_data</a>
(<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
dataQueue,
<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet)

 

<a href="/code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a> 

<a href="/code/headers/yaidsthread#aef69ad3066889a2a88760f93be494a1b" class="el">yaidsthread_get_input_data</a>
(<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
dataQueue)

 

void 

<a href="/code/headers/yaidsthread#aebee0adbdc704f68fbdddb9e22028298" class="el">yaidsthread_add_output_data</a>
(<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
dataQueue,
<a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a>
packet, char \*alert)

 

<a href="/code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a> 

<a href="/code/headers/yaidsthread#ae2b2e424ad69425f5901b63a5dc4ee8a" class="el">yaidsthread_get_output_data</a>
(<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
dataQueue)

 

<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> 

<a href="/code/headers/yaidsthread#aae0f14acca0e4c3a07ee23af9dace2c3" class="el">yaidsthread_create_pcap_thread</a>
(<a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a>
threadArgs)

 

<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> 

<a href="/code/headers/yaidsthread#a7411c65656b15681dff491360d36deab" class="el">yaidsthread_create_yara_thread</a>
(<a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a>
threadArgs)

 

<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> 

<a href="/code/headers/yaidsthread#a82c079c907e1c216d634bd05569df759" class="el">yaidsthread_create_output_thread</a>
(<a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a>
threadArgs)

 

<a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> 

<a href="/code/headers/yaidsthread#a280e7b978e356e3e206c4e4ec5d62a69" class="el">yaidsthread_create_timelimit_thread</a>
(<a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a>
threadArgs)

 

<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> 

<a href="/code/headers/yaidsthread#ac38b8ef3fc98bbf1f4f1031a02615ac0" class="el">yaidsthread_new_threadlist</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config)

 

<a href="/code/headers/yaidstypes#a41f17220799de0556349c9ee5245771f" class="el">yaidsThreadInfo_ptr</a> 

<a href="/code/headers/yaidsthread#a3b6a788e515bf8733db99521c5f81b98" class="el">yaidsthread_new_threadinfo</a>
(void)

 

int 

<a href="/code/headers/yaidsthread#af095cc8df152960f2916e679ed87ce57" class="el">yaidsthread_start_input_threads</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>
threadList,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
yaidsInputQueue,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

int 

<a href="/code/headers/yaidsthread#a7175dab16d3c6ba7116dea31deb4db5b" class="el">yaidsthread_start_yara_threads</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>
threadList,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
yaidsInputQueue,
<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
yaidsOutputQueue,
<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yaraScanners,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts)

 

int 

<a href="/code/headers/yaidsthread#ad3ff05632e8d28bbabd366eda68c7d9b" class="el">yaidsthread_start_output_threads</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>
threadList,
<a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a>
threadStatuses,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
yaidsOutputQueue,
<a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a>
packetCounts, int scannerThreadCount)

 

int 

<a href="/code/headers/yaidsthread#a06eb89b53753082fcd95cb1fc58d710c" class="el">yaidsthread_start_timelimit_threads</a>
(<a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a>
config,
<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>
threadList, bool \*yaidsRunning, int scannerThreadCount)

 

int 

<a href="/code/headers/yaidsthread#ab93f99f828b9cf7cfb83adff1466f82a" class="el">yaidsthread_run_threads</a>
(bool \*yaidsRunning,
<a href="/code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a>
config,
<a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a>
threadList,
<a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a>
yaidsInputQueue,
<a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a>
yaidsOutputQueue,
<a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a>
pcapHandle,
<a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a>
yaraScanners)

 

void \* 

<a href="/code/headers/yaidsthread#a84e71ea87509d932aed4ebb8a0be8876" class="el">yaidsthread_pcap_thread</a>
(void \*args)

 

void \* 

<a href="/code/headers/yaidsthread#ae829130bbd02b253c32286fe1a215d8f" class="el">yaidsthread_yara_thread</a>
(void \*args)

 

void \* 

<a href="/code/headers/yaidsthread#a317c18d64dbb6cb5235202452edf98fb" class="el">yaidsthread_output_thread</a>
(void \*args)

 

void \* 

<a href="/code/headers/yaidsthread#a6e0481a7d3d56e4fc647b4c2e4649f14" class="el">yaidsthread_timelimit_thread</a>
(void \*args)

 

<span id="var-members"></span> Variables
----------------------------------------

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#ab9333389297298033adae2fb1b352ef0" class="el">dataInputQueueMutex</a>
= PTHREAD\_MUTEX\_INITIALIZER

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#ace02c28d10e1e14887b9dcfb14ecb5d3" class="el">dataInputQueueNextMutex</a>
= PTHREAD\_MUTEX\_INITIALIZER

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#a78c4025cef1e7a6e0a00dc5317f98cce" class="el">dataInputQueueReadMutex</a>
= PTHREAD\_MUTEX\_INITIALIZER

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#a20f86573ce7bd755438b09d54c2e76e5" class="el">dataOutputQueueMutex</a>
= PTHREAD\_MUTEX\_INITIALIZER

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#a93aa8f64e3efe08da4ecb3e245a4ab39" class="el">dataOutputQueueNextMutex</a>

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#a2e924d549a3a1d95059b7ffc9382ea0c" class="el">dataOutputQueueReadMutex</a>

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#a9f6416539c3dab8294acadcf04dca186" class="el">packetCountsandThreadStatusesMutex</a>
= PTHREAD\_MUTEX\_INITIALIZER

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#ab89550d474c607eade3fdcdccd6f3a5d" class="el">packetCountsandThreadStatusesNextMutex</a>

 

static pthread\_mutex\_t 

<a href="/code/headers/yaidsthread#ad33224c11060faf9724c0b5615b8107f" class="el">packetCountsandThreadStatusesLowMutex</a>

 

Macro Definition Documentation
------------------------------

<span id="ac5295b130e8c6687f59112422c696682"></span>

<span class="permalink">[◆ ](#ac5295b130e8c6687f59112422c696682)</span>MAX\_OUTPUT\_ELEMENT\_SIZE
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define MAX_OUTPUT_ELEMENT_SIZE   60</td>
</tr>
</tbody>
</table>

<span id="a0be2f525350902ce32274365d7a89906"></span>

<span class="permalink">[◆ ](#a0be2f525350902ce32274365d7a89906)</span>MAX\_OUTPUT\_SINGLE\_SIZE
------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define MAX_OUTPUT_SINGLE_SIZE   20</td>
</tr>
</tbody>
</table>

<span id="acbf6b1f2542e5e92006f309706938417"></span>

<span class="permalink">[◆ ](#acbf6b1f2542e5e92006f309706938417)</span>YAIDS\_THREAD\_INPUT\_PCAP
-------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_THREAD_INPUT_PCAP   1</td>
</tr>
</tbody>
</table>

<span id="ae3303f2eb92ae79d642937f07983aa02"></span>

<span class="permalink">[◆ ](#ae3303f2eb92ae79d642937f07983aa02)</span>YAIDS\_THREAD\_OUTPUT
--------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_THREAD_OUTPUT   2</td>
</tr>
</tbody>
</table>

<span id="a2d3ce31d23bcc2a8d8d6ef43913f901d"></span>

<span class="permalink">[◆ ](#a2d3ce31d23bcc2a8d8d6ef43913f901d)</span>YAIDS\_THREAD\_TIMELIMIT
-----------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_THREAD_TIMELIMIT   4</td>
</tr>
</tbody>
</table>

<span id="a0f14b38758c6f398ff6da5c6bb2e1f37"></span>

<span class="permalink">[◆ ](#a0f14b38758c6f398ff6da5c6bb2e1f37)</span>YAIDS\_THREAD\_YARA
------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>#define YAIDS_THREAD_YARA   3</td>
</tr>
</tbody>
</table>

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
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>dataQueue</em>,</td>
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

<span id="aebee0adbdc704f68fbdddb9e22028298"></span>

<span class="permalink">[◆ ](#aebee0adbdc704f68fbdddb9e22028298)</span>yaidsthread\_add\_output\_data()
-------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_add_output_data</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> </td>
<td><em>dataQueue</em>,</td>
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
<td><a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> yaidsthread_create_output_thread</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> yaidsthread_create_pcap_thread</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> yaidsthread_create_timelimit_thread</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a101b6c8fdbd95b1e05b41e3ced0ec917" class="el">yaidsThreadReturn</a> yaidsthread_create_yara_thread</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a800a876dd63642e3db6c1ed28e185907" class="el">yaidsInputDataNode</a> yaidsthread_get_input_data</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a4926527e9fc83914c36bed059daf777f" class="el">yaidsOutputDataNode</a> yaidsthread_get_output_data</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a19f71db535637ca80e5dc18dc95d92d3" class="el">yaidsInputDataNode_ptr</a> yaidsthread_new_input_data</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> yaidsthread_new_input_queue</td>
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
<td><a href="/code/headers/yaidstypes#a9566a88b439b34380a64a35dd380a588" class="el">yaidsInputThreadArgs_ptr</a> yaidsthread_new_input_thread_args</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>dataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a2aa07c15f3e1d6bab8bc194f82a43e72" class="el">yaidsOutputDataNode_ptr</a> yaidsthread_new_output_data</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a77be557f4c3954726bc8f85105cf5130" class="el">yaidsPcapPacket_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> yaidsthread_new_output_queue</td>
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
<td><a href="/code/headers/yaidstypes#a9492ae9a8c7b48ba7ad8a8c8ab909a62" class="el">yaidsOutputThreadArgs_ptr</a> yaidsthread_new_output_thread_args</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> </td>
<td><em>dataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> yaidsthread_new_packet_counts</td>
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
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> yaidsthread_new_thread_statuses</td>
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
<td><a href="/code/headers/yaidstypes#a41f17220799de0556349c9ee5245771f" class="el">yaidsThreadInfo_ptr</a> yaidsthread_new_threadinfo</td>
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
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> yaidsthread_new_threadlist</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a1a3e1eb23151c7cb06f1f5729093cb40" class="el">yaidsTimelimitThreadArgs_ptr</a> yaidsthread_new_timelimit_thread_args</td>
<td>(</td>
<td>bool * </td>
<td><em>yaidsRunning</em>,</td>
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

<span id="ab233f6b72db40463f89a05e088433fdb"></span>

<span class="permalink">[◆ ](#ab233f6b72db40463f89a05e088433fdb)</span>yaidsthread\_new\_yara\_thread\_args()
-------------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td><a href="/code/headers/yaidstypes#a80abae2dda4b7446a0d572c7e0fb36a8" class="el">yaidsYaraThreadArgs_ptr</a> yaidsthread_new_yara_thread_args</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>inputDataQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a4964c6268238c2f5248ecf200bbafb12" class="el">yaidsOutputDataQueue_ptr</a> </td>
<td><em>outputDataQueue</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
<td><em>yaraScanner</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
<td><em>packetCounts</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a84cc20039333a5a366f5b6d6b46a446b" class="el">yaidsConfig</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>yaidsInputQueue</em>,</td>
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
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
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

<span id="a6f2a001be78db3dc06929356a50fd3f8"></span>

<span class="permalink">[◆ ](#a6f2a001be78db3dc06929356a50fd3f8)</span>yaidsthread\_set\_pcap\_finished()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_set_pcap_finished</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
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

<span id="ab132d969ced522101add67bf7b970903"></span>

<span class="permalink">[◆ ](#ab132d969ced522101add67bf7b970903)</span>yaidsthread\_set\_yara\_finished()
---------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>void yaidsthread_set_yara_finished</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
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

<span id="af095cc8df152960f2916e679ed87ce57"></span>

<span class="permalink">[◆ ](#af095cc8df152960f2916e679ed87ce57)</span>yaidsthread\_start\_input\_threads()
-----------------------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsthread_start_input_threads</td>
<td>(</td>
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>yaidsInputQueue</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8582f875a3bead293c87b8bce98ed503" class="el">yaidsPcapHandle_ptr</a> </td>
<td><em>pcapHandle</em>,</td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a3ff4e6a77ab1ce71098854bbc6459802" class="el">yaidsConfig_ptr</a> </td>
<td><em>config</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#ae354da9323e110104a59143d2c01234b" class="el">yaidsThreadList_ptr</a> </td>
<td><em>threadList</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a8cb52dabc859ccd49ea273f505b6f0e8" class="el">yaidsThreadStatuses_ptr</a> </td>
<td><em>threadStatuses</em>,</td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a4b52561086d9bbae2b7e5a24b7767bf0" class="el">yaidsInputDataQueue_ptr</a> </td>
<td><em>yaidsInputQueue</em>,</td>
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
<td><a href="/code/headers/yaidstypes#ab9497140a5558e69b16fdf399a77e483" class="el">yaidsYaraScanner_ptr</a> </td>
<td><em>yaraScanners</em>,</td>
</tr>
<tr class="odd">
<td></td>
<td></td>
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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
<td><a href="/code/headers/yaidstypes#a0d30b24cf3be4d088d00205e27aa0130" class="el">yaidsPacketCounts_ptr</a> </td>
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

Variable Documentation
----------------------

<span id="ab9333389297298033adae2fb1b352ef0"></span>

<span class="permalink">[◆ ](#ab9333389297298033adae2fb1b352ef0)</span>dataInputQueueMutex
------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataInputQueueMutex = PTHREAD_MUTEX_INITIALIZER</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

<span id="ace02c28d10e1e14887b9dcfb14ecb5d3"></span>

<span class="permalink">[◆ ](#ace02c28d10e1e14887b9dcfb14ecb5d3)</span>dataInputQueueNextMutex
----------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataInputQueueNextMutex = PTHREAD_MUTEX_INITIALIZER</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

<span id="a78c4025cef1e7a6e0a00dc5317f98cce"></span>

<span class="permalink">[◆ ](#a78c4025cef1e7a6e0a00dc5317f98cce)</span>dataInputQueueReadMutex
----------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataInputQueueReadMutex = PTHREAD_MUTEX_INITIALIZER</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

<span id="a20f86573ce7bd755438b09d54c2e76e5"></span>

<span class="permalink">[◆ ](#a20f86573ce7bd755438b09d54c2e76e5)</span>dataOutputQueueMutex
-------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataOutputQueueMutex = PTHREAD_MUTEX_INITIALIZER</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

<span id="a93aa8f64e3efe08da4ecb3e245a4ab39"></span>

<span class="permalink">[◆ ](#a93aa8f64e3efe08da4ecb3e245a4ab39)</span>dataOutputQueueNextMutex
-----------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataOutputQueueNextMutex</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

**Initial value:**

=

PTHREAD\_MUTEX\_INITIALIZER

<span id="a2e924d549a3a1d95059b7ffc9382ea0c"></span>

<span class="permalink">[◆ ](#a2e924d549a3a1d95059b7ffc9382ea0c)</span>dataOutputQueueReadMutex
-----------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t dataOutputQueueReadMutex</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

**Initial value:**

=

PTHREAD\_MUTEX\_INITIALIZER

<span id="ad33224c11060faf9724c0b5615b8107f"></span>

<span class="permalink">[◆ ](#ad33224c11060faf9724c0b5615b8107f)</span>packetCountsandThreadStatusesLowMutex
------------------------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t packetCountsandThreadStatusesLowMutex</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

**Initial value:**

=

PTHREAD\_MUTEX\_INITIALIZER

<span id="a9f6416539c3dab8294acadcf04dca186"></span>

<span class="permalink">[◆ ](#a9f6416539c3dab8294acadcf04dca186)</span>packetCountsandThreadStatusesMutex
---------------------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t packetCountsandThreadStatusesMutex = PTHREAD_MUTEX_INITIALIZER</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

<span id="ab89550d474c607eade3fdcdccd6f3a5d"></span>

<span class="permalink">[◆ ](#ab89550d474c607eade3fdcdccd6f3a5d)</span>packetCountsandThreadStatusesNextMutex
-------------------------------------------------------------------------------------------------------------

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><table>
<tbody>
<tr class="odd">
<td>pthread_mutex_t packetCountsandThreadStatusesNextMutex</td>
</tr>
</tbody>
</table></td>
<td><span class="mlabels"><span class="mlabel">static</span></span></td>
</tr>
</tbody>
</table>

**Initial value:**

=

PTHREAD\_MUTEX\_INITIALIZER

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
