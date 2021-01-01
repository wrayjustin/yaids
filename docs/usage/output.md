---
title: Output
permalink: /usage/output
sort: 3
---
![YAIDS](/yaids.png)
# Output

By default, YAIDS processed output to both `stdout` and to log files. The default `stdout` provides alerts
(rule matches), and two logs are generated - the alerts and PCAP of the triggered packets.

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

`2020-12-20 01:01:01 - Metasploit_Download [$s1:0x42:3] {GET /metasploitframework-latest.msi}
[171:171/171] (ETH/IP/TCP) 10:00:00:00:00:B3 > 10:00:00:00:00:F7 - 198.51.100.12:41309 > 203.0.113.37:80`
