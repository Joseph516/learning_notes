#include "anticlock_matrix.h"

AnticlockMatrix::AnticlockMatrix(int size)
    : Matrix(size), dir_('D'), row_(-1), col_(0) {}
AnticlockMatrix::~AnticlockMatrix() {}

int AnticlockMatrix::getPosition() {
  switch (dir_) {
    case 'D':
      if (row_ < size_ - 1 && *(data_ + col_ + (row_ + 1) * size_) == 0) {
        ++row_;
      } else {
        dir_ = 'R'; // 到头，改变至下一个方向
        ++col_;
      }
      break;
    case 'R':
      if (col_ < size_ - 1 && *(data_ + (col_ + 1) + row_ * size_) == 0) {
        ++col_;
      } else {
        dir_ = 'U';
        --row_;
      }
      break;
    case 'U':
      if (row_ > 0 && *(data_ + col_ + (row_ - 1) * size_) == 0) {
        --row_;
      } else {
        dir_ = 'L';
        --col_;
      }
      break;
    case 'L':
      if (col_ > 0 && *(data_ + (col_ - 1) + row_ * size_) == 0) {
        --col_;
      } else {
        dir_ = 'D';
        ++row_;
      }
      break;
    default:
      break;
  }
  //   std::cout << row_ << col_ << std::endl;
  return col_ + row_ * size_;
}