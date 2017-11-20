#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int T; cin >>T;
  while(T--){
    int N;cin>>N;
    vector<int> a,b;
    for (int i=0;i<N;++i){
      int v;cin>>v;
      a.push_back(v);
    }
    for (int i=0;i<N;++i){
      int v;cin>>v;
      b.push_back(v);
    }

    //sort
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int sum=0;
    auto ia=a.begin();
    auto ib = b.begin();
    for (int i=0;i<N;++i){
      sum+=(*(ia++))*(*(ib++));
    }
    cout << sum<<endl;
  }
  return 0;
}
