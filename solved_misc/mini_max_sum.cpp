#include <iostream>
#include <vector>

using namespace std;

void mini_max_sum(vector<int> &arr) {
  long long int maxSum=0;
  long long int minSum=0;
  for (int i=0; i<4;++i) {
    maxSum+=arr[i];
    minSum+=arr[i];
  }

  long long int currSum=maxSum;
  for (int i=0;i<4;++i) {
    currSum -= arr[i];
    currSum += arr[(4+i) % 5];
    
    maxSum=max(maxSum, currSum);
    minSum=min(minSum, currSum);
  }

  cout << minSum << " ";
  cout << maxSum << endl;
}

void CORRECT(vector<int> &v) {
  sort(v.begin(), v.end());

  int min_sum = 0;
  int max_sum = 0;

  for(int i=0;i<v.size()-1;++i)
    min_sum+=v[i];

  for(int i=1;i<v.size();++i)
    max_sum+=v[i];

  cout << min_sum << " ";
  cout << max_sum << endl;
}

int main() {

  vector<int> arr = {1,0,1,0,1};

  mini_max_sum(arr);
  CORRECT(arr);

  return 0;
}
