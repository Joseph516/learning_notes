#pragma once

// #include "iterator.h"

template <typename T>
class ArrayIterator {
  T* data_;
  int index_;

 public:
  ArrayIterator(T* data, int index) : data_(data), index_(index) {}
  ArrayIterator(ArrayIterator& other)
      : data_(other.data_), index_(other.index_) {}
  ~ArrayIterator() {}

  bool operator!=(const ArrayIterator& other) const;
  const ArrayIterator& operator++();
  const ArrayIterator& operator++(int);
  T& operator*() const;
  T* operator->() const;
};