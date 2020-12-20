/*
 *  yaidsyara.h - YAIDS Yara Headers
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

#ifndef yaidsyara
#define yaidsyara

extern int yaidsyara_yara_initialize(void);
extern int yaidsyara_yara_finalize(void);
extern void yaidsyara_init(yaidsYaraScanner_ptr yara);
extern int yaidsyara_create_scanner(yaidsConfig config,
                                    yaidsYaraScanner_ptr yara);
extern int yaidsyara_create_scanners(yaidsConfig config,
                                     yaidsYaraScanner_ptr yaraScanners);
extern void yaidsyara_scan_packet(yaidsYaraScanner_ptr yaraScanner,
                                  yaidsPcapPacket_ptr packet,
                                  yaidsOutputDataQueue_ptr
                                  yaidsOutputQueue,
                                  yaidsYaraCallbackArgs_ptr callbackArgs,
                                  yaidsConfig_ptr config);
extern int yaidsyara_scanner_callback(YR_SCAN_CONTEXT * scanContext,
                                      int status, void *rule, void *args);
extern char *yaidsyara_scanner_callback_get_match_meta(YR_SCAN_CONTEXT *
                                                       scanContext,
                                                       YR_RULE * yaraRule);
extern char *yaidsyara_scanner_callback_get_match_string(YR_SCAN_CONTEXT *
                                                         scanContext,
                                                         YR_RULE *
                                                         yaraRule);

#endif
