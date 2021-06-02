#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec;
  std::cout << " size: " << ivec.size() << " capacity: " << ivec.capacity()
            << std::endl;

  for (std::vector<int>::size_type i = 0; i != 24; i++) {
    ivec.push_back(1);
  }
  std::cout << " size: " << ivec.size() << " capacity: " << ivec.capacity()
            << std::endl;

  ivec.reserve(50);
  std::cout << " size: " << ivec.size() << " capacity: " << ivec.capacity()
            << std::endl;

  while(ivec.size() != ivec.capacity()) {
      ivec.push_back(0);
  }
  ivec.reserve(50);
  std::cout << " size: " << ivec.size() << " capacity: " << ivec.capacity()
            << std::endl;

  ivec.push_back(1);
  std::cout << " size: " << ivec.size() << " capacity: " << ivec.capacity()
            << std::endl;
}