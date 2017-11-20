#include <iostream>

using namespace std;

pair<int,int> try_(string s, int i, int j) {
  while(s[i]==s[j] && i>0 && j<s.size()) {
    --i;j++;
  }
  if (s[i]!=s[j]){
    i++;--j;
  }

  return {i,j};
}

string longestPalindrome(string s) {
  pair<int,int> range;
  int maxLen=0;
  for(int i=0;i<s.size();++i){
    auto l1=try_(s,i,i);
    auto l1Len=l1.second-l1.first+1;
    if(l1Len>maxLen){
      maxLen=l1Len;
      range=l1;
    }

    auto l2=try_(s,i,i+1);
    auto l2Len=l2.second-l2.first+1;
    if(l2Len>maxLen){
      maxLen=l2Len;
      range=l2;
    }
  }

  return s.substr(range.first, range.second-range.first+1);
}

int main() {
  string r=longestPalindrome("aba");
  cout<<r<<endl;
  r=longestPalindrome("cbbd");
  cout<<r<<endl;
  r=longestPalindrome("abba");
  cout<<r<<endl;
  r=longestPalindrome("aba");
  cout<<r<<endl;
  // cout<<r<<endl;
  return 0;
}
