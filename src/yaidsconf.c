/*
 *  yaidsconf.c - YAIDS Configuration Source Code
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
#include <sys/sysinfo.h>

extern yaidsConfig yaidsconf_init(void)
{
    yaidsConfig config;

    config.pcapDevice = NULL;
    config.yaraRulesFile = NULL;
    config.outputPrefix = NULL;
    config.outputPath = NULL;
    config.pcapInputFile = NULL;
    config.outputAlertFile = NULL;
    config.outputPcapFile = NULL;
    config.threads = yaidsConfig_get_default_thread_count();
    config.timelimit = 0;
    config.read_pcap_file = 0;
    config.silent_mode = 0;
    config.output_mode = 0;
    config.flush_mode = 0;
    config.fast_alert_mode = 0;
    config.debug = 0;
    config.status = 1;

    return config;
}

extern int yaidsConfig_get_default_thread_count(void)
{
    return get_nprocs() * 4;
}
