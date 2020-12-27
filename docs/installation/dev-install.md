---
title: Manual/Development Installation
permalink: /installation/dev-install
sort: 4
---
![YAIDS](/yaids.png)
# Manual/Development Installation

``` note
Most modern distributions should include the required dependencies, monitor the `./configure` output for any missing packages
```
1. Install Development Tools (git, gcc, glibc, etc.)
2. Install `libpcap` (including development headers)
3. Install `libyara` (including development headers)
4. Checkout the project: `git clone https://github.com/wrayjustin/yaids.git`
5. Run: `./init.sh`, `./configure`, `make`, and `make install`
