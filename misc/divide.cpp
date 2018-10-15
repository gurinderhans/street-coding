#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
  int sign=1;

  long long dd=dividend;
  if(dd<0){
    dd=-dd;
    sign=-sign;
  }
  long long dv=divisor;
  if(dv<0){
    dv=-dv;
    sign=-sign;
  }

  long long adder=0;
  long long counter=0;
  while(adder<dd){
    adder+=dv;
    counter++;
  }

  if (counter>INT_MAX)
    return INT_MAX;

  int res=(adder>dd)?counter-1:counter;
      res=sign<0?-res:res;
  return res;
}

// 
// 1
int main() {
  int r=divide(2147483647,1);
  cout<<"final: "<<r<<endl;
  return 0;
}
