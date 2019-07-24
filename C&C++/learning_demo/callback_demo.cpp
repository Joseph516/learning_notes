#include <iostream>

int getDouble(int x) {
  return x * 2;
}

int getQuadruple(int x) {
  return x * 4;
}

int getOddNumber(int x, int (*getEvenNumber)(int x)) {
  return 1 + (*getEvenNumber)(x);
}

int main(int argc, const char *argv[]) {
  int x = 3;
  std::cout << "x is:" << x << std::endl;

  // 生成2k+1奇数
  std::cout << "2 Times odd number is:" << getOddNumber(x, getDouble) << std::endl;

  // 生成4k+1奇数
  std::cout << "4 Times odd number is:" << getOddNumber(x, getQuadruple) << std::endl;

  return 0;
}