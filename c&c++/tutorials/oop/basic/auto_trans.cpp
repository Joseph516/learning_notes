#include <iostream>
using namespace std;

void func(int i) {
  cout << "Call func int" << endl;
}
// void func(char c) = delete;

int main() {
  func(1);
  func('a');
}