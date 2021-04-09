#include "anticlock_matrix.h"
#include <iostream>

int main(void) {
  int N; // 定义方阵尺寸
  std::cout << "输入方阵尺寸：";
  std::cin >> N;

  // 定义对象并输出填充后矩阵
  AnticlockMatrix obj(N);
  obj.fill();
  std::cout << obj;
}