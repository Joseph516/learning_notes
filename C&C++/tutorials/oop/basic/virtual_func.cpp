#include <iostream>
using namespace std;

class Base {
 public:
//   void print() { cout << "Base print" << endl; }
  virtual void print() { cout << "Base print" << endl; }

};

class Derived : public Base {
 public:
  void print() { cout << "Derived print" << endl; }
};

void func(Base& obj) { obj.print(); }

int main() {
  Derived d;
  d.print();  // Derived print
  func(d);    // Base print
  return 0;
}