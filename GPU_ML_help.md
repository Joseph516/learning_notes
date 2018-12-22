# gpu help

## AWS

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