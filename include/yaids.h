/*
 *  yaids.h - Main YAIDS Headers
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

#ifndef yaids
#define yaids

#include <stdbool.h>

#define YAIDS_SUCCESS                       0
#define YAIDS_ERROR                         1
#define YAIDS_MISSING_ARGUMENTS             2
#define YAIDS_INVALID_ARGUMENTS             3
#define YAIDS_INVALID_MODE                  4
#define YAIDS_NO_ACTION                     10
#define YAIDS_PERMISSION_DENIED             20
#define YAIDS_FILE_DOES_NOT_EXIST           21
#define YAIDS_THREAD_ERROR                  30
#define YAIDS_PCAP_ERROR                    40
#define YAIDS_PCAP_DEVICE_DOES_NOT_EXIST    41
#define YAIDS_YARA_ERROR                    50
#define YAIDS_YARA_MATCH                    100
#define YAIDS_YARA_NOMATCH                  101
#define YAIDS_COMPLETE                      999

extern const char *PROGRAM_NAME;
extern const char *COPYRIGHT;
extern const char *PROGRAM_SUBLINE;
extern const char *PROGRAM_DESCRIPTION;
extern const char *PROGRAM_VERSION;

extern _Bool global_yaidsRunning;

extern void yaids_signal(int signalValue);
extern void yaids_finish(void);
extern _Bool verify_status(int statusCode);
extern int main(int argc, char **argv);

#endif
