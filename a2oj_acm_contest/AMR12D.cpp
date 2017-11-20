#include <iostream>

using namespace std;

int main() {

  int n;cin>>n;
  while(n--){
    string s;cin>>s;
    bool aintIt=false;
    int mid=s.size()/2;
    for (int i=mid-1;i>=0;--i){
      if(s[i]!=s[s.size()-i-1]){
        aintIt=true;
        break;
      }
    }
    if(aintIt)
      cout << "NO";
    else cout << "YES";
    cout<<endl;
  }

  return 0;
}
