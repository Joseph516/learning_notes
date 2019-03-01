# Ubuntu笔记

## Software Operation

### Install and uinstall

- 查看软件：dpkg --get-selections | grep [software_name]
- 卸装软件： sudo apt-get purge [software_name]
- 安装软件： sudo apt-get install [software_name]
- 安装.deb文件：sudo dpkg -i [software.deb]
- 卸装.deb文件：sudo apt-get remove [software_name]
-  chmod u+x  file_name : 将文件变成executable

### Uncompress the executable

#### 安装rar工具

```shell
# 安装rar压缩程序
sudo apt-get install rar
# 安装rar 解压文件
sudo apt-get install unrar
```

#### 基本操作 

- .tar文件

  解包：tar xvf file_name.tar

  打包：tar cvf file_name.tar DirName

- .tgz文件

  解压：tar zxvf file_name.tgz

  压缩：tar czvf  file_name.tgz compressed_name

- .rar文件

  解压：rar x file_name.rar

  压缩：rar a file_name.rar DirName 

- .Z文件

  解压：uncompress file_name.Z

  压缩：compress file_name

- .bz2 
   解压1：bzip2 -d FileName.bz2 

   解压2：bunzip2 FileName.bz2

   压缩： bzip2 -z FileName 

- zip命令
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

- 不使用g++98编译：g++ -std=c++11 代替g++

### ssrin & pip

导致无法使用pip，终端运行，修改proxy：

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

参考TIM设置：https://www.jianshu.com/p/f38187cdda0

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