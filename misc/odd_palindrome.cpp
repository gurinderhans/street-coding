#include <iostream>

using namespace std;

int plen(string s, int i, int j) {
  while(i>=0 && j<s.size() && s[i]==s[j]) {
    i--; j++;
  }
  if(s[i]!=s[j])
  {
    i++; j--;
  }
  return j-i+1;
}

bool isOdd(string s) {
  for (int i=0;i<s.size();++i) {
    int b=plen(s,i,i+1);
    if (b>0)
      return false;
  }
  return true;
}

int main() {
  string p="annamyfriend";
  if (isOdd(p))
    cout << "Odd.";
  else cout << "Or not.";
  cout << endl;
  return 0;
}
