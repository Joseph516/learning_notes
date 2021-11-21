#include <iostream>
#include <string>

class Person {
  // 友元函数
  friend std::istream &read(std::istream &is, Person &person);
  friend std::ostream &print(std::ostream &os, const Person &person);

 private:
  std::string name_;
  std::string addr_;

 public:
  Person() = default;
  Person(const std::string &name, const std::string &addr)
      : name_(name), addr_(addr){};
  Person(std::istream &is) { read(is, *this); };
  ~Person(){};

  std::string const &get_name() const { return name_; }
  std::string const &get_addr() const { return addr_; }
};

std::istream &read(std::istream &is, Person &person) {
  // is读取const错误，需要转为非congst // 此方法不对
  // return is >> const_cast<std::string &>(person.get_name()) >>
  //        const_cast<std::string &>(person.get_addr());
  return is >> person.name_ >> person.addr_;
}

std::ostream &print(std::ostream &os, const Person &person) {
  return os << person.get_name() << " " << person.get_addr();
}

int main() {
  // 默认p1为空，从cin读入并输出
  Person p1 = Person();
  read(std::cin, p1);
  print(std::cout, p1);
  std::cout << std::endl;

  // 直接输出自定义的person
  Person p2 = Person("hyh", "铁道学院");
  print(std::cout, p2);
  std::cout << std::endl;

  Person p3 = Person(std::cin); 
  print(std::cout, p3);
  std::cout << std::endl;

  return 0;
}