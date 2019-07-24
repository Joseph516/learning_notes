# Coding Tips

## 开发配置

### vscode

#### 配置clang format

1. 安装C/C++插件，clang-format插件，下载好的clang-format程序地址：

```shell
# window10：
C:\Users\leoyh\.vscode\extensions\ms-vscode.cpptools-0.24.0\LLVM\bin
```

2. vscode设置：

Clang-format: Executable，C_Cpp: Clang_format_style(file表示按照代码目录下.clang fomat文件格式化)等

设置保存时候自动格式化：Editor: Format On Save

或者按Shift+Alt+F手动格式化，Linux是Ctrl+Shift+I

3. 配置.clang-format文件防止在需要格式化的一级目录处。

   更多配置见官方文档：https://clang.llvm.org/docs/ClangFormat.html

   ```
   Language: Cpp
   
   BasedOnStyle: Google
   
   #修饰符偏移量
   AccessModifierOffset: 0
   
   #每行长度限制
   ColumnLimit: 80
   
   #允许单行
   AllowShortFunctionsOnASingleLine: false
   
   #缩进宽度
   IndentWidth: 2
   
   # 连续的空行保留几行
   MaxEmptyLinesToKeep: 1
   
   #tab键盘的宽度
   TabWidth: 2
   ```

### 配置ML GPU

#### AWS

参考：https://zhuanlan.zhihu.com/p/40376269

注意IP地址需要填写AWS EC2上的地址；打开jupyter notebook前，link前面的地址需要替换成AWS上的地址。

本地文件可以upload至GPU远程。基本过程如下：

```shell
 -# 切换AWS key location
cd Desktop/Machine_Learning/key 
# ip地址为AWS instance ip地址
ssh -i pem_name.pem ubuntu@ip address 
# if Permission denied,然后重复上一个步骤
chmod 700 pem_name.pem 
# 根据实际选择激活的环境
source activate mxnet_p36 
# 打开jupyter，0000表示接受任何ip地址
jupyter notebook --ip=0.0.0.0 
# 替换ip地址并进入
http://ip address:8888/?token=b393ccd8f53353417edccd612aa1ef208f8e30637816967a 
```

需要注意AWS GPU的内存，最好是生成instance之前设置好内存。

第六步选All traffic和anywhere，这样你才能随时随地连接到。

wget [url]: 快速上传文件至AWS

new-Terminal：jupyter notebook上使用终端。

