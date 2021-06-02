#include <iostream>
#include <queue>
#include <vector>

int main() {
  struct cmp {
    bool operator() (const int& a, const int& b) const { return a > b; }
  };
  std::priority_queue<int, std::vector<int>, cmp> q;

  // std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  q.push(2);
  q.push(1);
  q.push(15);
  q.push(6);
  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }
  return 0;
}