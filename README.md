# YAIDS
Yara as an Intrusion Detection System / Yet Another Intrusion Detection System

An Intrusion Detection System (IDS), utilizing Yara and multi-threading

## Installation

### Prerequisites
* Development Toolkit (git, gcc, glibc, etc.)
* libpcap
* libyara (Version 4.X.X)
* POSIX Platform (Linux, etc. -- YAIDS has been tested on Ubuntu 18.04 and 20.04)

### Ubuntu (Quick Install)
1. Review and verify the [`quick-install-ubuntu.sh`](https://raw.githubusercontent.com/wrayjustin/yaids/main/quick-install-ubuntu.sh) file.
2. Run: `curl "https://raw.githubusercontent.com/wrayjustin/yaids/main/quick-install-ubuntu.sh" | bash`

### Other Distributions (Basic Install)
1. Install Development Tools (git, gcc, glibc, etc.)
2. Install `libpcap` (including development headers)
3. Install `libyara` (including development headers)
4. Checkout the project: `git clone https://github.com/wrayjustin/yaids.git`
5. Run: `./build.sh`

### Manual/Development Installation
1. Install Development Tools (git, gcc, glibc, etc.)
2. Install `libpcap` (including development headers)
3. Install `libyara` (including development headers)
4. Checkout the project: `git clone https://github.com/wrayjustin/yaids.git`
5. Run: `./init.sh`, `./configure`, `make`, and `make install`

### Manual (Without AutoTools)
1. Install Development Tools (git, gcc, glibc, etc.)
2. Install `libpcap` (including development headers)
3. Install `libyara` (including development headers)
4. Compile (from the `src` directory): `gcc <GCC OPTIONS> yaids.c yaidsconf.c yaidsio.c yaidspcap.c yaidsyara.c yaidsthread.c -o yaids -I. -I.. -I../include/ -lpcap -lyara -lpthread -lm`

## Usage
YAIDS can run on either an interface (live capture) or stored PCAP files. You can use any Yara supported rules.

### Examples
When running on a live interface, uee the following basic options: `yaids -i <interface> -y <path/to/compiled/yara/rules>`.

To process an exiisting PCAP file, use the following basic options: `yaids -r <path/to/pcap/file> -y <path/to/compiled/yara/rules>`.

### Options
You can obtain more information from the help message by running: `yaids --help`
```
YAIDS -- 0.0.1
        Yara as an Intrusion Detection System / Yet Another Intrusion Detection System
        An Intrusion Detection System (IDS), utilizing Yara and multi-threading
        COPYRIGHT (C) Justin M. Wray | Licensed: BSD 3-Clause
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
Usage:
        yaids
                -i    <DEVICE>            Interface: The libpcap Interface Device name (-i or -r is required)
                -r    <FILE>              Read: PCAP Input File (-i or -r is required)
                -y    <FILE>              Rules: Yara Rules File, compiled (required)
                -n    <NAME>              Prefix Name: Output files, prefix (optional, defaults to epoch)
                -w    <PATH>              Output Path: Output path (optional, defaults to current working directory)
                -t    <INT>               Threads: Number of Yara Threads (optional, defaults to 2 + 4 x CPU cores)
                -l    <INT>               Timelimit: Number of seconds to run, before exiting (optional, defaults to 0 - run until finished or interrupted)
                -s                        Silent Mode: Write output files, but don't output alerts to STDOUT (optional, incompatible with Output Only Mode)
                -o                        Output Only Mode: Output alerts to STDOUT only, does not write to files (optional, incompatible with Silent Mode)
                -x                        Flush Mode: Prevents buffering of file output (optional)
                -a                        Fast Alert Mode: Skip parsing packet headers for alerts (optional)
                -d                        Debug Mode: Verbose output (optional)
                -v                        Version: Show Version
                -h                        Help: Show Help (this list)
```

### Output
By default, YAIDS processed output to both `stdout` and to log files. The default `stdout` provides alerts (rule matches), and two logs are generated - the alerts and PCAP of the triggered packets.

The alert output contains the following fields:
 * Timestamp (YYYY-MM-DD HH:MM:SS)
 * Rule Name
 * Matching Rule Condition and Trigger Location
 * Matching Packet Data
 * Header Length: Length Yara Processed / PCAP Capture Length / Original Packet Length
 * Protocols: Link-Layer / Network / Transport
 * Layer-2 Source > Layer-2 Destination Addresses
 * Layer-3 Source > Layer-3 Destination Addresses and Layer-4 Ports (Address:Port)

An example alert:
```
2020-12-20 01:01:01 - Metasploit_Download [$s1:0x42:3] {GET /metasploitframework-latest.msi} [171:171/171] (ETH/IP/TCP) 10:00:00:00:00:B3 > 10:00:00:00:00:F7 - 198.51.100.12:41309 > 203.0.113.37:80
```

## Technical Details
The processing flow of YAIDS is straight-forward; data comes in, is processed, and then goes out: *INPUT->PROCESSING->OUTPUT*.

The complexity comes from multi-threading. Although network streams (from a device or file) are serial, the packets' processing can be computationally expensive and long-lived. Put simply, packets traverse the network faster than an IDS can examine.

YAIDS resolves this disadvantage by parallelizing the processing of packets.  Thus, the flow is more complex:
 * Input: *INPUT->INPUT QUEUE*
 * Processing: *IINPUT QUEUE->PROCESSING->OUTPUT QUEUE*
 * Output: *OUTPUT QUEUE->OUTPUT*

To obtain a better understanding of this processing flow, review the flowchart below.

### Priority
For live captures, the *INPUT* is prioritized to prevent missing/dropping packets.  For offline processing (reading of a PCAP file), the processing is prioritized to optimize the speed.

Priority is achieved through the utilization of a triple `mutex`:
 * Read/Low Priority
 * Next
 * Write/High Priority

### Data Queues
Data queues are created via a series of `structs` with a pointer to the subsequent `struct`. This is combined with a separate "queue" `struct` containing pointers to the *first* and *last* data `structs`.
```
+-----------------+     +-----------------+     +-----------------+     +-----------------+
|                 |     |                 |     |                 |     |                 |
|  DATA           |     |  DATA           |     |  DATA           |     |  DATA           |
|                 |     |                 |     |                 |     |                 |
|          Next*-------->          Next*-------->          Next*-------->          Next*-------->NULL
+------^----------+     +-----------------+     +-----------------+     +------^----------+
       |                                                                       |
       |                                                                       |
+------|-----------------------------------------------------------------------|----------+
| First*                                                                   Last*          |
|                                                                                         |
|                                          QUEUE                                          |
|                                                                                         |
+-----------------------------------------------------------------------------------------+

```

### Flowchart

```
                                                                        #-----------------#
                                                                   +----+                 +----+
                                                                   |    |    Yara         |    |
                                                                   |    |    Thread 1     |    |
                                                                   |    |                 |    |
                                                                   |    #-----------------#    |
                                                                   |                           |
                                                                   |                           |
                                                                   |    #-----------------#    |                                                *-----------------*
                                                                   | +--+                 +--+ |                                              --+                 |
                                                                   | |  |    Yara         |  | |                                              | |     Alert       |
                                                                   | |  |    Thread 2     |  | |                                              | |     File        |
*-----------------*     #-----------------#     +-----------------+| |  |                 |  | |+-----------------+     #-----------------#   | |                 |
|                 |     |                 |     |                 +- |  #-----------------#  | -+                 |     |                 +---+ *-----------------*
|     Packets     |     |     Input       |     |      Input      +---                       ---+     Output      |     |     Output      |
|                 +-----+     Thread      +-----+      Queue      +---                       ---+     Queue       +-----+     Thread      |
|                 |     |                 |     |                 +- |  #-----------------#  | -+                 |     |                 +---+ *-----------------*
*-----------------*     #-----------------#     +-----------------+| |  |                 |  | |+-----------------+     #-----------------#   | |                 |
                                                                   | |  |    Yara         |  | |                                              | |      PCAP       |
                                                                   | |  |    Thread 3     |  | |                                              | |      File       |
                                                                   | +--+                 +--+ |                                              --+                 |
                                                                   |    #-----------------#    |                                                *-----------------*
                                                                   |                           |
                                                                   |                           |
                                                                   |    #-----------------#    |
                                                                   |    |                 |    |
                                                                   |    |    Yara         |    |
                                                                   |    |    Thread ...   |    |
                                                                   +----+                 +----+
                                                                        #-----------------#
```

## License
```
COPYRIGHT (C) 2020 Justin M. Wray - wray.justin@gmail.com / https://www.justinwray.com
ALL RIGHTS RESERVED

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```
