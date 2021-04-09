本文章旨在结合C++面向对象方法，解决旋转方阵的实现问题，旋转方阵如下：
![旋转方阵示例](https://img-blog.csdnimg.cn/20200101221910921.png)
## 源代码
```sh
# 所有文件如下，执行：make&&./test
├── Makefile
├── anticlock_matrix.cpp
├── anticlock_matrix.h
├── main.cpp
├── matrix.cpp
└── matrix.h
```
## 步骤及思路
1. 根据功能，确定不变部分与可变部分。
```cpp
int main(void) {
  int N; // 定义方阵尺寸
  std::cout << "输入方阵尺寸：";
  std::cin >> N;

  // 定义对象并输出填充后矩阵
  Matrix obj(N);
  obj.fill();
  std::cout << obj;
}
```
2. 确定接口：从上到下设计。
  - 期待类所实现的功能
  - 根据期待的方法设计接口（最基本接口）
  - 确定成员变量
```cpp
class Matrix {
 public:
  const int size_;
  int* data_;
  char dir_;       // 移动方向
  int row_, col_;  // 当前坐标

 public:
  Matrix(int size);
  virtual ~Matrix();
  // 填充
  void fill();
  int getPosition();
  // 重载输出
  friend void operator<<(std::ostream& out, const Matrix& m);
};
```
4. 接口实现
  - 实现构造，析构等其它成员函数。
  - 实现必要的细化函数。
```cpp
Matrix::Matrix(int size) : size_(size), dir_('D'), row_(-1), col_(0){
  // 初始化数据
  data_ = new int[size * size];
  memset(data_, 0, (sizeof(int) * size * size));
}
void Matrix::fill() {
  for (int i = 0; i < size_ * size_; i++) {
    // 按数字顺序在指定位置填充
    int pos = getPosition(); 
    *(data_ + pos) = i + 1;
  }
}

int Matrix::getPosition() {
  switch (dir_) {
    case 'D':
      if (row_ < size_ - 1 && *(data_ + col_ + (row_ + 1) * size_) == 0) {
        ++row_;
      } else {
        dir_ = 'R'; // 到头，改变至下一个方向
        ++col_;
      }
      break;
    case 'R':
      if (col_ < size_ - 1 && *(data_ + (col_ + 1) + row_ * size_) == 0) {
        ++col_;
      } else {
        dir_ = 'U';
        --row_;
      }
      break;
    case 'U':
      if (row_ > 0 && *(data_ + col_ + (row_ - 1) * size_) == 0) {
        --row_;
      } else {
        dir_ = 'L';
        --col_;
      }
      break;
    case 'L':
      if (col_ > 0 && *(data_ + (col_ - 1) + row_ * size_) == 0) {
        --col_;
      } else {
        dir_ = 'D';
        ++row_;
      }
      break;
    default:
      break;
  }
  //   std::cout << row_ << col_ << std::endl;
  return col_ + row_ * size_;
}
```
5. 变与不变
   - 多态，适当定义接口类。
      显然在旋转方阵设计中，每次获取的位置是可变因素。根据位置函数不同，可以获取顺时针，逆时针等其它形式的方阵。
      因此根据OOP设计原则，将getPosition抽象，将Matrix定义成抽象类。在其派生类根据getPosition的不同，实现不同的功能的类，如逆时针方阵AnticlockMatrix。
```cpp
// 在Matrix中修改
virtual int getPosition() = 0;

// 添加AnticlockMatrix类，anticlock_matrix.h
class AnticlockMatrix : public Matrix {
 private:
  char dir_;       // 移动方向
  int row_, col_;  // 当前坐标

 public:
  AnticlockMatrix(int size);
  ~AnticlockMatrix();
  // 逆时针获取方阵位置
  int getPosition();
};

// anticlock_matrix.cpp
// 同时将getPosition() 在anticlock_matrix.cpp中实现
AnticlockMatrix::AnticlockMatrix(int size)
    : Matrix(size), dir_('D'), row_(-1), col_(0) {}
AnticlockMatrix::~AnticlockMatrix() {}
```
## 参考
题目源自清华大学课程《面向对象程序设计（C++）》