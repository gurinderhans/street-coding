#include <iostream>
#include <math.h>

using namespace std;

using ll=long long;

int main(){
  int t;cin>>t;
  while(t--){
    ll a,b;cin>>a>>b;

    if (b==0){
      cout << 1<<endl;
      continue;
  }

    int md = b%4;
    if (md==0)
      md=4;

    ll ans = pow(a,md);

    int aa = ans%10;
    cout << (aa) << endl;
  }
}

