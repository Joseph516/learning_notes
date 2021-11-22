# Linux

# makefile

## simple case

wiki：

Here is a simple makefile that describes the way an executable file called _edit_ depends on four object files which, in turn, depend on four C source and two header files. To be concrete, `edit` is a target, `main.o`, `kbd.o`, `command.o` and `display.o`are its dependencies, and `cc -o edit main.o kbd.o command.o display.o` is a system command.

executable file name: edit，所需目标文件：main.o kbd.o command.o display.o

cc：编译器，如 gcc，g++ 。-c：汇编命令，生成目标文件.o

clean: 清除.o 文件，配合 make clean 使用。

```makefile
edit: main.o kbd.o command.o display.o
    cc -o edit main.o kbd.o command.o display.o

main.o: main.c defs.h
    cc -c main.c
kbd.o: kbd.c defs.h command.h
    cc -c kbd.c
command.o: command.c defs.h command.h
    cc -c command.c
display.o: display.c defs.h
    cc -c display.c

clean:
     rm edit main.o kbd.o command.o display.o
```

To use this makefile to create the executable file called _edit_, type `make`.

To use this makefile to delete the executable file and all the object files from the directory, type `make clean`. 单独使用 make，并不会清除.o 文件。

### gcc 编译过程

```makefile
#该命令将hello.c直接生成最终二进制可执行程序hello.out
gcc -o hello hello.c
# 也可以生成exe
gcc hello.c -o hello.exe

# 预处理
#作用：将hello.c预处理输出hello.i文件。
gcc -E hello.c -o hello.i

# 编译
#作用：将预处理输出文件hello.i汇编成hello.s文件。
gcc –S hello.i –o hello.s

# 汇编
#作用：将汇编输出文件test.s编译输出test.o文件。
gcc –c hello.s –o hello.o

# 链接
# 链接生成hello.out
gcc -o hello hello.o
#作用：将编译输出文件hello.o链接成最终可执行文件hello.exe。
gcc hello.o –o hello.exe

# 函数库一般分为静态库和动态库两种。
# 静态库是指编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了。其后缀名一般为”.a”。
# 动态库在编译链接时并没有把库文件的代码加入到可执行文件中，而是在程序执行时由运行时链接文件加载库，这样可以节省系统的开销。动态库一般后缀名为”.so”，如前面所述的libc.so.6就是动态库。
# gcc在编译时默认使用动态库。
```

Makefile 处理多个文件的 debug。

```makefile
objects = main.o read_data.o fft.o complex.o
eq_match: $(objects)
	g++ -o debug $(objects)

main.o: main.cpp read_data.h complex.h
	g++ -g -c main.cpp

read_data.o: read_data.cpp
	g++ -g -c read_data.cpp

fft.o: fft.cpp complex.h
	g++ -g -c fft.cpp

complex.o: complex.cpp
	g++ -g -c complex.cpp

clean:
	rm eq_match $(objects)
```

## rules

根据上述实例，makefile 规则为：

target 除了上述 clean，还可以是其它命令。

```makefile
target: dependencies
	# system command(s)前面必须是tab
    system command(s)
```

## reference

- 和我一起学 makefile：https://seisman.github.io/how-to-write-makefile/introduction.html
- 某 blog：http://www.ruanyifeng.com/blog/2015/02/make.html
- GNU Doc： https://www.gnu.org/software/make/manual/make.html

## cmake

make 工具，可以生成 makefile、vs 等 IDE 工程文件。

cmake Tutorials：https://www.hahack.com/codes/cmake/

vscode+cmake+gdb 构建大型工程项目：https://zhuanlan.zhihu.com/p/45528705?utm_source=wechat_session&utm_medium=social&utm_oi=687576648198914048

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) # cmake最低版本要求

PROJECT(CppTemplate)    # 工程名 CppTemplate

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # 添加c++11标准支持

SET(CMAKE_C_COMPILER "/usr/bin/gcc") # 默认c编译器
SET(CMAKE_CXX_COMPILER "/usr/bin/g++") # 默认c++编译器

SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInfo

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项

# set(CMAKE_VERBOSE_MAKEFILE ON) # 开启调试 出现问题时开启

# enable_testing() # 打开测试

add_definitions(-DDEBUG) # 相当于代码中 #define DEBUG

# add_subdirectory(test) # 添加test子目录

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin") # 可执行文件输出目录

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include") # 头文件包含目录

# 这段代码可以区分操作系统
MESSAGE("Identifying the OS...")
if(WIN32)
  MESSAGE("This is Windows.")
elseif(APPLE)
  MESSAGE("This is MacOS.")
elseif(UNIX)
  MESSAGE("This is Linux.")
endif()
# 这段代码可以区分操作系统

AUX_SOURCE_DIRECTORY(src DIR_SRCS) # 添加源代码文件夹, 自动扫描所有文件

add_executable(chess  # 输出名为chess的可执行文件
   ${DIR_SRCS}
)
# 也可以这么写
# add_executable(chess  # 输出名为chess的可执行文件
#    ./src/main.cpp
#    ./src/utils.cpp
# )
```

```cmake
# 线程相关选项
find_package(Threads REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # CXX表示C++
# SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread") # 对应C
```

# Debugging 调试

## 条件编译调试

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
#ifdef DEBUG
  printf(
      "Compiled: " __DATE__
      " at " __TIME__
      "\n");
  printf("This is the %d line of the file %s \n", __LINE__, __FILE__);
#endif
  printf("Hello World");
  exit(0);
}
```

命令行：

```shell
# 注意DEBUG前有D
gcc -o main -DDEBUG main.c
```

## gdb 调试

GNU gdb 调试工具是 linux 的默认调试工具。https://www.gnu.org/s/gdb/

### 基本操作

gdb 命令基本上可以使用首字母缩写，如 r 代替 run。

- gcc -g -o file_name file_name.c ：开始进行调试

- gdb file_name

- run: 运行程序

- quit：退出调试

- backtrace/bt/where：三个命令都可以实现栈跟踪

- print variable：输出变量或表达式的内容。$1 = 4， $1 是伪变量，4 是变量的值。

  gdb 将变量的值保存在伪变量$<number>中，可以直接print $1。最后一次操作的结果总是$，倒数第二次操作是$$.

  - 打印小数正数，浮点数等

    p/t v // 将 v 转化成二进制输出

    p/x v // 转化成十六进制输出

    p/f v // 转化成浮点数输出

  print array_name[0]@number：打印出指定数目的数组内容。

- list：列出周围代码，可以用行号和函数跳转至指定代码。

### 单步调试

设置断点调试，help breakpoint 查看帮助，回车可以重复上一个命令。

- break n：对指定 n 行号设置断点。

  break function_name：对指定函数位置设置断点。

  break file_name:line_number: 对指定文件指定行打断点。(注意中间的冒号)

- step：执行当前行代码，并跳转至下一行代码。

- cont：继续执行，可以到下一个断点。

- display array[0]@5： display 命令每次遇到断点自动显示需要的内容。

- commads n：可以自定义遇到第 n 个断点后所执行的命令。

- info 查看命令内容，info dispaly，info break 等

- disable：禁用命令，不是删除。disable break 1：取消第一个断点。

- set variable name：对指定变量名的变量进行补丁操作。结合 commands 命令。

### 动态内存测试工具

ElectricFence 和 valgrind

### 如何结合 malefile 调试大型程序

#### 命令行使用 gdb 调试

1. 配置好 makefile 的 debug
2. 使用 gdb 运行 make 生成的 debug 文件。
3. 打断点：目标文件+断点位置，如 b main.cpp:1(即在 main.cpp 文件的第一行打断点)。

#### vscode 使用 launch 和 task 配置进行调试

1. 先配置合适的 task.json 文件，即具体需要执行或调试的命令。
2. 配置 launch.json 配置启动文件。
3. 注意在 debug 时需要在 makefile 文件中配置好 debug，否则无法打断点。

task.json

```json
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  // for the documentation about the tasks.json format
  "version": "2.0.0",
  "tasks": [
    {
      "label": "clean", // 任务名称
      "command": "make",
      "args": ["clean"],
      "type": "shell"
    },
    {
      "label": "build-debug",
      "command": "make",
      "args": ["build"],
      "type": "shell"
    },
    {
      "label": "build-all", // 依次调试多个任务，若不配置此，则每次launch只会启动一个任务。
      "dependsOn": ["clean", "build-debug"]
    }
  ]
}
```

launch.json

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "makefile debug",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/monitor", // 调试的程序位置
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}", // 当前项目的路径，即用vscode打开时的位置
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "build-all", // 第一次开始调试的任务，见task.json
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```

### 参考

Tutorial：https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/gdb.html

# 进程管理

linux 上进程有 5 种状态:

1. 运行(正在运行或在运行队列中等待)
2. 中断(休眠中, 受阻, 在等待某个条件的形成或接受到信号)
3. 不可中断(收到信号不唤醒和不可运行, 进程必须等待直到有中断发生)
4. 僵死(进程已终止, 但进程描述符存在, 直到父进程调用 wait4()系统调用后释放)
5. 停止(进程收到 SIGSTOP, SIGTSTP, SIGTTIN, SIGTTOU 信号后停止运行运行)

ps 工具标识进程的 5 种状态码:

- D 不可中断 uninterruptible sleep (usually IO)

- R 运行 runnable (on run queue)

- S 中断 sleeping

- T 停止 traced or stopped

- Z 僵死 a defunct (”zombie”) process

## 主要命令

ps -A：显示所有进程。

ps -ef：显示所有进程，连同命令显示。

**ps -ef|grep chrome：与 grep 使用，显示特定 chrome 进程。**

ps ax：查看进程当前状态。R：表示运行，S：表示睡眠

**ps aux:列出目前所有的正在内存中的程序，状态等。**

ps -aux --sort -pcpu | less：按 cpu 使用排序，less 管道筛选，q 命令可以退出 less 命令。

ps -aux --sort -pmem | less：按内存使用排序

ps -l：查看程序的 nice 值（NI），NI 值越高，优先级越高。

kill -l：显示杀死进程的命令。

kill -9 PID_number：强制杀死程序，慎用！

**killall name：按进程名杀死进程**

kill -l PID_number：重启进程

## 参考

进程相关 blog：https://segmentfault.com/a/1190000014730535

e-book：https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/ps.html

# POSIX 线程

在一个程序中多个执行线路，是一个进程内部的控制序列。

- 线程优势：

  可以让程序同时做多件事。

  线程切换资源比进程切换资源少。

- 线程的劣势

  设计困难，调试困难。

# C++ Unit Test

Tool： Google C++ Unit Test，Github 地址：https://github.com/google/googletest

## Install

1. google gtest 是一个跨平台测试框架，对于 linux 来说只需要关注 cmake 和 include，make 即可。

   其中 make 中，有基本的测试方法 makefile，对应与 sample 中的例子。

2. 生成 shared library，并将其放在公共搜索路径中。

   ```shell
   cd googletest-release-1.8.0
   mkdir build
   cmake -DBUILD_SHARED_LIBS=ON ../
   make # 生成libgtest_main.so libgtest.so
   sudo cp -a include/gtest /usr/include
   sudo cp -a libgtest_main.so libgtest.so /usr/lib/
   # 查看是否链接
   sudo ldconfig -v | grep gtest
   ```

3. 链接成功后，可以直接在需要测试的 cpp 程序中，包含#include <gtest/gtest.h>

## 测试方法

**sqrt_test.cpp**：单元测试文件

```c++
#include "sqrt.cpp" // 需要测试的程序
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) {
  ASSERT_EQ(6, squareRoot(36.0));
  ASSERT_EQ(18.0, squareRoot(324.0));
  ASSERT_EQ(25.4, squareRoot(645.16));
  ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) {
  ASSERT_EQ(-1.0, squareRoot(-15.0));
  ASSERT_EQ(-1.0, squareRoot(-0.2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

**CMakeLists.txt**

```cmake
cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 下面3行是对单元测试的bin文件调试，命令行：cmake  -DCMAKE_BUILD_TYPE=Debug path
SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInfo
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests sqrt_test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
```

**main.cpp**

```c++
// 编写main函数，并将指定需要测试的cpp包含。
#include <gtest/gtest.h>
#include "utils2_test.cpp"
#include "utils_test.cpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

# ubuntu 的基本操作

## Software Operation

### Install and uinstall

- 查看软件：dpkg --get-selections | grep [software_name]
- 卸装软件： sudo apt-get purge [software_name]
- 安装软件： sudo apt-get install [software_name]
- 安装.deb 文件：sudo dpkg -i [software.deb]
- 卸装.deb 文件：sudo apt-get remove [software_name]
- chmod u+x file_name : 将文件变成 executable

### Uncompress the executable

#### 安装 rar 工具

```shell
# 安装rar压缩程序
sudo apt-get install rar
# 安装rar 解压文件
sudo apt-get install unrar
```

#### 基本操作

- .tar 文件

  解包：tar xvf file_name.tar

  打包：tar cvf file_name.tar DirName

- .tgz 文件

  解压：tar zxvf file_name.tgz

  压缩：tar czvf file_name.tgz compressed_name

- .rar 文件

  解压：rar x file_name.rar

  压缩：rar a file_name.rar DirName

- .Z 文件

  解压：uncompress file_name.Z

  压缩：compress file_name

- .bz2
  解压 1：bzip2 -d FileName.bz2

  解压 2：bunzip2 FileName.bz2

  压缩： bzip2 -z FileName

- zip 命令
  解压：unzip FileName.zip

  压缩：zip -r FileName.zip DirName

  **示例**

- 解压文件.gz 至 .tar：gzip -d [file_name]

- 解包文件 .tar file: tar xvf [file_name]

- 运行 .run file: ./ [file_name]

### Folder operation

- 命令行打开文件夹：nautilus [folder_name]

### Problems

- Could not get lock /var/lib/dpkg/lock-frontend:

  原因：有安装或卸装程序占用进程。

  解决办法：

  ```shell
  # 查看进程
  ps aux | grep -i apt
  # 关闭进程
  sudo kill -9 <process id>
  # 或者关闭所有进程
  sudo killall apt apt-get
  ```

### C++编译

- 不使用 g++98 编译：g++ -std=c++11 代替 g++

### ssrin & pip

导致无法使用 pip，终端运行，修改 proxy：

/etc/environment 配置，删除

all_proxy=socks5://127.0.0.1:1080/
ALL_PROXY=socks5://127.0.0.1:1080/

临时使用清华源安装：

```shell
sudo pip install -i https://pypi.tuna.tsinghua.edu.cn/simple 软件包名称
```

永久设置：

```
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
```

### 创建快捷方式 .desktop

参考 TIM 设置：https://www.jianshu.com/p/f38187cdda0

桌面和 Dash 快捷方式的位置：/usr/share/applications 和~.local/share/applications

可以将包括多个.desktop 的文件夹放进去，可以生成多个快捷方式。

```shell
# 直接在Terminal输入tim启动程序
sudo ln -s ~/Software/tim/TIM.AppImage /usr/bin/tim

# Allow executing file as program/允许以应用程序执行
chmod +x file_name

# 设置icon和bin启动程序
cat > ~/usr/share/applications/tim.desktop <<EOL
[Desktop Entry]
Encoding=UTF-8
Name=Tim
Exec=tim # 程序启动路径
Icon=/home/jack/Software/tim/icon.png
Terminal=false
Type=Application
Categories=Internet;
EOL
```

## ssh

解决服务器自动断开问题：

vim /etc/ssh/sshd_config

```
ClientAliveInterval 60 #每分钟向客户的发送一次请求
ClientAliveCountMax 1440　＃ 当请求次数超多1440后无反应自动断开。
# 重新加载ssh配置
service sshd reload
sudo /etc/init.d/ssh restart
```

## virtualbox

### 无法识别 USB

1. 安装拓展 Oracle_VM_VirtualBox_Extension_Pack-5.1.38.vbox-extpack

2. 将用户名加入 groups。

   找到用户名：who am i

   查看用户名是否在 vbox 组内：cat /etc/group | grep vbox

   加入用户名：usermod -a -G vboxusers 用户名

3. 重启电脑和 virtualbox

4. 注意：使用 usb3.0 无法启动虚拟机。
