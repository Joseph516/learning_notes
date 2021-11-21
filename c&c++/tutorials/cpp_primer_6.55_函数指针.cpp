#include <iostream>
#include <vector>

int func(int, int) { return 0; }
int (*p)(int, int);  // 函数指针

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
  std::vector<decltype(func)*> v;  // decltype(func)*表示指向某类函数的指针
  v.push_back(add);
  v.push_back(subtract);
  v.push_back(multiply);
  v.push_back(divide);

  // 调用
  int a = 6, b = 3;
  for (auto const& f : v) {
    std::cout << f(a, b) << std::endl;
  }
  return 0;
}
