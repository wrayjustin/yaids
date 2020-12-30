# YAIDS
Yara-Based IDS

Yara as an Intrusion Detection System / Yet Another Intrusion Detection System

An Intrusion Detection System (IDS), utilizing Yara and multi-threading

[![Build](https://github.com/wrayjustin/yaids/workflows/Build/badge.svg)](https://github.com/wrayjustin/yaids/actions?query=workflow%3ABuild) [![Code Analysis](https://github.com/wrayjustin/yaids/workflows/Code%20Analysis/badge.svg)](https://github.com/wrayjustin/yaids/actions?query=workflow%3A%22Code+Analysis%22)

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
4. Compile (from the `src` directory): `gcc <GCC OPTIONS> yaids.c yaidsconf.c yaidsio.c yaidspcap.c yaidsyara.c yaidsthread.c -o yaids -I. -I.. -I../include/ -lpcap -lyara -lpthread -lm <ADDITIONAL LIBRARIES>`

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

`2020-12-20 01:01:01 - Metasploit_Download [$s1:0x42:3] {GET /metasploitframework-latest.msi} [171:171/171] (ETH/IP/TCP) 10:00:00:00:00:B3 > 10:00:00:00:00:F7 - 198.51.100.12:41309 > 203.0.113.37:80`

### Rules
YAIDS supports any Yara-compatable rule, including enabled and properly modules.

For convinenve, YAIDS also provides a "drop-in" replacement for `yara` (the Yara Rules Compiler).
In addition to some feature enhancements, `yaidsc` sets "external" variables for various packet offsets.

#### yaidsc
`yaidsc` is a drop-in replacement for `yarac` using an identical syntax. If needed, you can also pass
additional options to `yarac`. Note that `yaidsc` is not a binary replacement for `yarac`, it is a
wrapper script. The two major feature improvments are:
 * Multi-File Support, including Directories (which will compile all `*.yar` files in the directories provided)
 * External Variables for Packet Fields

```
Usage:
        yaidsc <INPUT [NAMESPACE]FILES|DIRECTORIES...> <OUTPUT FILE> 

 * If the input is a directory, all '.yar' files will be compiled.
 * You can compile multiple files or directories, one ruleset.
 * Namespaces can be provided, but only for individual files (not directories).
 ```

#### Packet Headers and Offsets
To provide simple network-related rule creation, without the need to perform complex header parsing and
calculations, `yaids` includes a padded string-based header before the PCAP data. This additional data
is only included during the `yara` scanning (not in the PCAP output, etc.). However, this does mean that
the Packet Offsets are modified, specifically by `255` bytes.  As a result, the raw packet data (including
the unprocessed header) begins at offset `256`.

##### Offsets
The processed (string-based) header uses the following format:
| Value                                                              | Offset Location | Field Size |
| ------------------------------------------------------------------ | --------------- | ---------- |
| Payload Offset                                                     | 0               | 1 (Byte)   |
| Original Packet (Length; This is regardless of the Capture Length) | 1               | 5 (Str)    |
| Frame Protocol                                                     | 6               | 14 (Str)   |
| Network Protocol                                                   | 20              | 14 (Str)   |
| Transport Protocol                                                 | 34              | 14 (Str)   |
| Frane Source Address                                               | 48              | 17 (Str)   |
| Frame Destination Address                                          | 65              | 17 (Str)   |
| Network Source Adderess                                            | 82              | 46 (Str)   |
| Transport Source (Port)                                            | 128             | 5 (Str)    |
| Network Destination Address:                                       | 133             | 46 (Str)   |
| Transport Destination (Port)                                       | 179             | 5 (Str)    |

Again, the packet data begins at byte `256`.

##### Offset Examples
One of the most powerful values of the processed header is the `Payload Offset`.
This offset value can be used in a `yara` `condition`, to match payload-specific data.
Keep in mind, you need to jump an additional `255` bytes to the begining of he packet data,
in additon to payload offset. For example:
```
rule example_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Example (HTTP GET Requests)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET"
    condition:
        $string1 at (int8(0) + 255)z
}
```

The remaining header offsets provide the ability to perform conditional matching (filtering) on the
listed packet attributes (addresses, ports, etc.). For example:
```
rule example_02 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Example (HTTP GET Requests)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET"
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
        $transportSource = "80"
        $networkDest = "192.168.202.90"
        $transportDest = "33783"
    condition:
        $frameProtocol at 6 and
        $netProtocol at 20 and
        $transportProtocol at 34 and
        $frameSource at 48 and
        $frameDest at 65 and
        $networkSource at 82 and
        $transportSource at 128 and
        $networkDest at 133 and
        $transportDest at 179 and
        $string1 at (int8(0) + 255)
}
```

##### Yara External Variables
To simplify the usgae of the packet header values, `yaidsc` (the rule compliler) will automatically
provide `external variables`.  When using `yaidsc` to compile your rules, theres not need to memorize
the offset locations.

The Externabl Variables:
| Value                                                              | Variable          |
| ------------------------------------------------------------------ | ----------------- |
| Original Packet (Length; This is regardless of the Capture Length) | headerStart       |
| Frame Protocol                                                     | frameProtocol     |
| Network Protocol                                                   | netProtocol       |
| Transport Protocol                                                 | transportProtocol |
| Frane Source Address                                               | frameSource       |
| Frame Destination Address                                          | frameDest         |
| Network Source Adderess                                            | networkSource     |
| Transport Source (Port)                                            | transportSource   |
| Network Destination Address:                                       | networkDest       |
| Transport Destination (Port)                                       | transportDest     |

Compare the previous two example to this example using the external variables:
```
rule example_03 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Example (HTTP GET Requests)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET"
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
        $transportSource = "80"
        $networkDest = "192.168.202.90"
        $transportDest = "33783"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest and
        $networkSource at networkSource and
        $transportSource at transportSource and
        $networkDest at networkDest and
        $transportDest at transportDest
        $string1 at (int8(0) + 255)
}
```

#### Supported Protocols
YAIDS supports all libpcap-comptable data (network or otherwise).

owever the header parsing does have some limitations.

##### Supported Layer-2 / Frame Protocols
| Protocol Name | YAIDS VALUE |
| ------------- | ----------- |
| Ethernet      | ETH         |

##### Supported Layer-3 / Network Protocols
| Protocol Name | YAIDS VALUE |
| ------------- | ----------- |
| IPv4          | IP          |
| IPv6          | IP6         |
| 8021AD        | 8021AD      |
| 8021Q         | 8021Q       |
| 8021QINQ      | 8021QINQ    |
| AARP          | AARP        |
| ARP           | ARP         |
| ATALK         | ATALK       |
| DECDNS        | DECDNS      |
| DECDTS        | DECDTS      |
| DN            | DN          |
| IPX           | IPX         |
| LANBRIDGE     | LANBRIDGE   |
| LAT           | LAT         |
| LOOPBACK      | LOOPBACK    |
| MOPDL         | MOPDL       |
| MOPRC         | MOPRC       |
| MPLS          | MPLS        |
| MPLS_MULTI    | MPLS_MULTI  |
| NS            | NS          |
| PPPOED        | PPPOED      |
| PPPOES        | PPPOES      |
| PPP           | PPP         |
| PUP           | PUP         |
| REVARP        | REVARP      |
| SCA           | SCA         |
| SPRITE        | SPRITE      |
| TEB           | TEB         |
| TRAIL         | TRAIL       |
| VEXP          | VEXP        |
| VPROD         | VPROD       |

##### Supported Layer-4 / Transport Protocols
| Protocol Name | YAIDS VALUE |
| ------------- | ----------- |
| TCP           | TCP         |
| UDP           | UDP         |
| ICMP          | ICMP        |

Remember, you can write rules for _any_ traffic type, but if the protocols are not listed above,
`yaids` will not automatically parse the headers and therefore will not populare the `External Variables`

In cases where the protocol is unsupported the default value will be "UNKN", which will be used in the
alert output and the `External Variables`.

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
                                    *-----------------*
                                    |                 |
                                    |     Packets     |
                                    |                 |
                                    |                 |
                                    *--------v--------*
                                             |
                                             |
                                             |
                                             |
                                    #--------v--------#
                                    |                 |
                                    |     Input       |
                                    |     Thread      |
                                    |                 |
                                    #--------v--------#
                                             |
                                             |
                                             |
                                             |
                                    +--------V--------+
                                    |                 |
                                    |     Input       |
                                    |     Queue       |
                                    |                 |
                                    +--v--v-----v--v--+
         +-----------------------------+  |     |  +------------------------------
         |                                |     |                                |
         |                       +--------+     +--------+                       }
         |                       |                       |                       |
#--------V--------#     #--------V--------#     #--------V--------#     #--------V--------#
|                 |     |                 |     |                 |     |                 |
|    Yara         |     |    Yara         |     |    Yara         |     |    Yara         |
|    Thread 1     |     |    Thread 2     |     |    Thread 3     |     |    Thread ...   |
|                 |     |                 |     |                 |     |                 |
#--------v--------#     #--------v--------#     #--------v--------#     #--------v--------#
         |                       |                       |                       |
         |                       +--------+     +--------+                       |
         |                                |     |                                |
         +-----------------------------+  |     |  +-----------------------------|
                                    +--V--V-----V--V--+
                                    |                 |
                                    |     Output      |
                                    |     Queue       |
                                    |                 |
                                    +--------v--------+
                                             |
                                             |
                                             |
                                             |
                                    #--------V--------#
                                    |                 |
                                    |     Output      |
                                    |     Thread      |
                                    |                 |
                                    #---v---------v---#
                                        |         |
                                        |         |
                                 +------+         +------+
                                 |                       |
                        *--------V--------*     *--------V--------*
                        |                 |     |                 |
                        |      PCAP       |     |      Alert      |
                        |      File       |     |      File       |
                        |                 |     |                 |
                        *-----------------*     *-----------------*
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
