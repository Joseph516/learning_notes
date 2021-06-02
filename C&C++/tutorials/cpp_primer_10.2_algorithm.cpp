#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int ia[] = {10, 30, 40, 55, 76, 30};

  // find
  int val = 55;
  int* result = std::find(std::begin(ia), std::end(ia), val);
  // auto res = std::find(ia+1, ia+3, val);
  if (result != std::end(ia)) {
    std::cout << "Find value!"
              << "\n";
  }

  // count
  auto cnt = std::count(std::begin(ia), std::end(ia), 30);
  std::cout << cnt << "\n";

  // equal
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::vector<int> v2{1, 2, 3, 4, 5};
  auto res_equal = std::equal(v1.cbegin(), v1.cend(), v2.cbegin());
  if (res_equal) {
    std::cout << "Equal!"
              << "\n";
  }

  // sort&unique
  std::vector<std::string> words{"good", "boy", "hello", "nx", "hi", "nx"};
  std::sort(words.begin(), words.end());
  auto word_unique_end = std::unique(words.begin(), words.end());
  words.erase(word_unique_end, words.end());
  for (const auto& v : words) {
    std::cout << v << " ";
  }
  std::cout << "\n";
  return 0;
}