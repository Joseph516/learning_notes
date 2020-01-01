#ifndef _ANTICLOCK_MATRIX_H_
#define _ANTICLOCK_MATRIX_H_
#include "matrix.h"

class AnticlockMatrix : public Matrix {
 private:
  char dir_;       // 移动方向
  int row_, col_;  // 当前坐标

 public:
  AnticlockMatrix(int size);
  ~AnticlockMatrix();
  // 逆时针获取方阵位置
  int getPosition();
};

#endif