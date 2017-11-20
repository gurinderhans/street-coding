#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

vector<string> rows {
  "qwertyuiop",
  "asdfghjkl",
  "zxcvbnm"
};

pair<int, int> get_loc(char c)
{
  for (int i=0; i<rows.size(); ++i)
  {
    int idx=rows[i].find(c);
    if(idx != string::npos)
    {
      return make_pair(i, idx);
    }
  }
  return make_pair(-1,-1);
}

int get_dist(char a, char b)
{
  int dist=0;

  auto aLoc = get_loc(a);
  auto bLoc = get_loc(b);

  dist = abs(aLoc.first - bLoc.first) + abs(aLoc.second - bLoc.second);

  return dist;
}

int main()
{
  int T; cin>>T;
  while(T--)
  {
    string w; int dict_count;
    cin>>w>>dict_count;

    vector<pair<string, int>> words;

    while(dict_count--)
    {
      string ow;cin>>ow;
      int total_dist=0;
      for (int i=0;i<w.size();++i)
      {
        total_dist+=get_dist(w[i], ow[i]);
      }

      words.push_back(make_pair(ow, total_dist));
    }

    sort(words.begin(), words.end(), [](pair<string, int> &left, pair<string, int> &right) {
        if (left.second == right.second)
        return left.first < right.first;
      return left.second < right.second;
    });

    for (auto i : words)
    {
      cout << i.first << " " << i.second << endl;
    }
  }

  return 0;
}
