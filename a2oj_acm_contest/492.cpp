#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isVowel(char c) {
  char f = (c>='A' && c <='Z' ? c+32 : c);
  return f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u';
}

int main() {

  string s;
  while(getline(cin, s)) {
    s+='\n';

    string word;
    for (int i=0;i<s.size();++i){
      char c=s[i];

      char lc=c>='A'&&c<='Z'?c+32:c;
      if (lc>='a'&&lc<='z'){
        word+=c;
      } else {
        if(word.size()>0){
          if(isVowel(word[0])){
            cout << word;
          }else{
            cout << word.substr(1) << word[0];
          }
          cout <<"ay";
          word.clear();
        }
        cout << c;
      }
    }
  }

  return 0;
}
