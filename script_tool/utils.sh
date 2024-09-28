#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

ExitIfCheckFail()
{
    if [ $? -ne 0 ]; then
        echo -e "${RED}$1 execute failed${NC}"
        exit 1
    else
        echo -e "${GREEN}$1 execute success${NC}"
    fi
}

getCpuNum(){
    cpu_num=`cat /proc/cpuinfo | grep processor | wc -l`
    if [ $cpu_num -eq 0 ];then
        cpu_num=7
    else
        cpu_num=`expr $cpu_num \* 8 / 10`
    fi
}

setup_build_dir() {
    build_dir="$1"  # 将传入的参数赋值给全局变量 build_dir

    # 创建目录并进入
    mkdir -p "${build_dir}"  # 创建目录（如果目录已经存在，不报错）
    cd "${build_dir}"
    local_file="build.properties.local"
    # 创建文件并写入空内容
    touch ${local_file}
    echo "" > ${local_file}
}