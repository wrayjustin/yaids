---
title: Dataflow
permalink: /technical/dataflow
sort: 1
---
![YAIDS](/yaids.png)
# Dataflow

The processing flow of YAIDS is straight-forward; data comes in, is processed, and then goes out: *INPUT->PROCESSING->OUTPUT*.

The complexity comes from multi-threading. Although network streams (from a device or file) are serial, the packets' processing can be computationally expensive and long-lived. Put simply, packets traverse the network faster than an IDS can examine.

YAIDS resolves this disadvantage by parallelizing the processing of packets.  Thus, the flow is more complex:
 * Input: *INPUT->INPUT QUEUE*
 * Processing: *IINPUT QUEUE->PROCESSING->OUTPUT QUEUE*
 * Output: *OUTPUT QUEUE->OUTPUT*

To obtain a better understanding of this processing flow, review the flowchart below.
