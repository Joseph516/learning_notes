# ubuntu Hints

## Software Operation

**Install and uinstall**

- 查看软件：dpkg --get-selections | grep [software name]

- 卸装软件： sudo apt-get purge [software name]

- 安装软件： sudo apt-get install [software name]

- 安装.deb文件：sudo dpkg -i [software.deb]

- 卸装.deb文件：sudo apt-get remove [software name]

**Uncompress the executable**

- 解压文件.gz to .tar：gzip -d [software name]
- untar the .tar file: tar xvf [software name]
- run the installer .run file: ./ [software name]   

**Folder operation**
- 打开文件夹：nautilus [folder name]

