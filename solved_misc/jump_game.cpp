#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
  int mx=nums[0];
  for(int i=1;i<nums.size();++i){
    if(i>mx) break; // can't go further than the max reachable index!
    mx=max(mx, nums[i]+i);
  }
  return mx>=nums.size()-1;
}

int main() {
  vector<int> v{1,2,3};
  bool r=canJump(v);
  cout << r<< endl;
  return 0;
}
