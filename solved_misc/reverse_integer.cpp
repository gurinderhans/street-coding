#include <iostream>

using namespace std;

int reverse(int x)
{
  long long rev=0;
  int i=0;
  while(x){
    int dig=x%10;
    rev = (rev*10)+dig;
    x /= 10;
  }
  
  if(rev > INT_MAX || rev < INT_MIN) return 0;

  return rev;
}

int main()
{
  int ans=reverse(12345678);
  cout << ans << endl;

  return 0;
}
