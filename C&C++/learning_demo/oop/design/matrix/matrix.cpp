#include "matrix.h"

Matrix::Matrix(int size) : size_(size) {
  // 初始化数据
  data_ = new int[size * size];
  memset(data_, 0, (sizeof(int) * size * size));
}

Matrix::~Matrix() { delete[] data_; }

// 重载输出
void operator<<(std::ostream& out, const Matrix& m) {
  for (int i = 0; i < m.size_; i++) {
    for (int j = 0; j < m.size_; j++) {
      std::cout << *(m.data_ + j + i * m.size_) << '\t';
    }
    std::cout << std::endl;
  }
}

void Matrix::fill() {
  for (int i = 0; i < size_ * size_; i++) {
    // 按数字顺序在指定位置填充
    int pos = getPosition(); 
    *(data_ + pos) = i + 1;
  }
}

