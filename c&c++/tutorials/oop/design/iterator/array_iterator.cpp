#include "array_iterator.h"

template <typename T>
bool ArrayIterator<T>::operator!=(const ArrayIterator<T>& other) const {
  return (data_ != other.data_ || index_ != other.index_);
}

template <typename T>
const ArrayIterator<T>& ArrayIterator<T>::operator++() {
  index_++;
  return *this;
}

template <typename T>
const ArrayIterator<T>& ArrayIterator<T>::operator++(int) {
  index_++;
  return ArrayIterator(data_, index_ - 1);
}

template <typename T>
T& ArrayIterator<T>::operator*() const {
  return *(data_ + index_);
}

template <typename T>
T* ArrayIterator<T>::operator->() const {
  return (data_ + index_);
}


template class ArrayIterator<float>;
template class ArrayIterator<double>;
template class ArrayIterator<int>;
template class ArrayIterator<char>;

