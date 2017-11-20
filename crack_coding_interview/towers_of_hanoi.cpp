#include <iostream>
#include <vector>

using namespace std;

void move(vector<int> &from, vector<int> &aux, vector<int> &to) {
  while (!from.empty()) {
    int el = from.back(); from.pop_back();
    if (to.back() > el) {
      to.push_back(el);
    } else if (aux.back() > el) {
      aux.push_back(el);
    } else {
      int c=0;
      while (!aux.empty()) {
        from.push_back(aux.back());
        aux.pop_back();
        c++;
      }

      while (c--) {
        to.push_back(from.back());
        from.pop_back();
      }
    }
  }
}

int main() {

  vector<int> from = { 3,2,1 };
  vector<int> aux = {};
  vector<int> to = {};

  move(from, aux, to);

  return 0;
}
