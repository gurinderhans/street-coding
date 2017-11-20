#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int mxArea=0;

  int i=0;
  int j=height.size()-1;
  while(i<j) {
    int hi=height[i];
    int hj=height[j];
    int newArea=min(hi,hj)*(j-i);
    if (newArea>mxArea)mxArea=newArea;
    if (hi<hj) {
      i++;
    } else {
      j--;
    }
  }

  return mxArea;
}

int main() {
  vector<int> v{1,2,1,2,2};
  int r=maxArea(v);
  cout <<r;
  cout << endl;
  return 0;
}
