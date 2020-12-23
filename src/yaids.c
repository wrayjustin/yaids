/*
 *  yaids.c - YAIDS Main Thread and Process Source Code
 *
 *  This file is a part of or derived from YAIDS: https://github.com/wrayjustin/yaids
 *
 *  COPYRIGHT (C) 2020 Justin M. Wray - wray.justin@gmail.com / https://www.justinwray.com
 *  ALL RIGHTS RESERVED
 *  
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *  
 *  1. Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *  
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation and/or
 *  other materials provided with the distribution.
 *  
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *  may be used to endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <config.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <yaids.h>
#include <yaidstypes.h>
#include <yaidsconf.h>
#include <yaidsio.h>
#include <yaidspcap.h>
#include <yaidsyara.h>
#include <yaidsthread.h>
#include <yara.h>
#include <signal.h>

const char *PROGRAM_NAME = "YAIDS";
const char *COPYRIGHT = 
    "COPYRIGHT (C) Justin M. Wray | Licensed: BSD 3-Clause";
const char *PROGRAM_SUBLINE =
    "Yara as an Intrusion Detection System / Yet Another Intrusion Detection System";
const char *PROGRAM_DESCRIPTION =
    "An Intrusion Detection System (IDS), utilizing Yara rules, and multi-threading";
const char *PROGRAM_VERSION = PACKAGE_VERSION;

bool global_yaidsRunning = true;

extern void yaids_signal(int signalValue)
{
    if (signalValue == 2) {
        yaidsio_print_exiting();
        global_yaidsRunning = false;
    } else {
        signal(signalValue, SIG_DFL);
    }
}

extern _Bool verify_status(int statusCode)
{
    if (statusCode != YAIDS_SUCCESS) {
        yaidsio_exit_error(statusCode);
        return false;
    }

    return true;
}

extern int main(int argc, char **argv)
{
    signal(SIGINT, yaids_signal);
    bool *yaidsRunning;
    yaidsRunning = &global_yaidsRunning;

    yaidsConfig config = yaidsio_getopts(argc, argv);
    yaidsconf_config_init(&config, argv[0], argc);
    verify_status(config.status);

    if (config.debug) yaidsio_print_config_debug(&config);

    yaidsPcapHandle pcapHandle;
    verify_status(yaidspcap_create_handle
                  (&config, (yaidsPcapHandle_ptr) & pcapHandle));

    verify_status(yaidsyara_yara_initialize());

    yaidsYaraScanner yaraScanners[config.threads];
    verify_status(yaidsyara_create_scanners(&config, yaraScanners));

    yaidsThreadList_ptr threadList = yaidsthread_new_threadlist(&config);
    yaidsInputDataQueue_ptr yaidsInputQueue =
        yaidsthread_new_input_queue();
    yaidsOutputDataQueue_ptr yaidsOutputQueue =
        yaidsthread_new_output_queue();
    verify_status(yaidsthread_run_threads
                  (yaidsRunning, config, threadList, yaidsInputQueue,
                   yaidsOutputQueue, (yaidsPcapHandle_ptr) & pcapHandle,
                   (yaidsYaraScanner_ptr) & yaraScanners));

    verify_status(yaidsyara_yara_finalize());

    return 0;
}
