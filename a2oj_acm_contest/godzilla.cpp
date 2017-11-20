#include <iostream>
#include <vector>
#include <set>

using namespace std;
void printSet(set<int> s){
  for(auto i:s){
    cout << i << " ";
  }
  cout << endl;
}

void gameOn(){
  int ng,nm; cin>>ng>>nm;
  set<int> ga,ma;
  while(ng--){
    int s;cin>>s;
    ga.insert(s);
  }
  while(nm--){
    int s;cin>>s;
    ma.insert(s);
  }

  while(ga.size() > 0 && ma.size() > 0){//fight
    int gv=*ga.begin();
    int mv=*ma.begin();

    if (gv==mv || gv>mv) ma.erase(mv);
    else ga.erase(gv);
  }

  // printSet(ga);
  // printSet(ma);

  if(ga.size()>0)
    cout << "Godzilla";
  else if (ma.size()>0)
    cout << "MechaGodzilla";
  else
    cout << "uncertain";

  cout << endl;
}

int main(){
  int T; cin >>T;
  while(T--){
    gameOn();
    // break;
  }
  return 0;
}
