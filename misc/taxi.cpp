#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  while (a<=c)
  {
  cout << a << " " << c << endl;
    a+=b;
  cout << a << " " << c << endl;
    if(a>c)a=c;
  cout << a << " " << c << endl;
    c-=d;
  cout << a << " " << c << endl;
  }
  // cout << a << " " << c << endl;

  return 0;
}
