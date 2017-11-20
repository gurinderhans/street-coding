#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void swap(vector<int> &v, int i, int j) {
      int tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }

    void _permute(vector<int> &nums, int numsIdx, vector<vector<int> > &retArrs) {
      if (nums.size() == numsIdx) {
        // retArrs->push(nums);
        retArrs.push_back(nums);
        return;
      }

      for (int i=numsIdx; i<nums.size(); ++i) {
        swap(nums, numsIdx, i);
        _permute(nums, numsIdx+1, retArrs);
        swap(nums, numsIdx, i);
      }
    }

    vector<vector<int> > permute(vector<int>& nums) {
      vector<vector<int> > *retArrs = new vector<vector<int> >();
      _permute(nums, 0, *retArrs);
      return *retArrs;
    }
};


void printArr(vector<int> &arr) {
  for (int i=0; i<arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  vector<int> nums = {1,2,3,4,5,6,7};

  auto s = Solution().permute(nums);
  for (auto i : s) {
    printArr(i);
  }

  return 0;
}
