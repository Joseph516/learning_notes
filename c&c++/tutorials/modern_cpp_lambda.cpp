#include <functional>
#include <iostream>
#include <memory>
#include <utility>

void lambda_expression_capture() {
  auto important = std::make_unique<int>(1);
  auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
    return x + y + v1 + (*v2);
  };
  std::cout << add(3, 4) << std::endl;
}

int foo(int para) { return para; }
int main() {
  std::function<int(int)> func = foo;

  std::cout << func(10) << std::endl;

  int important = 10;
  std::function<int(int)> func2 = [&](int value) -> int {
    // &表示捕捉搜索lambda出现的变量，这里指important变量。
    return 1 + value + important;
  };
  std::cout << func2(10) << std::endl;

  return 0;
}