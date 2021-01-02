---
title: Command Line Options
permalink: /usage/options
sort: 1
---
![YAIDS](/yaids.png)
# Command Line Options

You can obtain more information from the help message by running: `yaids --help` or `man yaids`
```
YAIDS -- 4.0.1
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
                -f    <FILE>              BPF: BPF (PCAP Filter) File (optional, no traffic filtering)
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
