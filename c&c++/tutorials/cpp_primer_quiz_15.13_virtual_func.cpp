#include <iostream>
#include <string>

using namespace std;

class Base {
 public:
  Base(string basename) : basename_(basename) {}
  string name() { return basename_; };
  virtual void print(ostream &os) { os << basename_; }

 private:
  string basename_;
};

class Derived : public Base {
 public:
  Derived(string name) : Base(name) {}
  void print(ostream &os) override {
    Base::print(os);
    os << " derived\n" << i_;
  }

 private:
  int i_;
};

int main() {
  Base *p = new Derived("Tom");
  p->print(std::cout);
  delete p;
}