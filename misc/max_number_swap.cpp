#include <iostream>
#include <set>

using namespace std;

struct Comparator {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    if (a.first==b.first){
      return a.second<b.second;
    }
    return a.first>b.first;
  }
};

int maximumSwap(int num) {
  string snum=to_string(num);

  multiset<pair<int, int>, Comparator> mm;
  for(int i=0;i<snum.size();++i){
    mm.insert({48+snum[i],i});
  }

  int i=0;
  for (auto it=mm.begin();it!=mm.end();++it){
    if(i!=it->second){
      int itVal=it->first;
      while(it->first==itVal) it++;
      swap(snum[(--it)->second], snum[i]);
      break;
    }
    i++;
  }
  return stoi(snum);
}

int main()
{
  int r=maximumSwap(9918863);
  cout << r<<endl;

  return 0;
}
