/**
 * 算法分解：
 * -------描述--------------操作--------参数---------
 * 针对集合中的所有元素    遍历操作    _iterator
 * 判断是否结合           判断        _isPass
 * 对及格者累加           累加        analyze()函数本身
 */
#include <iostream>
#include "array_collection.h"
#include "array_iterator.h"

template <typename iterator_>
void analyze(iterator_ begin, iterator_ end) {
  int passed = 0, count = 0;
  for (iterator_ p = begin; p != end; p++) {
    if (*p >= 60) {
      passed++;
    }
    count++;
  }

  std::cout << "Passing rate is: " << (float)passed / count << std::endl;
}

int main(void) {
  float scores[6] = {20, 30, 50, 55, 70, 90};
  //   Collection<float> *collection1 = new ArrayCollection<float>(6, scores);

  ArrayCollection<float> collection1(6, scores);

  // int a = collection1.size();

  analyze(collection1.begin(), collection1.end());

  return 0;
}