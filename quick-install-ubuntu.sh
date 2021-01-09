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
function setup_installer
{
    mkdir ./yaids_installer || return 1
    cd ./yaids_installer || return 1
}

##################################################
#               Install Dependenices             #
##################################################
function install_dependenices
{
    sudo apt update
    sudo apt install --assume-yes \
                     build-essential \
                     automake \
                     libtool \
                     make \
                     gcc \
                     pkg-config \
                     flex \
                     bison \
                     git || return 1
    sudo apt install --assume-yes \
                     libjansson-dev \
                     libssl-dev \
                     libmagic-dev \
                     protobuf-compiler \
                     libprotobuf-dev \
                     libprotoc-dev \
                     libprotobuf-c-dev \
                     google-perftools \
                     libgoogle-perftools-dev || return 1
    sudo apt install --assume-yes \
                     libbluetooth-dev \
                     libdbus-1-dev || return 1
    sudo apt install --assume-yes \
                     libbsd-dev || return 1
}

##################################################
#               Install libpcap 1.9.1            #
##################################################
function install_libpcap
{
    wget https://www.tcpdump.org/release/libpcap-1.9.1.tar.gz || return 1
    tar -zxvf libpcap-1.9.1.tar.gz || return 1
    cd ./libpcap-1.9.1 || return 1
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
                --with-gcc || return 1
    make || return 1
    sudo make install || return 1
    cd ../ || return 1
}

##################################################
#               Install libyara 4.0.2            #
##################################################
function install_libyara
{
    wget https://github.com/VirusTotal/yara/archive/v4.0.2.tar.gz || return 1
    tar -zxvf v4.0.2.tar.gz || return 1
    cd ./yara-4.0.2 || return 1
    ./bootstrap.sh || return 1
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
                --with-crypto || return 1
    make || return 1
    sudo make install || return 1
    echo "/usr/local/lib" | sudo tee -a /etc/ld.so.conf > /dev/null || return 1
    sudo ldconfig || return 1
    cd ../ || return 1
}

##################################################
#               Install YAIDS                    #
##################################################
function install_yaids
{
    git clone https://github.com/wrayjustin/yaids.git || return 1
    cd ./yaids || return 1
    ./build.sh || return 1
    cd ../../ || return 1
}

##################################################
#               Verify YAIDS                     #
##################################################
function verify_install
{
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
        exit 0
    else
        echo "---------"
        echo "Installation Failed."
        exit 1
    fi
}

# Failure Process
function install_failed
{
    echo "---------"
    echo "Installation Failed."
    exit 1
}

# Execution Installation
setup_installer || install_failed
install_dependenices || install_failed
install_libpcap || install_failed
install_libyara || install_failed
install_yaids || install_failed
verify_install

#END
