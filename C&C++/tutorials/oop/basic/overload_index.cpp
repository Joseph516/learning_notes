/* 为了统计全年级学生考试成绩的分数段分布情况，即1～10、11～20、21～30、...、91～100等各个分数段的学生人数，
拟设计实现一个重载了下标运算符的类，该类对象使用元素为考试成绩的数组和数组元素个数来初始化，
当使用0～9的整数下标k来访问该对象时，返回 第k分数段（10*k + 1 <= e <= 10*k +
10）中的元素个数。
*/

#include <iostream>

class Grades {
 private:
  float *scores_;  // 成绩数组
  int nums_;       // 学生人数

 public:
  Grades() {}
  Grades(int nums) : nums_(nums) {}
  ~Grades() {
    if (scores_) {
      delete[] scores_;
    }
  }

  void GetScores() {
    std::cout << "输入学生人数：";
    std::cin >> nums_;
    scores_ = new float[nums_];

    for (int i = 0; i < nums_; i++) {
      std::cout << "输入第" << i + 1 << "学生分数：";
      std::cin >> scores_[i];
    }
  }

  int operator[](int k) {
    int count = 0;
    for (int i = 0; i < nums_; i++) {
      if (scores_[i] >= 10 * k + 1 && scores_[i] <= 10 * k + 10) {
        ++count;
      }
    }
    return count;
  }
};

int main(void) {
  //   Grades test(10);
  Grades test;
  test.GetScores();

  int k = 0;
  std::cout << k << "分段人数：" << test[k];
}