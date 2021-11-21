#include <array>
#include <iostream>

int main() {
  std::array<int, 10> a{1,2};
  //   for (const auto& c : a) {
  //     std::cout << c << std::endl;
  //   }
  for (std::array<int, 10>::size_type i = 0; i < a.size(); i++) {
    std::cout << a[i] << std::endl;
  }
  return 0;
}