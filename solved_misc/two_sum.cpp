#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

vector<int> two_sum(vector<int> &v, int target)
{
  unordered_map<int,pair<int,int>> m;
  for (int i=0;i<v.size();++i)
  {
    m[target-v[i]] = make_pair(v[i],i);
  }
  
  for (int i=0;i<v.size();++i)
  {
    if (m.find(v[i]) != m.end())
    {
      if (i!=m[v[i]].second)
        return {i, m[v[i]].second};
    }
  }

  return {};
}

int main()
{
  vector<int> a {3,2,4};
  int target = 6;

  vector<int> ans=  two_sum(a, target);

  cout << "first: " << ans[0] << ", second: " << ans[1] << endl;
  cout << "vfirst: " << a[ans[0]] << ", vsecond: " << a[ans[1]] << endl;

  return 0;
}
