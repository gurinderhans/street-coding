#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pvtor(vector<int> ss){
  for(int s : ss){
    cout << s << " ";
  }
  cout << endl;
}

int main(){
  for (;;){
    int a,b;cin>>a>>b;

    if(a+b==0) break;

    vector<int> ak,df;
    while(a--){
      int v;cin>>v;
      ak.push_back(v);
    }
    while(b--){
      int v;cin>>v;
      df.push_back(v);
    }
    sort(ak.begin(),ak.end());
    sort(df.begin(), df.end());

    int d1=df[0];
    int d2=df[1];
    int a1=ak[0];

    bool offside=(a1<d2);

    cout << (offside ? "Y" : "N") << endl;

  }
}

