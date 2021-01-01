#!/bin/bash

##
 #  tests/tests.sh - Test Suite for YAIDS
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

SCRIPT_PATH="$(realpath "$0")"
DIR_PATH="$(dirname "$SCRIPT_PATH")"

TESTS_RUN=0
TESTS_PASSED=0
TESTS_FAILED=0

function run_test_output
{
    local TEST_NAME="$1"
    local INPUT_FILE="$2"
    local COMPILED_RULES="$3"
    local TEST_MATCH="$4"
    local EXPECTED_RESULTS="$5"
    local ADDITIONAL_OPTIONS="$6"

    local RESULTS
    # shellcheck disable=SC2086
    RESULTS="$(yaids $ADDITIONAL_OPTIONS -r "$DIR_PATH/pcaps/$INPUT_FILE" -y "$DIR_PATH//$COMPILED_RULES" -o 2> /dev/null | grep -c "$TEST_MATCH")"

    if [ "$RESULTS" == "$EXPECTED_RESULTS" ]; then
        return 0
    fi

    return 1
}

function run_test_alert_file
{
    local TEST_NAME="$1"
    local INPUT_FILE="$2"
    local COMPILED_RULES="$3"
    local TEST_MATCH="$4"
    local EXPECTED_RESULTS="$5"
    local ADDITIONAL_OPTIONS="$6"

    # shellcheck disable=SC2086
    yaids $ADDITIONAL_OPTIONS -r "$DIR_PATH/pcaps/$INPUT_FILE" -y "$DIR_PATH/$COMPILED_RULES" -w "$DIR_PATH" -n "$TEST_NAME" -s 1> /dev/null 2> /dev/null

    local RESULTS
    RESULTS="$(grep -c "$TEST_MATCH" "$DIR_PATH/yaids.$TEST_NAME.alerts" 2> /dev/null)"

    rm -rf "$DIR_PATH/yaids.$TEST_NAME.alerts"
    rm -rf "$DIR_PATH/yaids.$TEST_NAME.pcap"

    if [ "$RESULTS" == "$EXPECTED_RESULTS" ]; then
        return 0
    fi

    return 1
}

function run_test_pcap_file
{
    local TEST_NAME="$1"
    local INPUT_FILE="$2"
    local COMPILED_RULES="$3"
    local TEST_MATCH="$4"
    local EXPECTED_RESULTS="$5"
    local ADDITIONAL_OPTIONS="$6"

    yaids -r "$DIR_PATH/pcaps/$INPUT_FILE" -y "$DIR_PATH/$COMPILED_RULES" -w "$DIR_PATH" -n "$TEST_NAME" -s 1> /dev/null 2> /dev/null

    local RESULTS
    # shellcheck disable=SC2086
    RESULTS="$(yaids $ADDITIONAL_OPTIONS -r "$DIR_PATH/yaids.$TEST_NAME.pcap" -y "$DIR_PATH/$COMPILED_RULES" -o 2> /dev/null | grep -c "$TEST_MATCH")"

    rm -rf "$DIR_PATH/yaids.$TEST_NAME.alerts"
    rm -rf "$DIR_PATH/yaids.$TEST_NAME.pcap"

    if [ "$RESULTS" == "$EXPECTED_RESULTS" ]; then
        return 0
    fi

    return 1
}

function run_test
{
    local TEST_NAME="$1"
    local TEST_FUNCTION="$2"
    local TEST_DESC="$3"
    local INPUT_FILE="$4"
    local COMPILED_RULES="$5"
    local TEST_MATCH="$6"
    local EXPECTED_RESULTS="$7"
    local ADDITIONAL_OPTIONS="$8"

    ((++TESTS_RUN))
    printf "[%-20s%-20s#%-2s]%40s" "$TEST_NAME" "$TEST_DESC" "$TEST_COUNT" ""
    if $TEST_FUNCTION "$TEST_NAME" "$INPUT_FILE" "$COMPILED_RULES" "$TEST_MATCH" "$EXPECTED_RESULTS" "$ADDITIONAL_OPTIONS"; then
        ((++TESTS_PASSED))
        printf "+ \e[38;5;82mPASSED\e[0m\n"
    else
        ((++TESTS_FAILED))
        printf "! \e[38;5;198mFAILED\e[0m\n"
    fi
}

function run_tests
{
    local INPUT_FILE="$1"
    local RULE_FILE="$2"
    local TEST_NAME="$3"
    local TEST_MATCH="$4"
    local EXPECTED_RESULTS="$5"
    local ADDITIONAL_OPTIONS="$6"

    local COMPILED_RULES

    if [[ "$RULE_FILE" =~ Combined ]]; then
        COMPILED_RULES="$(echo "$RULE_FILE" | cut -d ' '  -f 3)"
        local RULES_INPUT="$(echo "$RULE_FILE" | sed -e 's/'"$COMPILED_RULES"'//g' -e 's/ $//g' | tr ' ' '\n' | awk '{ print "'"$DIR_PATH"'/" $0 }' | xargs)"
        # shellcheck disable=SC2086
        yaidsc $RULES_INPUT "$DIR_PATH"/"$COMPILED_RULES"

    else
        COMPILED_RULES="$RULE_FILE"c
        if [ ! -f "$DIR_PATH/$COMPILED_RULES" ]; then
            yaidsc "$DIR_PATH"/"$RULE_FILE" "$DIR_PATH"/"$COMPILED_RULES"
        fi
    fi

    for TEST_COUNT in {01..03}; do
        run_test "$TEST_NAME" "run_test_output" "Output Test" "$INPUT_FILE" "$COMPILED_RULES" "$TEST_MATCH" "$EXPECTED_RESULTS" "$ADDITIONAL_OPTIONS"
        run_test "$TEST_NAME" "run_test_alert_file" "Alert File Test" "$INPUT_FILE" "$COMPILED_RULES" "$TEST_MATCH" "$EXPECTED_RESULTS" "$ADDITIONAL_OPTIONS"
        run_test "$TEST_NAME" "run_test_pcap_file" "PCAP File Test" "$INPUT_FILE" "$COMPILED_RULES" "$TEST_MATCH" "$EXPECTED_RESULTS" "$ADDITIONAL_OPTIONS"
    done
}

function cleanup_tests
{
    rm -rf "$DIR_PATH"/*.yarc
    rm -rf "$DIR_PATH"/yaids.*.alerts
    rm -rf "$DIR_PATH"/yaids.*.pcap
}

function finalize_tests
{
    echo "---------"
    echo "Results: $TESTS_PASSED / $TESTS_RUN PASSED"
    echo "------------------"

    if [ $TESTS_PASSED == $TESTS_RUN ]; then
        echo -e "\e[38;5;82mALL\e[0m TESTS PASSED"
        exit 0
    else
        echo -e "\e[38;5;198m$TESTS_FAILED\e[0m TESTS FAILED"
        exit 1
    fi
}

run_tests "test.pcap" "test_A.yar" "test_A_01_PCAP" "test_A_01" "21"
run_tests "test.pcapng" "test_A.yar" "test_A_01_NG" "test_A_01" "21"
run_tests "test.pcap" "test_A.yar" "test_A_02_PCAP" "test_A_02" "1"
run_tests "test.pcapng" "test_A.yar" "test_A_02_NG" "test_A_02" "1"
run_tests "test.pcap" "test_A.yar" "test_A_03_PCAP" "test_A_03" "3"
run_tests "test.pcapng" "test_A.yar" "test_A_03_NG" "test_A_03" "3"
run_tests "test.pcap" "test_A.yar" "test_A_04_PCAP" "test_A_04" "3"
run_tests "test.pcapng" "test_A.yar" "test_A_04_NG" "test_A_04" "3"
run_tests "test.pcap" "test_A.yar" "test_A_05_PCAP" "test_A_05" "2"
run_tests "test.pcapng" "test_A.yar" "test_A_05_NG" "test_A_05" "2"
run_tests "test.pcap" "test_A.yar" "test_A_06_PCAP" "test_A_06" "12"
run_tests "test.pcapng" "test_A.yar" "test_A_06_NG" "test_A_06" "12"
run_tests "test.pcap" "test_B.yar" "test_B_01_PCAP" "test_B_01" "1"
run_tests "test.pcapng" "test_B.yar" "test_B_01_NG" "test_B_01" "1"
run_tests "test.pcap" "test_B.yar" "test_B_02_PCAP" "test_B_02" "1"
run_tests "test.pcapng" "test_B.yar" "test_B_02_NG" "test_B_02" "1"
run_tests "test.pcap" "test_B.yar" "test_B_03_PCAP" "test_B_03" "2"
run_tests "test.pcapng" "test_B.yar" "test_B_03_NG" "test_B_03" "2"
run_tests "test.pcap" "test_C.yar" "test_C_01_PCAP" "test_C_01" "2"
run_tests "test.pcapng" "test_C.yar" "test_C_01_NG" "test_C_01" "2"
run_tests "test.pcap" "test_D.yar" "test_D_01_PCAP" "test_D_01" "466"
run_tests "test.pcapng" "test_D.yar" "test_D_01_NG" "test_D_01" "466"
run_tests "test.pcap" "test_D.yar" "test_D_02_PCAP" "test_D_02" "466"
run_tests "test.pcapng" "test_D.yar" "test_D_02_NG" "test_D_02" "466"
run_tests "test.pcap" "test_D.yar" "test_D_03_PCAP" "test_D_03" "462"
run_tests "test.pcapng" "test_D.yar" "test_D_03_NG" "test_D_03" "462"
run_tests "test.pcap" "test_D.yar" "test_D_04_PCAP" "test_D_04" "182"
run_tests "test.pcapng" "test_D.yar" "test_D_04_NG" "test_D_04" "182"
run_tests "test.pcap" "test_D.yar" "test_D_05_PCAP" "test_D_05" "38"
run_tests "test.pcapng" "test_D.yar" "test_D_05_NG" "test_D_05" "38"
run_tests "test.pcap" "test_D.yar" "test_D_06_PCAP" "test_D_06" "38"
run_tests "test.pcapng" "test_D.yar" "test_D_06_NG" "test_D_06" "38"
run_tests "test.pcap" "test_D.yar" "test_D_07_PCAP" "test_D_07" "38"
run_tests "test.pcapng" "test_D.yar" "test_D_07_NG" "test_D_07" "38"
run_tests "test.pcap" "test_D.yar" "test_D_08_PCAP" "test_D_08" "38"
run_tests "test.pcapng" "test_D.yar" "test_D_08_NG" "test_D_08" "38"
run_tests "test.pcap" "test_D.yar" "test_D_09_PCAP" "test_D_09" "25"
run_tests "test.pcapng" "test_D.yar" "test_D_09_NG" "test_D_09" "25"
run_tests "test.pcap" "test_A.yar test_B.yar test_E_Combined.yarc" "test_E_PCAP" "test_" "46"
run_tests "test.pcapng" "test_A.yar test_B.yar test_E_Combined.yarc" "test_E_NG" "test_" "46"
run_tests "test.pcap" "test_F.yar" "test_F_PCAP" "test_F_01" "2" "-f $DIR_PATH/test_F.bpf"
run_tests "test.pcapng" "test_F.yar" "test_F_PNG" "test_F_01" "2" "-f $DIR_PATH/test_F.bpf"
cleanup_tests
finalize_tests
