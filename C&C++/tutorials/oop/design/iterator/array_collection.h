#pragma once

template <typename T>
class ArrayCollection {
  T* data_;
  int size_;

 public:
  ArrayCollection() : size_(10) { data_ = new T[size_]; }
  ArrayCollection(int size, T* data) : size_(size) {
    data_ = new T[size_];
    for (int i = 0; i != size_; i++) {
      *(data_ + i) = *(data + i);
    }
  }
  ~ArrayCollection() { delete[] data_; }

  int size() { return size_; }
  T* begin();
  T* end();
};