# Python学习笔记

# Question

# 实用知识

## 单元测试

```python
# 编写单元测试类，包含需要测试的类或函数。
# 注意单元测试的类需要继承unittest.TestCase
import unittest

from mydict import Dict

class TestDict(unittest.TestCase):

    def test_init(self):
        d = Dict(a=1, b='test')
        self.assertEqual(d.a, 1)
        self.assertTrue(isinstance(d, dict))
   
# 运行单元测试
python -m unittest mydict_test
```

## freeze

生成或更新项目需要的库文件及版本信息

```shell
pip freeze > requirements.txt
# 查看环境库
pip freeze
```

## virtualenv

创建独立的python运行环境，不影响其它python库文件及版本。

Tutorial：https://realpython.com/python-virtual-environments-a-primer/

conda创建教程：<https://blog.csdn.net/u012343179/article/details/76146815>

```shell
# 指定python版本创建环境
virtualenv --no-site-packages -p /usr/bin/python3.5 env
# 激活环境
source venv/bin/activate
# 取消激活环境
source venv/bin/deactivate
# 安装软件包
pip install package_name

# 使用conda安装，包的安装位置在anaconda的envs中。
conda create -n name python=具体版本 其它库如numpy
source activate name
```

使用venv方法创建：

```shell
# Python 2:
virtualenv env

# Python 3
python3 -m venv env
```

## 并行计算

https://joblib.readthedocs.io/en/latest/

## 软件包管理PyPi

使用setuptools工具，编写setup.py文件, https://pypi.org/project/setuptools/

1. 直接提交到pypi服务器，可以使用pip下载安装。
2. 本地安装，只能在本地使用。http://www.cnblogs.com/streakingBird/p/4056765.html

### pip

- 查看软件包更新：pip list --outdate

# 基本知识

### “*”符号的意义

单星号,将所以参数以元组(tuple)**的形式导入：

双星号，将参数以字典的形式导入

```ipython
In [1]: def fooa(): 
   ...:     a = 1 
   ...:     b =2  
   ...:     return a,b 
   ...:                                                                         

In [2]: def foob(a,b): 
   ...:     print(a+b) 
   ...:                                                                         

In [3]: foob(*fooa())                                                           
3
```

### python与matlab交互

- 使用matlab的数据分析计算

  ```matlab
  % save some data in a .mat
  a = [1, 2, 3; 4, 5, 6];
  S.b = [7, 8, 9; 10, 11, 12];
  M(1).c = [2, 4, 6; 8, 10, 12];
  M(2).c = [1, 3, 5; 7, 9, 11];
  
  save('data.mat','a','S','M')
  ```

  ```python
  import scipy.io as spio
  mat = spio.loadmat('data.mat', squeeze_me=True)
  
  a = mat['a'] # array
  S = mat['S'] # structure containing an array
  M = mat['M'] # array of structures
  ```

### 运行python

```python
# 当文件被直接运行时，执行function函数。当文件被导入时，不执行。
if __name__ == "__main__":
    function()
```

## IPython

## Jupyter notebook

### 安装插件

1. 安装目录功能：pip install jupyter_contrib_nbextensions
2. 配置nbextension：jupyter contrib nbextension install --user --skip-running-check
3. 启动jupyter notebook配置

### 添加内核

```shell
# 查看内核
jupyter kernelspec list
# 移除
jupyter kernelspec remove python2

# 安装
path/to/python2 -m pip install ipykernel
# 添加内核 --name [name]可以取名
path/to/python2 -m ipykernel install <options>

path/to/python3 -m pip install ipykernel
path/to/python3 -m ipykernel install <options>
```



# 遇到的问题

- conda not found: 

   export PATH=/home/joe/anaconda3/bin ：加入conda bin文件路径	
