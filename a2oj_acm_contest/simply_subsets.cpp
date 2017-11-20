#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  string A,B;
  for(;;){
    getline(cin,A);
    getline(cin,B);
    if (!cin) break;

    istringstream a(A);
    istringstream b(B);

    set<string> sa,sb;
    while (!a.eof()){
      string v; a >> v;
      sa.insert(v);
    }
    while(!b.eof()){
      string v; b>>v;
      sb.insert(v);
    }

    if (sa==sb){
      cout << "A equals B" << endl;
    } else if (includes(sa.begin(), sa.end(), sb.begin(), sb.end())){
      cout << "B is a proper subset of A" << endl;
    } else if (includes(sb.begin(), sb.end(), sa.begin(), sa.end())){
      cout << "A is a proper subset of B" << endl;
    } else {
      vector<string> out(sa.size()+sb.size());
      auto it = set_intersection(sa.begin(), sa.end() ,sb.begin(), sb.end(), out.begin());
      out.resize(it-out.begin());
      if (out.size() == 0){
        cout << "A and B are disjoint" << endl;
      } else {
        cout << "I'm confused!" << endl;
      }
    }
  }

  return 0;
}
