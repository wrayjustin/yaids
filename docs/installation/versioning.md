---
title: Versioning
permalink: /installation/versioning
sort: 6
---
![YAIDS](/yaids.png)
# Versioning

YAIDS uses a three value version number: X.Y.Z. The version number is a modified form of `SemVer` (Semantic Versioning).

Given the close dependency on `Yara`, the first version value maps to the compatible Major Yara release. While `libpcap`
is another major dependency of `yaids`, `libpcap` maintains binary compatibility  across releases.

The YAIDS version fields: YARA_MAJOR.MAJOR.MINOR (For example, 4.0.0)

* YARA_MAJOR - The compatible Yara (Major) version
* MAJOR - Incremented on significant changes
* MINOR - Incremented on minor changes or patches

Releases that increment  the _YARA\_MAJOR_ field are highly likely to be incompatible with differing versions of Yara.
Releases that increment the _MAJOR_ field may be incompatible with previous `yaids` releases. Whereas _MINOR_ releases
should be forwards and backwards compatible within the same _YARA\_MAJOR\.MAJOR_ release family.

Note: At present, YAIDS is provided via rolling-release; that is, there is currently only a single line of releases.
However, that may potentially change on the release of the next _major_ Yara version.
