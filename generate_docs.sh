#!/bin/bash

##
 #  generate_docs.sh - Automated Documentation Generator for YAIDS
 #
 #  This file is a part of or derived from YAIDS: https://github.com/wrayjustin/yaids
 #
 #  COPYRIGHT (C) 2020 Justin M. Wray - wray.justin@gmail.com / https://www.justinwray.com
 #  ALL RIGHTS RESERVED
 #
 #  Redistribution and use in source and binary forms, with or without modification,
 #  are permitted provided that the following conditions are met:
 #
 #  1. Redistributions of source code must retain the above copyright notice, this
 #  list of conditions and the following disclaimer.
 #
 #  2. Redistributions in binary form must reproduce the above copyright notice,
 #  this list of conditions and the following disclaimer in the documentation and/or
 #  other materials provided with the distribution.
 #
 #  3. Neither the name of the copyright holder nor the names of its contributors
 #  may be used to endorse or promote products derived from this software without
 #  specific prior written permission.
 #
 #  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 #  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 #  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 #  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 #  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 #  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 #  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 #  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 #  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 #  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 #
##

# Check for Required Dependencies
function check_dependencies
{
    command -v doxygen || return 1
    command -v pandoc || return 1
}

# Provide Missing Dependency Error
function missing_dependencies
{
    echo "---------"
    echo "Documentation Generated Failed -- MISSING DEPENDENCIES."
    echo
    echo "Make sure you have 'doxygen' and 'pandoc' installed."
    exit 1
}

# Provide Error if Doc Generation Fails
function doc_generation_failed
{
    echo "---------"
    echo "Documentation Generated Failed."
    exit 1
}

# Create Missing Documentation Directories
function doc_directory_setup
{
    mkdir -p docs/installation/ || return 1
    mkdir -p docs/usage/ || return 1
    mkdir -p docs/technical/ || return 1
    mkdir -p docs/code/ || return 1
    mkdir -p docs/code/headers/ || return 1
    mkdir -p docs/code/headers/definitions/ || return 1
    mkdir -p docs/code/source/ || return 1
    mkdir -p docs/images/ || return 1
}

# Remove Prevvious Files
function doc_cleanup
{
    cd docs/ || return 1
    make clean || return 1
    make clean-doxygen || return 1
    make clean-doxygen-built || return 1
    make clean-markdown || return 1
    cd ../ || return 1
}

# Remove Tempoary Files
function prepare_for_repo
{
    cd docs/ || return 1
    make clean-local || return 1
    rm -rf man.source || return 1
    cd ../ || return 1
}

# Generate Automated Code Documentation with Doxygen
function process_doxygen
{
    doxygen docs/headers.Doxyfile || return 1 # Doxygen: Code Headers
    doxygen docs/source.Doxyfile || return 1 # Doxygen: Code Source
}

# Create a New Markdown File
function create_markdown
{
    FILE="$1"
    TITLE="$2"
    PERMALINK="$3"
    SORT="$4"
    NOTICE_TYPE="$5"
    NOTICE_TEXT="$6"

    echo '---' > "$FILE" || return 1
    echo "title: $TITLE" >> "$FILE" || return 1
    echo "permalink: $PERMALINK" >> "$FILE" || return 1

    if [ -n "$SORT" ]; then
        echo "sort: $SORT" >> "$FILE" || return 1
    fi

    echo '---' >> "$FILE" || return 1
    echo '![YAIDS](/yaids.png)' >> "$FILE" || return 1
    echo "# $TITLE" >> "$FILE" || return 1
    echo  >> "$FILE" || return 1

    if [ -n "$NOTICE_TYPE" ] && [ -n "$NOTICE_TEXT" ]; then
        echo '```' "$NOTICE_TYPE" >> "$FILE" || return 1
        echo "$NOTICE_TEXT" >> "$FILE" || return 1
        echo '```' >> "$FILE" || return 1
    fi

    echo "$FILE" >> docs/man.source
}

# Create Markdown and make it an Index
function create_markdown_index
{
    FILE="$1"
    create_markdown "$@" || return 1
    echo '{% include list.liquid all=true %}' >> "$FILE" || return 1
}

# Create Markdown and make it a ChangeLog
function create_markdown_changelog
{
    FILE="$1"
    create_markdown "$@" || return 1
    git log --pretty=format:'## %s - %cd%n%b%n[%h](https://github.com/wrayjustin/yaids/commit/%H) by [%aN](https://github.com/%aN)%n' >> "$FILE"
}

# Create Markdown and fill with first README.md section
function create_markdown_from_readme_top
{
    FILE="$1"
    create_markdown "$@" || return 1
    FIRST_SECTION=$(grep '## ' README.md | head -n 1) || return 1
    sed "/$FIRST_SECTION/q" README.md | head -n -1 | tail -n +2 >> "$FILE" || return 1
}

# Create Markdown and fill with last README.md section
function create_markdown_from_readme_bottom
{
    FILE="$1"
    create_markdown "$@" || return 1
    LAST_SECTION=$(grep '## ' README.md | tail -n 1) || return 1
    awk "/^$LAST_SECTION/,0" README.md | tail -n +2 >> "$FILE" || return 1
}

# Create Markdown and fill with specific section
function create_markdown_from_readme_section
{
    FILE="$1"
    TITLE="$2"
    MATCH="$7"

    if [ -z "$MATCH" ]; then
        MATCH="$TITLE"
    fi

    MATCH=$(echo "$MATCH" | sed -e 's/(/\\(/g' -e 's/)/\\)/g' -e 's/\//\\\//g') || return 1
    create_markdown "$@" || return 1
    awk "/^(###|##) $MATCH/{flag=1;next}/^(###|##)/{flag=0}flag" README.md | head -n -1 | sed -e 's/#\{1,\}/#/' >> "$FILE" || return 1
}

# Cleanup Autogenerated Markdown
function markdown_cleanup
{
    FILE="$1"

    REMOVELIST=(
        '\[Public Attributes\]'
        '\-members\.html'
        'graph_legend\.html'
        'dir.*\.html'
        'Go to the source code of this file'
        '\!\[YAIDS\](\/yaids\.png)')

    # shellcheck disable=SC2016
    REPLACELIST=(
        '/\.png/s/href=\"/href=\"\/images\//g'
        '/\.png/s/](/](\/images\//g'
        's/src=\"yaids\.png\"/src=\"\/yaids.png\"/g'
        '/_8h_source\.html/s/href=\"/href=\"\/code\/headers\//g'
        '/_8c_source\.html/s/href=\"/href=\"\/code\/source\//g'
        '/_8h\.html/s/href=\"/href=\"\/code\/headers\//g'
        '/_8c\.html/s/href=\"/href=\"\/code\/source\//g'
        '/__struct\.html/s/href=\"/href=\"\/code\/headers\/definitions\//g'
        's/_8h\.html//g'
        's/_8c\.html//g'
        's/_8h_source\.html//g'
        's/_8c_source\.html//g'
        's/__struct\.html/__struct/g'
        '$s/Generated by/Source Code Documentation Generated By \`doxygen\`<\/span>/')

    sed -i '$d' "$FILE"
    sed -i '$d' "$FILE"

    for REMOVELINE in "${REMOVELIST[@]}"; do
        sed "/$REMOVELINE/d" -i "$FILE" || return 1
    done || return 1

    for SED_CMD in "${REPLACELIST[@]}"; do
        sed -e "$SED_CMD" -i "$FILE" || return 1
    done || return 1
}

# Create Markdown and fill with Code Definitions
function generate_code_definition_docs
{
    # shellcheck disable=SC2010
    for definition in $(ls docs/_doxygen-headers/html/structyaids*.html | grep -v "\-members.html" | sed -e 's/docs\/_doxygen-headers\/html\///g' | sed -e 's/\.html//g'); do
        create_markdown "docs/code/headers/definitions/$definition.md" "$definition" "code/headers/definitions/$definition" || return 1 # Create Definition MD
        pandoc -s "docs/_doxygen-headers/html/$definition.html" -t markdown_strict >> "docs/code/headers/definitions/$definition.md" || return 1 # Convert Doxygen HTML and Append
        markdown_cleanup "docs/code/headers/definitions/$definition.md" || return 1 # Cleanup Doxygen/Pandoc MD
    done
}

# Create Markdown and fill with auto-generated Code Header Documentation
function generate_code_headers_docs
{
    # shellcheck disable=SC2012
    for header in $(ls include/*.h | sed -e 's/include\///' | sed -e 's/\.h//'); do
        create_markdown "docs/code/headers/$header.md" "$header" "code/headers/$header" || return 1 # Create Definition MD
        pandoc -s "docs/_doxygen-headers/html/""$header""_8h.html" -t markdown_strict >> "docs/code/headers/$header.md" || return 1 # Convert Doxygen HTML and Append
        markdown_cleanup "docs/code/headers/$header.md" || return 1 # Cleanup Doxygen/Pandoc MD
    done
}

# Create Markdown and fill with auto-generated Source Code Documentation
function generate_code_source_docs
{
    # shellcheck disable=SC2012
    for code in $(ls src/*.c | sed -e 's/src\///' | sed -e 's/\.c//'); do
        create_markdown "docs/code/source/$code.md" "$code" "code/source/$code" || return 1 # Create Definition MD
        pandoc -s "docs/_doxygen-source/html/""$code""_8c.html" -t markdown_strict >> "docs/code/source/$code.md" || return 1 # Convert Doxygen HTML and Append
        markdown_cleanup "docs/code/source/$code.md" || return 1 # Cleanup Doxygen/Pandoc MD
    done
}

# Copy Code Documentation Diagrams
function copy_code_images
{
    cp docs/_doxygen-headers/html/*yaids*.png docs/images/ || return 1
    cp docs/_doxygen-source/html/*yaids*.png docs/images/ || return 1
    rm docs/images/yaids.png || return 1
}

# Execute Document Generation
function generate_code_docs
{
    generate_code_definition_docs || return 1
    generate_code_headers_docs || return 1
    generate_code_source_docs || return 1
    copy_code_images || return 1
}

# Create a README for Docuumentation
function create_docs_readme
{
    create_markdown_from_readme_top 'docs/README.md' 'YAIDS' '/' '1' || return 1 # Home
    echo '## Documentation' >> docs/README.md || return 1
    echo '{% include list.liquid all=true %}' >> docs/README.md || return 1
}

# Generate Documentation Files
function generate_doc_files
{
    create_docs_readme || return 1 # Main Page (Home)
    create_markdown_index 'docs/installation/index.md' 'Installation' '/installation/' '2' || return 1 # Installation: Index
    create_markdown_index 'docs/usage/index.md' 'Usage' '/usage/' '3' || return 1 # Usage: Index
    create_markdown_index 'docs/technical/index.md' 'Technical Design' '/technical/' '4' || return 1 # Usage: Index
    create_markdown_index 'docs/code/index.md' 'Code' '/code/' '5' 'tip' \
        'The full source code can be viewed in the [yaids/main](https://github.com/wrayjustin/yaids) repository' || return 1 # Code: Index
    create_markdown_index 'docs/code/headers/index.md' 'Headers' '/code/headers/' '1' 'tip' \
        'The full source code can be viewed in the [yaids/main](https://github.com/wrayjustin/yaids) repository' || return 1 # Code: Headers Index
    create_markdown_index 'docs/code/headers/definitions/index.md' 'Data Definitions' '/code/headers/definitions/' '1' 'tip' \
        'The full source code can be viewed in the [yaids/main](https://github.com/wrayjustin/yaids) repository' || return 1 # Code: Headers Definitions Index
    create_markdown_index 'docs/code/source/index.md' 'Source' '/code/source/' '2' 'tip' \
        'The full source code can be viewed in the [yaids/main](https://github.com/wrayjustin/yaids) repository' || return 1 # Code: Source Index
    create_markdown_from_readme_section 'docs/installation/prerequisites.md' 'Prerequisites' '/installation/prerequisites' '1' || return 1 # Installation: Prerequisites
    create_markdown_from_readme_section 'docs/installation/ubuntu-quick.md' 'Ubuntu (Quick Install)' '/installation/ubuntu-quick' '2' \
        'tip' 'This is the recommended installation method if you are running Ubuntu' || return 1 # Installation: Ubuntu (Quick Install)
    # shellcheck disable=SC2016
    create_markdown_from_readme_section 'docs/installation/basic-install.md' 'Other Distributions (Basic Install)' '/installation/basic-install' '3' \
        'note' 'Most modern distributions should include the required dependencies, monitor the `./configure` output for any missing packages' || return 1 # Installation: Ubuntu (Quick Install)|| return 1 # Installation: Ubuntu (Quick Install)
    # shellcheck disable=SC2016
    create_markdown_from_readme_section 'docs/installation/dev-install.md' 'Manual/Development Installation' '/installation/dev-install' '4' \
        'note' 'Most modern distributions should include the required dependencies, monitor the `./configure` output for any missing packages' || return 1 # Installation: Manual/Development Installation
    # shellcheck disable=SC2016
    create_markdown_from_readme_section 'docs/installation/manual-install.md' 'Manual (Without AutoTools)' '/installation/manual-install' '5' \
        'warning' 'Most modern distributions should include the required dependencies, monitor the `./configure` output for any missing packages; Lack of optimization may impact the performace of `YAIDS`' || return 1 # Installation: Manual (Without AutoTools)
    create_markdown_from_readme_section 'docs/usage/options.md' 'Command Line Options' '/usage/options' '1' '' '' 'Options' || return 1 # Usage: Options
    create_markdown_from_readme_section 'docs/usage/examples.md' 'Examples' '/usage/examples' '2' || return 1 # Usage: Examples
    create_markdown_from_readme_section 'docs/usage/output.md' 'Output' '/usage/output' '3' || return 1 # Usage: Output
    create_markdown_from_readme_section 'docs/technical/dataflow.md' 'Dataflow' '/technical/dataflow' '1' '' '' 'Technical Details' || return 1 # Technical Design: Dataflow
    create_markdown_from_readme_section 'docs/technical/priority.md' 'Thread Priority' '/technical/priority' '2' '' '' 'Priority' || return 1 # Technical Design: Thread Priority
    create_markdown_from_readme_section 'docs/technical/queues.md' 'Data Queues' '/technical/queues' '3' || return 1 # Technical Design: Data Queues
    create_markdown_from_readme_section 'docs/technical/flowchart.md' 'Flowchart' '/technical/flowchart' '4' || return 1 # Technical Design: Flowchat
    create_markdown_changelog 'docs/changelog.md' 'ChangeLog' '/changelog/' '6' || return 1 # ChangeLog
    create_markdown_from_readme_bottom 'docs/license.md' 'License' '/license/' '7' || return 1 # License
    generate_code_docs || return 1 # Code (Doxygen Converted)
}

# Create MAN Page from generated Documentation
function create_man_page
{
    # shellcheck disable=SC2046
    pandoc -s README.md -t man -o docs/yaids.1 || return 1
    sed -e 's/\[IMAGE: .* (.*\.png)\]//g' -i docs/yaids.1 || return 1
    sed -e '/{% include list.liquid all=true %}/d' -i docs/yaids.1 || return 1
    sed -e '/\[IMAGE:  Build  /d' -i docs/yaids.1 || return 1
    rm -rf docs/man.sources || return 1
}

##################################################
#               Build Documentation              #
##################################################
check_dependencies || missing_dependencies
doc_directory_setup || doc_generation_failed
doc_cleanup || doc_generation_failed
process_doxygen || doc_generation_failed
generate_doc_files || doc_generation_failed
create_man_page || doc_generation_failed
prepare_for_repo || doc_generation_failed

# END

################################
#### LOCAL TESTING
#### Uncomment for Local Testing (Requires `jekyll`)
#cd ./docs || doc_generation_failed
#bundle exec jekyll serve -H 0.0.0.0 || doc_generation_failed
#### END OF LOCAL TESTING
################################
