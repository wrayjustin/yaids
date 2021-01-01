---
title: Security
permalink: /technical/security
sort: 6
---
![YAIDS](/yaids.png)
# Security

# Security Policy
Thank you for your interest in improving the security of `YAIDS`. We appreciate your efforts and responsible disclosure!

## Supported Versions
YAIDS is currently distributed via rolling-releases; ensure you stay up to date with the [yaids/main](https://github.com/wrayjustin/yaids) branch.
However, YAIDS is versioned, and older versions may not receive backported updates.

Currently, the following versions are maintained:

| Version | Supported          |
| ------- | ------------------ |
| 0.0.X   | :white_check_mark: |

## Reporting a Vulnerability

### Upstream
Upstream vulnerabilities or security issues should be reported to the relevant project:
 * libpcap: https://github.com/the-tcpdump-group/libpcap
 * libyara: https://github.com/VirusTotal/yara

If an upstream vulnerability impacts the security of YAIDS, please submit a
[Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D) for notification purposes.

### Denial of Service
If the security flaw does not result in [Remote Code Execution](https://en.wikipedia.org/wiki/Arbitrary_code_execution) please submit your request
via a [Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D).

This public reporting should only apply when the only impact of the vulnerability is the stoppage of YAIDS execution, not in cases where process flow (or memory)
is controllable. For example, a _double free_ should be filed as an
[issue](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D), whereas a _buffer overflow_ should not.

### Code Execution/Process Control/Memory Control
In cases where the security flaw results in [Remote Code Execution](https://en.wikipedia.org/wiki/Arbitrary_code_execution), or other similar control
of the process, memory, or system, please submit your report via email: wray.justin@gmail.com

Please include `[YAIDS SECURITY]` at the beginning of your email subject. The report should include the same level of detail as requested in a
[Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D), including full details and information about the vulnerability.

### Other
Issues, such as theoretical flaws, standards compliance, code quality, etc., should be reported as either a
[Feature Request](https://github.com/wrayjustin/yaids/issues/new?labels=enhancement&template=feature-request.md&title=%5BFEATURE%5D)
or [Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D).

## Advisories
Your security submission may result in an advisory or update. For non-public submission, please include information on if and how you would like to be credited for the report.

## Proactive Security
Please read abour the testing, including security testing that is conducted on the YAIDS code: [Code Testing](https://yaids.io/technical/security).
This information is also avaliable within the [README](https://github.com/wrayjustin/yaids/blob/main/README.md).

## Disclaimer
Although security is essential, it is equally important to remember that YAIDS is provided _AS-IS_, without any warranty. Support, security, or otherwise, is not guaranteed.

```
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
