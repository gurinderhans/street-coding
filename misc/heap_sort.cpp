#include <iostream>

using namespace std;

void heapify_down(int arr[], int n, int i) {
  int l = (2*i)+1;
  int r = (2*i)+2;

  int mx=i;

  if(l < n && arr[l] > arr[mx])
    mx=l;

  if(r < n && arr[r] > arr[mx])
    mx=r;

  if(mx != i)
  {
    swap(arr[mx], arr[i]);

    heapify_down(arr, n, mx);
  }
}

void heap_sort(int arr[], int len) {
  for (int i=(len/2)-1; i>-1; --i)
  {
    heapify_down(arr, len, i);
  }

  for (int i=len-1;i>-1;--i){
    swap(arr[0],arr[i]);
    heapify_down(arr, i, 0);
  }
}

int main() {
  int arr[] = {2,3,8,4,9,5,0,1};

  heap_sort(arr, sizeof(arr)/sizeof(int));
  for(int i=0;i<8;++i) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
