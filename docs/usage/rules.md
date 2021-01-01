---
title: Rules
permalink: /usage/rules
sort: 4
---
![YAIDS](/yaids.png)
# Rules

YAIDS supports any Yara-compatible rule, including enabled and adequately configured modules.

For convenience, YAIDS also provides a "drop-in" replacement for `yara` (the Yara Rules Compiler).
In addition to some feature enhancements, `yaidsc` sets "external" variables for various packet offsets.

You can learn more about writing Yara rules from the Yara documentation: [Writing Yara Rules](https://yara.readthedocs.io/en/stable/writingrules.html).

#### yaidsc
`yaidsc` is a drop-in replacement for `yarac` using an identical syntax. If needed, you can also pass
additional options to `yarac`. Note that `yaidsc` is not a binary replacement for `yarac`; it is a
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
the Packet Offsets are modified, specifically by `255` bytes. As a result, the raw packet data (including
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
| Network Source Address                                            | 82              | 46 (Str)   |
| Transport Source (Port)                                            | 128             | 5 (Str)    |
| Network Destination Address:                                       | 133             | 46 (Str)   |
| Transport Destination (Port)                                       | 179             | 5 (Str)    |

Again, the packet data begins at byte `256`.

##### Offset Examples
One of the most powerful values of the processed header is the `Payload Offset`.
This offset value can be used in a `yara` `condition`, to match payload-specific data.
Keep in mind, you need to jump an additional `255` bytes to the begining of he packet data,
in additon to payload offset. For example:
```yara
rule example_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Example (HTTP GET Requests)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET"
    condition:
        $string1 at (int8(0) + 255)
}
```

The remaining header offsets provide the ability to perform conditional matching (filtering) on the
listed packet attributes (addresses, ports, etc.). For example:
```yara
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
To simplify using the packet header values, `yaidsc` (the rule compliler) will automatically
provide `external variables`. When using `yaidsc` to compile your rules, there's no need to memorize
the offset locations.

External Variables:

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
```yara
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
        $transportDest at transportDest and
        $string1 at (int8(0) + 255)
}
```

#### Supported Protocols
YAIDS supports all libpcap-compatible data (network or otherwise).

However, the header parsing does have some limitations. Only the following protocols will be parsed.

##### Supported Layer-2 / Frame Protocols

| Protocol Name | YAIDS Value |
| ------------- | ----------- |
| Ethernet      | ETH         |

##### Supported Layer-3 / Network Protocols

| Protocol Name | YAIDS Value |
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

| Protocol Name | YAIDS Value |
| ------------- | ----------- |
| TCP           | TCP         |
| UDP           | UDP         |
| ICMP          | ICMP        |

Remember, you can write rules for _any_ traffic type, but if the protocols are not listed above,
`yaids` will not automatically parse the headers and therefore will not populate the `External Variables`

In cases where the protocol is unsupported, the default value will be "UNKN", which will be used in the
alert output and the `External Variables`.
