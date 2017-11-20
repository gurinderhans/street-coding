#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v){
  for (int s:v){
    cout << s << " ";
  }
  cout << endl;
}

int remove(vector<int>& nums){
  if(nums.size()==0) return 0;
  int i=0,j=1;
  while(j<nums.size()) {
    if(nums[i]==nums[j]){
      while(nums[i]==nums[j]) j++;
      if(j<nums.size()){
        swap(nums[i+1],nums[j]);
        i++;
      }
    }else if (nums[i]<nums[j]) {
      if(i+1==j){
        i++;j++;
      }else{
        swap(nums[i+1],nums[j]);
        i++;
      }
    }
    else {
      j++;
    }
  }
  return i+1;
}

int main() {
  vector<int> v{1,1,2,3};
  int len=remove(v);
  cout << "len: " << len << endl;
  print(v);
  return 0;
}
