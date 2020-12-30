/*
 *  yaidsio.c - YAIDS Input/Output Source Code
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
#include <time.h>
#include <yaids.h>
#include <yaidstypes.h>
#include <yaidsconf.h>
#include <yaidsio.h>
#include <yaidspcap.h>
#include <yaidsyara.h>
#include <yaidsthread.h>
#include <stdarg.h>

extern void yaidsio_print_debug_line(const char *format, ...)
{
    int status;
    char line[BUFSIZ];
    va_list args;

    va_start(args, format);
    status = vsnprintf(line, sizeof(line), format, args);
    va_end(args);

    if ((status > YAIDS_SUCCESS) && (global_yaidsRunning)) {
        fprintf(stderr, "[DEBUG]\t\t%s\n", line);
    }
}

extern void yaidsio_print_error_line(const char *format, ...)
{
    int status;
    char line[BUFSIZ];
    va_list args;

    va_start(args, format);
    status = vsnprintf(line, sizeof(line), format, args);
    va_end(args);

    if (status > YAIDS_SUCCESS) {
        fprintf(stderr, "[ERROR]\t\t%s\n", line);
    }
}

extern void yaidsio_print_std_line(const char *format, ...)
{
    int status;
    char line[BUFSIZ];
    va_list args;

    va_start(args, format);
    status = vsnprintf(line, sizeof(line), format, args);
    va_end(args);

    if (status > YAIDS_SUCCESS) {
        fprintf(stdout, "%s\n", line);
    }
}

extern void yaidsio_print_std_string(const char *format, ...)
{
    int status;
    char line[BUFSIZ];
    va_list args;

    va_start(args, format);
    status = vsnprintf(line, sizeof(line), format, args);
    va_end(args);

    if (status > YAIDS_SUCCESS) {
        fprintf(stdout, "%s", line);
    }
}

extern void yaidsio_print_horizontal_line(int chars)
{
    yaidsio_print_std_string("\x1b(0");
    for (int idx = 0; idx <= chars; idx++)
        yaidsio_print_std_string("\x71");
    yaidsio_print_std_string("\x1b(B\n");
}

extern void yaidsio_print_header(void)
{
    yaidsio_print_std_line("%s -- %s", PROGRAM_NAME, PROGRAM_VERSION);
    yaidsio_print_std_line("\t%s", PROGRAM_SUBLINE);
    yaidsio_print_std_line("\t%s", PROGRAM_DESCRIPTION);
    yaidsio_print_std_line("\t%s", COPYRIGHT);
    yaidsio_print_horizontal_line(120);
}

extern void yaidsio_print_arg_line(char *opt, char *type, char *desc)
{
    yaidsio_print_std_line("\t\t-%-*s%-*s%-s", 5, opt, 20, type, desc);
}

extern void yaidsio_help(char *exe)
{
    yaidsio_print_std_line("%s -- %s", PROGRAM_NAME, PROGRAM_VERSION);
    yaidsio_print_std_line("\t%s", PROGRAM_SUBLINE);
    yaidsio_print_std_line("\t%s", PROGRAM_DESCRIPTION);
    yaidsio_print_std_line("\t%s", COPYRIGHT);
    yaidsio_print_horizontal_line(120);
    yaidsio_print_std_line("Usage:");
    yaidsio_print_std_line("\t%s", exe);
    yaidsio_print_arg_line("i", "<DEVICE>",
                           "Interface: The libpcap Interface Device name (-i or -r is required)");
    yaidsio_print_arg_line("r", "<FILE>",
                           "Read: PCAP Input File (-i or -r is required)");
    yaidsio_print_arg_line("y", "<FILE>",
                           "Rules: Yara Rules File, compiled (required)");
    yaidsio_print_arg_line("n", "<NAME>",
                           "Prefix Name: Output files, prefix (optional, defaults to epoch)");
    yaidsio_print_arg_line("w", "<PATH>",
                           "Output Path: Output path (optional, defaults to current working directory)");
    yaidsio_print_arg_line("t", "<INT>",
                           "Threads: Number of Yara Threads (optional, defaults to 2 + 4 x CPU cores)");
    yaidsio_print_arg_line("l", "<INT>",
                           "Timelimit: Number of seconds to run, before exiting (optional, defaults to 0 - run until finished or interrupted)");
    yaidsio_print_arg_line("s", "",
                           "Silent Mode: Write output files, but don't output alerts to STDOUT (optional, incompatible with Output Only Mode)");
    yaidsio_print_arg_line("o", "",
                           "Output Only Mode: Output alerts to STDOUT only, does not write to files (optional, incompatible with Silent Mode)");
    yaidsio_print_arg_line("x", "",
                           "Flush Mode: Prevents buffering of file output (optional)");
    yaidsio_print_arg_line("a", "",
                           "Fast Alert Mode: Skip parsing packet headers for alerts (optional)");
    yaidsio_print_arg_line("d", "",
                           "Debug Mode: Verbose output (optional)");
    yaidsio_print_arg_line("v", "", "Version: Show Version");
    yaidsio_print_arg_line("h", "", "Help: Show Help (this list)");
}

extern void yaidsio_version(void)
{
    yaidsio_print_std_line("%s -- %s", PROGRAM_NAME, PROGRAM_VERSION);
}

extern yaidsConfig yaidsio_getopts(int argc, char **argv)
{
    yaidsConfig config = yaidsconf_init();

    int argopts;
    int optidx;

    opterr = 0;

    while ((argopts = getopt(argc, argv, "soxahdvi:r:y:n:w:t:l:")) != -1)
        switch (argopts) {
            case 'i':
                config.pcapDevice = optarg;
                break;
            case 'r':
                config.pcapInputFile = optarg;
                config.read_pcap_file = 1;
                break;
            case 'y':
                config.yaraRulesFile = optarg;
                break;
            case 'n':
                config.outputPrefix = optarg;
                break;
            case 'w':
                config.outputPath = optarg;
                break;
            case 't':
                config.threads = atoi(optarg);
                break;
            case 'l':
                config.timelimit = atoi(optarg);
                break;
            case 's':
                config.silent_mode = 1;
                break;
            case 'o':
                config.output_mode = 1;
                break;
            case 'x':
                config.flush_mode = 1;
                break;
            case 'a':
                config.fast_alert_mode = 1;
                break;
            case 'd':
                config.debug++;
                break;
            case 'v':
                yaidsio_version();
                config.status = YAIDS_NO_ACTION;
                return config;
            case 'h':
                yaidsio_help(argv[0]);
                config.status = YAIDS_NO_ACTION;
                return config;
            case '?':
                yaidsio_help(argv[0]);
                config.status = YAIDS_INVALID_ARGUMENTS;
                return config;
            default:
                abort();
        }

    for (optidx = optind; optidx < argc; optidx++) {
        yaidsio_help(argv[0]);
        config.status = YAIDS_INVALID_ARGUMENTS;
        return config;
    }

    config.status = YAIDS_PENDING_CONFIG;

    return config;
}

extern void yaidsio_print_config_debug(yaidsConfig_ptr config)
{
    yaidsio_print_debug_line("Configuration:");
    yaidsio_print_debug_line("\t pcapDevice: %s", config->pcapDevice);
    yaidsio_print_debug_line("\t yaraRulesFile: %s",
                             config->yaraRulesFile);
    yaidsio_print_debug_line("\t outputPrefix: %s", config->outputPrefix);
    yaidsio_print_debug_line("\t outputPath: %s", config->outputPath);
    yaidsio_print_debug_line("\t pcapInputFile: %s",
                             config->pcapInputFile);
    yaidsio_print_debug_line("\t outputAlertFile: %s",
                             config->outputAlertFile);
    yaidsio_print_debug_line("\t outputPcapFile: %s",
                             config->outputPcapFile);
    yaidsio_print_debug_line("\t threads: %d", config->threads);
    yaidsio_print_debug_line("\t timelimit: %d", config->timelimit);
    yaidsio_print_debug_line("\t read_pcap_file: %d",
                             config->read_pcap_file);
    yaidsio_print_debug_line("\t silent_mode: %d", config->silent_mode);
    yaidsio_print_debug_line("\t output_mode: %d", config->output_mode);
    yaidsio_print_debug_line("\t flush_mode: %d", config->flush_mode);
    yaidsio_print_debug_line("\t debug: %d", config->debug);
    yaidsio_print_debug_line("\t status: %d", config->status);
}

extern void yaidsio_exit_error(int errorCode)
{
    switch (errorCode) {
        case YAIDS_ERROR:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. YAIDS is exiting.");
            break;
        case YAIDS_MISSING_ARGUMENTS:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("You are missing require arguments. Check your input and try again. YAIDS is exiting.");
            break;
        case YAIDS_INVALID_ARGUMENTS:
            yaidsio_print_horizontal_line(120);
            yaidsio_print_error_line
                ("You included invalid arguments. Check your input and try again. YAIDS is exiting.");
            break;
        case YAIDS_INVALID_MODE:
            yaidsio_print_horizontal_line(120);
            yaidsio_print_error_line
                ("The Mode(s) selected are invalid. Check your input and try again. YAIDS is exiting.");
            break;
        case YAIDS_PERMISSION_DENIED:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. Permissions Denied. YAIDS is exiting.");
            break;
        case YAIDS_FILE_DOES_NOT_EXIST:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. One of the specified files does not exist. YAIDS is exiting.");
            break;
        case YAIDS_THREAD_ERROR:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. Threads failed to start. YAIDS is exiting.");
            break;
        case YAIDS_PCAP_ERROR:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. PCAP encountered an error. YAIDS is exiting.");
            break;
        case YAIDS_PCAP_DEVICE_DOES_NOT_EXIST:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. The network interface does not exist. YAIDS is exiting.");
            break;
        case YAIDS_YARA_ERROR:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. Yara encountered an error. YAIDS is exiting.");
            break;
        case YAIDS_NO_ACTION:
            exit(0);
            break;
        case YAIDS_COMPLETE:
            yaidsio_print_horizontal_line(120);
            yaidsio_print_std_line("Done. YAIDS is exiting.");
            exit(0);
            break;
        default:
            yaidsio_print_header();
            yaidsio_print_error_line
                ("An error has occured. YAIDS is exiting.");
            break;
    }

    exit(errorCode);
}

extern void yaidsio_print_started(void)
{
    yaidsio_print_header();
    yaidsio_print_std_line("%s\n", "Started.");
}

extern void yaidsio_print_exiting(void)
{
    printf("\r");
    yaidsio_print_horizontal_line(120);
    yaidsio_print_std_line("%s\n", "[SIGINT] Exiting at user request...");
}

extern void yaidsio_print_alert(char *alert)
{
    yaidsio_print_std_line("%s", alert);
}

extern void yaidsio_write_alert(FILE * alertFileHandle, char *alert)
{
    fwrite(alert, strlen(alert), 1, alertFileHandle);
    fwrite("\n", 1, sizeof(char), alertFileHandle);
}

extern void yaidsio_write_pcap(FILE * pcapFileHandle,
                               yaidsPcapPacket_ptr packet)
{
    if (pcapFileHandle)
        yaidspcap_write_packet(pcapFileHandle, packet);
}
