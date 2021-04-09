#pragma once

template <typename T>
class Iterator {
 public:
  virtual ~Iterator(){};
  virtual bool operator!=(const Iterator& other) const = 0;
  virtual const Iterator& operator++() = 0;
  virtual const Iterator& operator++(int) = 0;
  virtual T& operator*() const = 0;
  virtual T* operator->() const = 0;
  bool operator==(const Iterator& other) const { return !(*this != other); }
};