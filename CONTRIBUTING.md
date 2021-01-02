# Contribution Guide

Thank you for your interest in contributing to YAIDS. Please read and follow this guidance when participating within the YAIDS project and community.

## Issues

### Support

**Are you looking for guidance or have a question?** You can submit a [Support Request](https://github.com/wrayjustin/yaids/issues/new?&labels=question&template=support.md&title=%5BSUPPORT%5D) via the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/). Before filing a request, please consider the following:

 * *Is your question answered in the documentation?* Search and review the documentation found at [yaids.io](https://yaids.io).
 * *Has your question already been asked?* Please search through the open [Issue Tracker](https://github.com/wrayjustin/yaids/issues/) for relevant submissions.
 * *Is your question better suited for an upstream project?* Consider the authority for your request, review the upstream documentation, and if relevant, submit your request upstream -
	 * `yara` - [Documentation](https://yara.readthedocs.io/) - [Issue Tracker](https://github.com/VirusTotal/yara/issues)
	 * `libpcap` - [Documentation](https://www.tcpdump.org/index.html#documentation) - [Issue Tracker](https://github.com/the-tcpdump-group/libpcap/issues)

When submitting a [Support Request](https://github.com/wrayjustin/yaids/issues/new?&labels=question&template=support.md&title=%5BSUPPORT%5D) it is imperative that you fully complete the request template with all information. Failure to provide full details in your submission may delay or prevent assistance. Please remember that the [Code of Coduct](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md) is in effect for issue submissions.

### Bug Reports

**Did you find a bug in YAIDS?** You can submit a [Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D) via the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/). Before filing a bug, please consider the following:

 * *Has the bug already been submitted?* Please search through the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/) for previous submissions.
 * *Is there an existing Pull Request that resolves the bug?* Please search through the open [Pull Requests](https://github.com/wrayjustin/yaids/pulls) for a pertinent submission.
 * *Is your report better suited for an upstream project?* Consider the authority for your report, review the upstream documentation, and if relevant, submit your request upstream -
	 * `yara` - [Documentation](https://yara.readthedocs.io/) - [Issue Tracker](https://github.com/VirusTotal/yara/issues)
	 * `libpcap` - [Documentation](https://www.tcpdump.org/index.html#documentation) - [Issue Tracker](https://github.com/the-tcpdump-group/libpcap/issues)

When submitting a [Bug Report](https://github.com/wrayjustin/yaids/issues/new?labels=bug&template=bug-report.md&title=%5BBUG%5D) it is critical that you fully complete the bug template with all information. Failure to provide full details in your submission may delay or prevent assistance. Please remember that the [Code of Coduct](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md) is in effect for issue submissions.

### Feature Requests

**Do you have an idea for YAIDS?** You can submit a [Feature Request](https://github.com/wrayjustin/yaids/issues/new?labels=enhancement&template=feature-request.md&title=%5BFEATURE%5D) via the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/). Before filing a request, please consider the following:

 * *Has the feature already been requested?* Please search through the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/) for a prior request.
 * *Is there an existing Pull Request that provides the feature?* Please search through the open [Pull Requests](https://github.com/wrayjustin/yaids/pulls) for an existing submission.
 * *Is your request better suited for an upstream project?* Consider the authority for your report, review the upstream documentation, and if relevant, submit your request upstream -
	 * `yara` - [Documentation](https://yara.readthedocs.io/) - [Issue Tracker](https://github.com/VirusTotal/yara/issues)
	 * `libpcap` - [Documentation](https://www.tcpdump.org/index.html#documentation) - [Issue Tracker](https://github.com/the-tcpdump-group/libpcap/issues)
 * *Have you already developed your feature?* YAIDS is Open Source; you are welcome to submit your feature via a Pull Request (please submit a Feature Request to accompany your Pull Request).

When submitting a [Feature Request](https://github.com/wrayjustin/yaids/issues/new?labels=enhancement&template=feature-request.md&title=%5BFEATURE%5D) it is essential that you fully complete the request template with all information. Failure to provide full details in your submission may delay or prevent assistance. Please remember that the [Code of Coduct](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md) is in effect for issue submissions.

### Security Issues

**Have you found a security issue within YAIDS?** Please review and follow the [Security Policy](https://github.com/wrayjustin/yaids/security/policy).

## Pull Requests

**Are you interested in contributing code, documentation, or changes to YAIDS?** You can submit a [Pull Request](https://github.com/wrayjustin/yaids/compare).

Before submitting a Pull Request, please consider the following:

 * *Has the intended changes already been requested?* Please search through the [Issue Tracker](https://github.com/wrayjustin/yaids/issues/) for an existing issue (bug report, feature request, discussions, etc.). If no existing issue is found, please open an issue (all Pull Requests require a corresponding Issue).
 * *Is there an existing Pull Request that provides the same changes?* Please search through the open [Pull Requests](https://github.com/wrayjustin/yaids/pulls) for an existing request.
 * *Is your request better suited for an upstream project?* Consider the authority for your changes, review the upstream documentation, and if relevant, submit your request upstream -
	 * `yara` - [Documentation](https://yara.readthedocs.io/) - [Issue Tracker](https://github.com/VirusTotal/yara/issues)
	 * `libpcap` - [Documentation](https://www.tcpdump.org/index.html#documentation) - [Issue Tracker](https://github.com/the-tcpdump-group/libpcap/issues)
 * *Have you tested your changes?* Please use the [Test Suite ](https://github.com/wrayjustin/yaids/blob/main/tests/), and ensure all tests are passing.
 * *Have you read the [Contributor Agreement](https://github.com/wrayjustin/yaids/blob/main/CLA.md)?* All submissions require acceptance and agreement to the Contributor Agreement.

All Pull Requests **require** the following checklist be fully executed and completed:

> - [ ] I have formatted the code (`./format.sh`).
> - [ ] I have updated the documentation, and processed the document generation (`./generate_docs.sh`).
> - [ ] I have tested the code based on the project testing methodologies.
> - [ ] I have ensured the project is building successfully.
> - [ ] I have updated relevant test cases, run the [**Test Suite** ](https://github.com/wrayjustin/yaids/blob/main/tests/), and all tests are passing.
> - [ ] I have read the [**CONTRIBUTING** ](https://github.com/wrayjustin/yaids/blob/main/CONTRIBUTING.md) document.
> - [ ] I have read and agree to the [**Contributor Agreement**](https://github.com/wrayjustin/yaids/blob/main/CLA.md) document.
> - [ ] I have read and agree to the [**Code of Conduct**](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md) document.
> - [ ] I have released the changes within this PR under the project [**LICENSE**](https://github.com/wrayjustin/yaids/blob/main/COPYING.md).
> - [ ] I commit to tracking this PR, discussing the changes and feedback, completing required changes, fixing issues, and ensuring merge compatibility (merge/rebasing).
> - [ ] I understand that if the changes incorporated within this PR are for some reason incompatible with the current code that these changes may be incorporated within another PR (with proper attribution).

When submitting a [Pull Request](https://github.com/wrayjustin/yaids/compare) it is mandatory that you fully complete the PR template with all information. Failure to provide full details in your submission may delay or prevent the inclusion of your changes. Please remember that the [Code of Coduct](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md) is in effect for Pull Request submissions.

### Formatting

For simplicity and convenience, the `yaids` repository includes a [formatting script](https://github.com/wrayjustin/yaids/blob/main/format.sh). The formating script requires and uses [`GNU indent`](https://www.gnu.org/software/indent/) (this should be included, or installable on your Linux distribution) and [`shfmt`](https://github.com/mvdan/sh) (this should be installable on your distribution).

All code submissions must be formatted to the project standards (preferably with the `format.sh` script.  Formatting your code is straight-forward:

 1. Develop your Changes/Code
 2. (Optionally) Stage/Commit to your Branch
 3. Run `./format.sh` from the project root directory

For C-Code, `yaids` uses: `indent -kr -ci4 -cli4 -i4 -nut --no-tabs`
For BASH Code, `yaids` uses: `shfmt -i 4 -ci -sr -fn -kp -w`

### Documentation

Project documentation is used in multiple portions of the `yaids` codebase, including:
 * Project Repository
 * Project Website
 * Distributed Documentation (MAN Page)

It is critical that documentation stays closely aligned and up-to-date with the project codebase. All changes should be accompanied by relevant documentation updates.

For convenience and reproducibility, documentation is scripted for automated generation. The [docuementation generation script](https://github.com/wrayjustin/yaids/blob/main/generate_docs.sh) builds the documentation from multiple sources, including:
 * [README.md](https://github.com/wrayjustin/yaids/blob/main/README.md)
 * [CONTRIBUTING.md](https://github.com/wrayjustin/yaids/blob/main/CONTRIBUTING.md)
 * [CODE_OF_CONDUCT.md](https://github.com/wrayjustin/yaids/blob/main/CODE_OF_CONDUCT.md)
 * [CLA.md](https://github.com/wrayjustin/yaids/blob/main/CLA.md)
 * [SECURITY.md](https://github.com/wrayjustin/yaids/blob/main/SECURITY.md)
 * [Source Code](https://github.com/wrayjustin/yaids/tree/main/src)
 * [Commit Log](https://github.com/wrayjustin/yaids/commits/main)

Note that the Source Code documentation generation is performed with `doxygen`, which is required to run the documentation generation script.

To update the documentation, follow these steps:

 1. Develop and Format your Changes/Code
 2. (Optionally) Stage/Commit to your Branch
 3. Update the relevant Markdown files (`README.md`, etc.)
 4. Run `./generate_docs.sh` from the project root directory

The documentation generated will be used for the [YAIDS](https://yaids.io) website. You can test the website locally with [`jekyll`](https://jekyllrb.com/) (jekyll is not required for documentation generation, but it is required for local testing of the website).

To test the website locally, you can either (a) uncomment the testing lines at the bottom of the [docuementation generation script](https://github.com/wrayjustin/yaids/blob/main/generate_docs.sh) or (b) run `bundle exec jekyll serve -H <IP Address>`.

Do **NOT** commit the built site (this is automatically handled by `GitHub Pages`.

### Testing

To learn more about the expected testing methods for the YAIDS project, please see the [testing documentation](https://yaids.io/technical/testing).

In addition to the tooling mentioned in the testing documentation, all changes must pass the [Test Suite ](https://github.com/wrayjustin/yaids/blob/main/tests/). Running the Test Suite is quick and easy, as the Test Suite includes a [testing script](https://github.com/wrayjustin/yaids/blob/main/tests/tests.sh).

To run and confirm successfully passing of the tests, complete the following:

 1. Develop, Format, and Document your Changes/Code
 2. (Optionally) Stage/Commit to your Branch
 3. (When Required) Update the relevant Test Conditions (`tests.sh`, etc.)
 4. Run `./tests/test.sh` from the project root directory