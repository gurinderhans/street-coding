#include <iostream>

using namespace std;

bool isPalindrome(int x) {
  if (x<0) return false;
  int cx=x;
  int rev=0;
  while(x){
    rev = (rev*10)+(x%10);
    x/=10;
  }
  return rev==cx;
}

int main() {
  bool ans=isPalindrome(01);
  cout << ans<<endl;
  return 0;
}
