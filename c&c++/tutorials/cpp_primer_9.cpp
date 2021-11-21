#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void stdout_print(const T& a) {
  for (auto& v : a) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}

template <typename T>
void stdout_print_pointer(const T& a) {
  for (auto iter = a.begin(); iter != a.end(); iter++) {
      std::cout << *iter << " ";
  }
  std::cout << "\n";
}

int main() {
  // swap
  std::vector<int> a, b;
  a = {1, 2, 3};
  swap(a, b);
  a.insert(a.begin(), 5, 4);
  stdout_print(a);
  stdout_print(b);

  // assign
  std::list<std::string> names;
  char ch_a = 'a';
  char ch_b = 'b';
  char ch_c = 'c';
  std::vector<const char*> oldstyle{&ch_a, &ch_b, &ch_c};
  names.assign(oldstyle.cbegin(), oldstyle.cend());
  // FIXME: 字符串乱码
  stdout_print_pointer(names); 
  stdout_print_pointer(oldstyle);
  // FIXME: 这样不乱码，但是names会保错
  for (auto iter = oldstyle.begin(); iter != oldstyle.end(); iter++) {
      std::cout << *(*iter) << " ";
  }
  std::cout << "\n";
  
}