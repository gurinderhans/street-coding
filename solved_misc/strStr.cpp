#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
  if (needle.size()==0)
    return 0;

  for (int i=0;i<haystack.size();++i){
    if(needle[0]==haystack[i]){
      bool didMatch=true;
      for(int j=1;j<needle.size();++j){
        if(needle[j]!=haystack[i+j]){
          didMatch=false;
          break;
        }
      }
      if(didMatch){
        return i;
      }
    }
  }
  return -1;
} 

int main(){
  int s=strStr("HelloO", "ello");
  cout <<s<<endl;

  return 0;
}
