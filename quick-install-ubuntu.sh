#!/bin/bash

##
 #  quick-install-ubuntu.sh - YAIDS Installer for Ubuntu
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

# Create an Installer Directory
mkdir ./yaids_installer
cd ./yaids_installer

##################################################
#               Install Dependenices             #
##################################################
    sudo apt install build-essential \
                     automake \
                     libtool \
                     make \
                     gcc \
                     pkg-config \
                     flex \
                     bison \
                     git
    sudo apt install libjansson-dev \
                     libssl-dev \
                     libmagic-dev \
                     protobuf-compiler \
                     libprotobuf-dev \
                     libprotoc-dev \
                     libprotobuf-c-dev \
                     google-perftools \
                     libgoogle-perftools-dev
    sudo apt install libbluetooth-dev \
                     libdbus-1-dev

##################################################
#               Install libpcap 1.9.1            #
##################################################
    wget https://www.tcpdump.org/release/libpcap-1.9.1.tar.gz
    tar -zxvf libpcap-1.9.1.tar.gz
    cd ./libpcap-1.9.1
    ./configure --enable-largefile \
                --enable-protochain \
                --enable-packet-ring \
                --enable-ipv6 \
                --enable-remote \
                --enable-optimizer-dbg \
                --enable-yydebug \
                --enable-universal \
                --enable-usb \
                --enable-netmap \
                --enable-bluetooth \
                --enable-dbus \
                --enable-rdma \
                --with-gcc
    make
    sudo make install
    cd ../

##################################################
#               Install libyara 4.0.2            #
##################################################
    wget https://github.com/VirusTotal/yara/archive/v4.0.2.tar.gz
    tar -zxvf v4.0.2.tar.gz
    cd ./yara-4.0.2
    ./bootstrap.sh
    ./configure --enable-largefile \
                --enable-cuckoo \
                --enable-magic \
                --enable-dotnet \
                --enable-macho \
                --enable-dex \
                --enable-debug-dex \
                --enable-pb-tests \
                --enable-optimization \
                --with-cpu-profiler \
                --with-crypto
    make
    sudo make install
    echo "/usr/local/lib" | sudo tee -a /etc/ld.so.conf > /dev/null
    sudo ldconfig
    cd ../

##################################################
#               Install YAIDS                    #
##################################################
    git clone https://github.com/wrayjustin/yaids.git
    cd ./yaids
    ./build.sh
    cd ../../
    
##################################################
#               VErify YAIDS                     #
##################################################
    yaids -v
    STATUS=$?
    if [ "$STATUS" == 0 ]; then
        clear
        yaids -h
        echo "---------"
        echo
        echo "Installation Complete"
        echo "  You can now delete the yaids_installer directory and this installer script."
        echo
    else
        echo "---------"
        echo "Installation Failed."
    fi
    
#END
