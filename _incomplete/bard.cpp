#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  
  int N,E; cin>>N>>E;
  int songs=0;
  unordered_map<int,int> vrec;

  while(E--)
  {
    vector<int> vs;
    bool newsong=false;
    int esum=0;

    int n;cin>>n;while(n--)
    {
      int v;cin>>v;
      vs.push_back(v);

      if (v==1)
      {
        newsong=true;
        songs++;
      }
      else
      {
        esum+=vrec[v];
      }
    }

    if (newsong)
    {
      for (int v:vs)
      {
        vrec[v]++;
      }
    }
    else
    {
      for(int v:vs)
      {
        vrec[v]+=esum-vrec[v];
      }
    }
  }

  vector<int> res;
  for(auto v:vrec)
  {
    if(v.second==songs)
    {
      res.push_back(v.first);
    }
  }

  sort(res.begin(),res.end());
  for(int i:res)
  {
    cout << i << endl;
  }


  return 0;
}
