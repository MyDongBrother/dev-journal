#!/bin/bash
source ./script_tool/utils.sh

# 配置系统环境
project_name="dev-journal"
platform="linux" #[linux|qnx]
architecture="x86" #[x86|arm]
build_type="debug" #[release|debug|test]

# 根据配置选项创建build文件夹,配置编译选项
case "$platform" in
    "linux")
        case "$architecture" in
            "x86")
                setup_build_dir "./build_x86"
                ;;
            "arm")
                setup_build_dir "./build_arm"
                compiler_root_path="/opt/aarch64--glibc--stable-2020.08-1"
                echo "cmake_find_root_path ${compiler_root_path}" >> ${local_file}
                echo "cmake_c_compiler ${compiler_root_path}/bin/aarch64-buildroot-linux-gnu-gcc" >> ${local_file}
                echo "cmake_cxx_compiler ${compiler_root_path}/bin/aarch64-buildroot-linux-gnu-g++" >> ${local_file}
                ;;
            *)
                echo -e "${RED}$1 unsupported architecture${NC}"
                exit 1
                ;;
        esac
        ;;
    "qnx")
        setup_build_dir "./build_qnx"
        compiler_root_path="/opt/QNX_8155/qnx700_121c1/host/linux/x86/usr"
        echo "cmake_find_root_path ${compiler_root_path}" >> ${local_file}
        echo "cmake_c_compiler ${compiler_root_path}/bin/aarch64-unknown-nto-qnx7.0.0-gcc" >> ${local_file}
        echo "cmake_cxx_compiler ${compiler_root_path}/bin/aarch64-unknown-nto-qnx7.0.0-g++" >> ${local_file}
        export QNX_HOST=/opt/QNX_8155/qnx700_121c1/host/linux/x86
        export QNX_TARGET=/opt/QNX_8155/qnx700_121c1/target/qnx7
        export MAKEFLAGS=-I/opt/QNX_8155/qnx700_121c1/target/qnx7/usr/include
        ;;
    *)
        echo -e "${RED}$1 unsupported platform${NC}"
        exit 1
        ;;
esac

# 配置本地编译配置文件
echo "project ${project_name}" >> ${local_file}
echo "platform  ${platform}" >> ${local_file}
echo "architecture ${architecture}" >> ${local_file}
echo "build_type ${build_type}" >> ${local_file}

# 配置install路径
cmake -DCMAKE_INSTALL_PREFIX=$PWD ..
getCpuNum
echo "Adjusted CPU number: $cpu_num"

# 编译
cmake .
ExitIfCheckFail "cmake"
make -j$cpu_num
ExitIfCheckFail "make"
make install
ExitIfCheckFail "install"

# 运行
cp ./compile_commands.json ../cmake
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
./bin/main_run

echo "Done"
