#include <iostream>

using namespace std;

int main()
{
  int L,R; cin>>L>>R;
  if (L==0 && R==0)
  {
    cout << "Not a moose" << endl;
  }
  else if (L==R)
  {
    cout << "Even " << L+R<<endl;
  }
  else
  {
    cout << "Odd " << (L>R?L:R)*2 << endl;
  }
  return 0;
}
