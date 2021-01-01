---
title: Code Testing
permalink: /technical/testing
sort: 5
---
![YAIDS](/yaids.png)
# Code Testing

YAIDS is tested using both automated and manual processes. The testing conducted covers functional
testing, security testing, and code quality analysis.

Some of the tools utilized for testing include:
 * [CodeQL](https://securitylab.github.com/tools/codeql)
 * [valgrind](https://valgrind.org/)
 * [AFL/american fuzzy lop](https://lcamtuf.coredump.cx/afl/)
 * [mutiny](https://github.com/Cisco-Talos/mutiny-fuzzer)
 * [ShellCheck](https://www.shellcheck.net/)
 * [gcc (-Wall and -Werror)](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)

In addition to the third-party tools listed above, `yaids` inclues a [_test suite_](https://github.com/wrayjustin/yaids/tree/main/tests).

#### Test Suite
The test suite includes PCAP files and Yara Rules, and verifies that multiple modes of `yaids` return
the correct alerts and output.

The following modes are tested:
 * Output Mode
 * Silent Mode
 * Default Mode / Re-Processing of the Default Mode output

The following test cases are included in the test suite:

| Test Name | Test Count  | Description                                    |
| --------- | ----------- | -----------------------------------------------|
| test_A    | 6           | HTTP Traffic/Rules                             |
| test_B    | 3           | FTP Traffic/Rules                              |
| test_C    | 1           | UDP Traffic/Rules                              |
| test_D    | 9           | Traffic Attributes (Source, Destination, etc.) |
| test_E    | 1           | Combined Ruleset                               |
| test_F    | 3           | BPF Test                                       |

All tests are run three times to ensure consistent results. Additionally, the tests are run using
both standard PCAP and PCAPNG files.

NOTE: The PCAP files included for testing purposes are sources from [NETRESEC](https://www.netresec.com/?page=MACCDC).

#### Automated Testing Workflows
There are three sets of tests conducted automatically on the [yaids/main](https://github.com/wrayjustin/yaids) branch.
The statuses of these tests are displayed at the top of the documentation. Furthermore, you can view the
historical results for these workflows via [GitHub Actions](https://github.com/wrayjustin/yaids/actions).

 * [Build Testing](https://github.com/wrayjustin/yaids/blob/main/.github/workflows/build.yml)
 * [Test Suite](https://github.com/wrayjustin/yaids/blob/main/.github/workflows/tests.yml)
 * [Code Quality/CodeQL](https://github.com/wrayjustin/yaids/blob/main/.github/workflows/codeql-analysis.yml)
