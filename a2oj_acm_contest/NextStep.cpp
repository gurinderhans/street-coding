#include <iostream>

using namespace std;

int main() {
  int n;cin>>n;
  while(n--){
    int a,b;cin>>a>>b;
    if (b!=a && b!=a-2){
      cout << "No Number"<<endl;
      continue;
    }

    if (a==b){
      if (a%2+b%2==0){
        cout << 2*a;
      }else
        cout << (a*2)-1;
    } else {
      if (a%2+b%2==0)
        cout << a+b;
      else cout << (a+b)-1;
    }
    cout << endl;
  }

  return 0;
}
