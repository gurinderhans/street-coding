#include <iostream>
#include <sstream>

using namespace std;

int main(){

  string s;
  while(getline(cin,s)){
    istringstream ss(s);
    int a,b;ss>>a>>b;
    cout << (a > b ? a : b) << endl;
  }

  return 0;
}
