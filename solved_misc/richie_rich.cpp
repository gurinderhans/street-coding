#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool is_palindrome(string &s);

// GET RICH STUPID WAY!!!!! (takes waaaay too long w/ backtracing)
bool get_rich_stupid(string &s, int k, int start, int end) {
  if (start>end || k<1) {
    return is_palindrome(s);
  }

  char a=s[start];
  char b=s[end];

  if (a != '9' && b != '9' && k > 1) {
    s[start]=s[end]='9';
    bool ok=get_rich_stupid(s, k-2, start+1, end-1);
    if(!ok){ // ROLLBACK
      s[start]=a; s[end]=b;
    } else {
      return true;
    }
  }
  
  if (a == b) {
    if (start == end) {
      s[start]='9';
      return get_rich_stupid(s,k-1, start+1, end-1);
    }
    return get_rich_stupid(s, k, start+1, end-1);
  }

  s[start]=s[end]=max(a,b);
  bool ok=get_rich_stupid(s, k-1, start+1, end-1);
  if(!ok){ // ROLLBACK
    s[start]=a; s[end]=b;
  }
  return ok;
}

// PLS.
bool is_palindrome(string &s) {
  int slen=s.size();
  int l=slen%2==0 ? (slen/2) - 1 : slen/2;
  int r=slen/2;

  while (l>=0 && r<slen) {
    if(s[l]!=s[r]){
      return false;
    }
    --l;r++;
  }
  return true;
}

bool get_rich_overnight(string &s, int k) {
  int slen=s.size();
  int smid=slen/2;
  vector<bool> marker(smid, false);

  for(int i=0;i<smid;++i) {
    char a=s[i];
    char b=s[slen-i-1];
    if (k<=0)
      break;
    if(a!=b){
      s[i]=s[slen-i-1]=max(a,b);
      marker[i]=true;
      k--;
    }
  }

  for (int i=0;i<marker.size();++i) {
    if(s[i]=='9')
      continue;
    if (k<=0)
      break;

    if (marker[i]) {
      k-=1;
    } else {
      if(k<2) {
        break;
      }
      k-=2;
    }

    if (k>=0) {
      s[i]=s[slen-i-1]='9';
    }
  }

  if(slen%2!=0 && k>0 && s[smid]!='9') {
    s[smid]='9';
  }

  return is_palindrome(s);
}

void get_rich(string s, int k) {
  bool ok=get_rich_overnight(s, k);
  if(ok){
    cout << s;
  } else {
    cout << -1;
  }
  cout << endl;
  
  // get_rich_stupid(s, k, 0, s.size()-1);
}

int main() {
  int k; cin >> k >> k;
  string s; cin>>s;
  get_rich(s,k);
  return 0;
}
