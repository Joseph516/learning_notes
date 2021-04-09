#include "array_collection.h"

template <typename T>
T* ArrayCollection<T>::begin() {
  // return ArrayIterator(data_, 0);
  return data_;
}

template <typename T>
T* ArrayCollection<T>::end() {
  // return ArrayIterator(data_, size_ - 1);
  return data_ + size_;
}

// 实例声明，或将成员函数的实现写在类中
template class ArrayCollection<float>;
template class ArrayCollection<double>;
template class ArrayCollection<int>;
template class ArrayCollection<char>;