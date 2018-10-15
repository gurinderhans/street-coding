#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

  public:
    stack<int> A, B;
    void push(int x) {

      // first empty out stack A into B
      while (!A.empty()) {
        int top = A.top();
        A.pop();
        B.push(top);
      }

      // add `x` to A
      A.push(x);

      // refill A by emptying out B
      while(!B.empty()) {
        int top = B.top();
        B.pop();
        A.push(top);
      }
    }

    void pop() {
      A.pop();
    }

    int front() {
      return A.top();
    }
};

int main() {

  MyQueue qq;
  qq.push(2);
  qq.push(3);
  qq.push(4);
  qq.push(10);
  cout << qq.front() << endl;
  qq.pop();
  qq.pop();
  qq.pop();
  cout << qq.front() << endl;

  return 0;
}
