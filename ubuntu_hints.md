# ubuntu Hints

## Software Operation

### Install and uinstall

- 查看软件：dpkg --get-selections | grep [software_name]

- 卸装软件： sudo apt-get purge [software_name]

- 安装软件： sudo apt-get install [software_name]

- 安装.deb文件：sudo dpkg -i [software.deb]

- 卸装.deb文件：sudo apt-get remove [software_name]

### Uncompress the executable

#### 安装rar工具

```shell
# 安装rar压缩程序
sudo apt-get install rar
# 安装rar 解压文件
sudo apt-get install unrar
```

#### 基本操作 

- 接包与压缩包.tar文件

  解包：tar xvf file_name.tar

  打包：tar cvf file_name.tar DirName

- 解压与压缩.rar文件

  解压：rar x file_name.rar

  压缩：rar a file_name.rar DirName 

- 解压与压缩.Z文件

  解压：uncompress file_name.Z

  压缩：compress file_name

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

