// 左闭右开区间

#include "iterator.h"

template <typename T>
class Collection {
 public:
  virtual ~Collection() {}
  virtual Iterator<T> *begin() const = 0;
  virtual Iterator<T> *end() const = 0;
  virtual int size() = 0;
};