/* 在程序中输出一些信息，是一种很有效的调试方法。请设计实现一个名为Log的类，能方便输出调试信息：
   1. 支持使用流运算符输出调试信息，即
   Log obj;
   obj << "debug message" << endl;

   2. 支持对调试信息进行分级控制。在程序调试过程中，可以随时改变调试级别。
   如果调试级别（如error级别）高于某个输出信息的级别（如warning级别），则禁止输出该调试信息；反之则输出相应的调试信息。
   例如，下面是本题必须支持的一个示例代码片段：
   obj.set_level("error"); /// 此成员函数的效果是全局性的
   obj << level("warning") << "WARNING MESSAGE" <<endl;
   obj << level("fatal") << "BROKEN" <<endl;
   由于错误级别高低为：fatal > error > warning, 所以程序输出为BROKEN。
*/

#include <iostream>
#include <string>

// 错误级别
typedef enum level_type { warning, error, fatal } level_type;

// 错误等级转换
level_type level(std::string s) {
  if (s == "error") {
    return error;
  } else if (s == "fatal") {
    return fatal;
  } else {
    return warning;
  }
}

class Log {
 private:
  std::ostream& out;
  level_type base_level = warning;
  level_type curr_level = warning;

 public:
  Log() : out(std::cerr) {}
  ~Log() {}
  // 重载stream
  template <typename T>
  Log& operator<<(const T& v) {
    // 当比基准错误等级高时输出
    if (curr_level >= base_level) {
      out << v;
    }
    return *this;
  }
  Log& operator<<(std::ostream& (*pf)(std::ostream&)) {
    // 当比基准错误等级高时输出
    if (curr_level >= base_level) {
      pf(out);
    }
    return *this;
  }
  Log& operator<<(level_type t) { curr_level = t; }

  // 设置错误等级
  void set_level(std::string s) { base_level = level(s); }
};

int main(void) {
  Log obj;
  obj << "debug message" << std::endl;

  obj.set_level("error");  /// 此成员函数的效果是全局性的
  obj << level("warning") << "WARNING MESSAGE" << std::endl;
  obj << level("fatal") << "BROKEN" << std::endl;
  return 0;
}