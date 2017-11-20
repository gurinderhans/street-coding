#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool isAnagram(string a, string b){
  unordered_map<char, int> m;
  for(char s:a){
    char ss=(s>='A'&&s<='Z' ? s+32 : s);
    m[ss]++;
  }
  for(char s:b){
    char ss=(s>='A'&&s<='Z' ? s+32 : s);
    m[ss]--;
  }

  for (auto i:m) if (i.second != 0) return false;

  return true;
}
void pv(vector<string> v){
  for(string s:v){
    cout << s << " ";
  }
  cout << endl;
}

int main(){
  vector<string> wl;
  for(;;){
    string s;cin>>s;
    if (s=="#")
      break;

    wl.push_back(s);
  }

  vector<string> r;
  for(int i=0;i<wl.size();++i){
    bool y=false;
    for(int j=0;j<wl.size();++j){
      if(i==j) continue;
      if (isAnagram(wl[i],wl[j])){
        y=true;
        break;
      }
    }
    if(!y)
      r.push_back(wl[i]);
  }

  sort(r.begin(), r.end());

  for(string s:r){
    cout << s<<endl;
  }

  return 0;
}
