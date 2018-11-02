#include <iostream>
#include <vector>

using namespace std;

string reduce(string sinp) {
  string s=sinp;
  while(1) {
    vector<bool> marker(s.size());
    for(int i=1;i<s.size();++i) {
      if(s[i-1]==s[i] && !marker[i-1] && !marker[i]){
        marker[i-1]=marker[i]=true;
      }
    }
    bool didRemove=false;
    string tmp;
    for(int i=0;i<marker.size();++i) {
      if(!marker[i]){
        tmp+=s[i];
      } else {
        didRemove=true;
      }
    }
    if (!didRemove) {
      break;
    }
    s=tmp;
  }

  return s;
} 

int main(){
  string s="aa";
  string res=reduce(s);
  if (res.size()==0){
    cout << "Empty String" << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}
