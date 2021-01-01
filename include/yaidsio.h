/*
 *  yaidsio.h - YAIDS Input/Output Headers
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

#ifndef yaidsio
#define yaidsio

extern void yaidsio_print_debug_line(const char *format, ...);
extern void yaidsio_print_error_line(const char *format, ...);
extern void yaidsio_print_std_line(const char *format, ...);
extern void yaidsio_print_horizontal_line(int chars);
extern void yaidsio_print_header(void);
extern void yaidsio_print_arg_line(char *opt, char *type, char *desc);
extern void yaidsio_help(char *exe);
extern void yaidsio_version(void);
extern yaidsConfig yaidsio_getopts(int argc, char **argv);
extern void yaidsio_print_config_debug(yaidsConfig_ptr config);
extern void yaidsio_exit_error(int errorCode);
extern void yaidsio_print_started(void);
extern void yaidsio_print_exiting(void);
extern void yaidsio_print_alert(char *alert);
extern void yaidsio_write_alert(FILE * alertFileHandle, char *alert);
extern void yaidsio_write_pcap(FILE * pcapFileHandle,
                               yaidsPcapPacket_ptr packet);
extern char * yaidsio_read_file(char* fileName);

#endif
