#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

int main() {
  std::vector<std::string> words{"aad", "sdgdfg", "good", "unbelivable"};

  int sz = 4;
  auto wc = std::find_if(words.begin(), words.end(),
                         [sz](const std::string& a) { return a.size() > sz; });
  
  std::for_each(wc, words.end(), [](const std::string &s) {std::cout << s << " ";});
  std::cout << "\n";
  
  return 0;
}