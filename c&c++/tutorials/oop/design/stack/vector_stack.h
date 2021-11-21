#pragma once

#include <vector>
#include "stack.h"

template <typename T>
class VectorStack : public Stack<T> {
 private:
  std::vector<T> data;

 public:
  VectorStack() {}
  ~VectorStack() {}

  void pop() {
    if (!empty()) {
      data.pop_back();
    }
  }
  T top() {
    if (!empty()) {
      return data[data.size() - 1];
    }
    return 0;
  }

  void push(T e) { data.push_back(e); }
  bool empty() { return data.empty(); }
};