#include <iostream>
#include <vector>
#include <string>

using namespace std;

string prefix(vector<string>& strs, int i) {
  if(strs.size()==0 || i >= strs[0].size()) return "";
  char s=strs[0][i];
  for(int j=1;j<strs.size();++j){
    if(strs[j][i]!=s){
      return "";
    }
  }
  return string(1,s)+prefix(strs, i+1);
}

string longestCommonPrefix(vector<string>& strs) {
  return prefix(strs,0);
}

int main() {
  vector<string> v{"a"};
  string r=longestCommonPrefix(v);
  cout<<"res: " << r<<endl;
  return 0;
}
