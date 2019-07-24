// 参考https://blog.csdn.net/qq_29924041/article/details/74857469

#include <iostream>

// 回调函数类
class CallBack {
  public:
  virtual int getEvenNumber(int x) const = 0;
};

// 库函数类
class Compute {
  public:
  // ! 调用Application中重写的回调函数
  Compute(CallBack *mcallback)
      : mcallback_(mcallback) {
  }
  ~Compute() {
  }

  // 被调用的库函数
  int getOddNumber(int x) {
    int temp = 0;
    if (mcallback_ != NULL) {
      temp = mcallback_->getEvenNumber(x);
    }
    return 1 + temp;
  }

  private:
  CallBack *mcallback_;
};

// 应用函数类
class Application : public CallBack {
  public:
  Application() {
    // ! 关键，将自身传入库函数，相当于登记回调函数。
    mcompute_ = new Compute(this); 
  }
  ~Application() {
    if (mcompute_ != NULL) {
      delete mcompute_;
      mcompute_ = NULL;
    }
  }

  // 编写函数调用库函数
  void getNumber(int x) {
    int res = mcompute_->getOddNumber(x);
    std::cout << res << std::endl;
  }

  // 自定义回调函数，可以是2×k，4×k等。
  int getEvenNumber(int x) const {
    // return x * 2;
    return x * 4;
  };

  private:
  Compute *mcompute_;
};

int main(int argc, const char *argv[]) {
  int x = 3;

  Application test;

  test.getNumber(x);

  return 0;
}