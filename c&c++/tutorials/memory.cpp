#include <iostream>
using namespace std;

int main() {
  char *p = new char[50];
  for (int i = 0; i < 50; i++) {
    cout << (int *)&p[i] << endl;
  }
  delete[] p;
  return 0;
}

/*
output：
0x7fe275c058e0
0x7fe275c058e1
0x7fe275c058e2
0x7fe275c058e3
0x7fe275c058e4
0x7fe275c058e5
*/