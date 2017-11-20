#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

  ostringstream out;

  string s;
  while (getline(cin, s)) {

    unordered_map<int, int> charMap;
    for (int i =0; i<s.size() ; charMap[s[i++]]++);

    vector<pair<int, int> > v;
    for (auto s : charMap)
      v.push_back({s.first, s.second});

    std::sort(v.begin(), v.end(), [](pair<int,int> &left, pair<int, int> &right) {
      if (left.second == right.second)
        return left.first > right.first;
      else
        return left.second < right.second;
    });

    for (auto i : v){
      out << i.first << " " << i.second << endl;
    }

    out << endl;
  }

  string ostr = out.str();
  cout << ostr.substr(0,ostr.size()-1);

  return 0;
}
