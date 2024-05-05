#!/usr/bin/bash
BASEDIR=$(dirname $0)
export LD_LIBRARY_PATH=$BASEDIR/../vsomeip-installed/lib/:$LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH