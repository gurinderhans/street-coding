#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {

  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    string s; getline(cin>>ws,s);
    istringstream ss(s);
    unordered_map<int,int> cnt;
    while(!ss.eof()){
      int v;ss>>v;
      cnt[v]++;
    }
    int mx=-1;
    int maj;
    for(auto it : cnt){
      if (it.second>mx){
        mx=it.second;
        maj=it.first;
      } else if (it.second==mx){
        mx=-1;
        maj=-1;
      }
    }

    cout << maj<<endl;
  }

  return 0;
}
