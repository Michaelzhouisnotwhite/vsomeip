#!/usr/bin/sh
BASEDIR="$( cd "$( dirname "$0" )" && pwd )"
echo $BASEDIR
export LD_LIBRARY_PATH=$BASEDIR/../vsomeip-installed/lib/:$LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH