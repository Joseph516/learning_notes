#include <iostream>

#include "vector_stack.h"

template<typename T>
void testStack(Stack<T> & s) {
  for (int i = 0; i < 5; i++) {
    s.push(i);
  }

  while(!s.empty()) {
    T e = s.top();
    std::cout << e << std::endl;
    s.pop();
  }
} 

int main(void) {
  VectorStack<float> stack;
  testStack(stack);

  return 0;
}