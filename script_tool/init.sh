#!/bin/bash
# CURRENT_SCRIPT_DIR=$(dirname $(realpath $0))
# DUMP_DIR=~/dump
#PID=`ps aux | grep main_run | grep -v grep | grep -v init | awk '{print $2}'`
PID=`top -b -n 1  |  grep main_run | grep -v grep | awk '{print $1}'`
echo $PID

# # start SPI service
# ulimit -c unlimited
# mkdir -p $DUMP_DIR
# sudo sysctl -w kernel.core_pattern=$DUMP_DIR/core-%e.%p.%h.%t
# # run app start script here
echo "starting main_run app"
# change working directory
# run app
# cd $CURRENT_SCRIPT_DIR
# echo $CURRENT_SCRIPT_DIR
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib/


if [[ "$PID" != "" ]];then
    sudo kill -9 $PID
fi
./bin/main_run
