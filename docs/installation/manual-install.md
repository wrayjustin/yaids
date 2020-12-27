---
title: Manual (Without AutoTools)
permalink: /installation/manual-install
sort: 5
---
![YAIDS](/yaids.png)
# Manual (Without AutoTools)

``` warning
Most modern distributions should include the required dependencies, monitor the `./configure` output for any missing packages; Lack of optimization may impact the performace of `YAIDS`
```
1. Install Development Tools (git, gcc, glibc, etc.)
2. Install `libpcap` (including development headers)
3. Install `libyara` (including development headers)
4. Compile (from the `src` directory): `gcc <GCC OPTIONS> yaids.c yaidsconf.c yaidsio.c yaidspcap.c yaidsyara.c yaidsthread.c -o yaids -I. -I.. -I../include/ -lpcap -lyara -lpthread -lm <ADDITIONAL LIBRARIES>`
