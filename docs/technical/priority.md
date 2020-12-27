---
title: Thread Priority
permalink: /technical/priority
sort: 2
---
![YAIDS](/yaids.png)
# Thread Priority

For live captures, the *INPUT* is prioritized to prevent missing/dropping packets.  For offline processing (reading of a PCAP file), the processing is prioritized to optimize the speed.

Priority is achieved through the utilization of a triple `mutex`:
 * Read/Low Priority
 * Next
 * Write/High Priority
