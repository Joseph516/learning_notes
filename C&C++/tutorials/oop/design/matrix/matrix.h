// oop设计：方阵填充
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstring>
#include <iostream>

class Matrix {
 public:
  const int size_;
  int* data_;

 public:
  Matrix(int size);
  virtual ~Matrix();
  // 填充
  void fill();
  virtual int getPosition() = 0;
  // 重载输出
  friend void operator<<(std::ostream& out, const Matrix& m);
};

#endif