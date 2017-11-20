#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  int N; cin >> N;

  unordered_set<string> ffs;
  unordered_set<string> fs;

  while (N--){
    string fid; cin >> fid;
    fs.insert(fid);

    int ffc; cin >> ffc;
    while(ffc--){
      string ffid; cin >> ffid;
      ffs.insert(ffid);
    }
  }

  for (string fid : fs)
    if (ffs.find(fid) != ffs.end())
      ffs.erase(fid);

  cout << ffs.size() << endl;

  return 0;
}
