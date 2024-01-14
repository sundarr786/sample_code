#!/bin/bash

#credit = clement jean
#for own purpose
#for installing:
PROTOC_VERSION=$(curl -sL "https://api.github.com/repos/protocolbuffers/protobuf/releases/latest" | awk '/"tag_name": "v[0-9.]+"/{print $2}' | awk 'match($0, /[0-9.]+/) { print substr( $0, RSTART, RLENGTH )}')
PROTOC_OS=linux
PROTOC_ARCH=x86_64

curl -Lo protoc.zip "https://github.com/protocolbuffers/protobuf/releases/latest/download/protoc-${PROTOC_VERSION}-${PROTOC_OS}-${PROTOC_ARCH}.zip"

unzip -q protoc.zip -x readme.txt -d /usr/local

rm -f protoc.zip

chmod a+x /usr/local/bin/protoc

protoc --version

#uninstall

#sudo rm -f /usr/local/bin/protoc
#sudo rm -rf /usr/local/include/google/protobuf

