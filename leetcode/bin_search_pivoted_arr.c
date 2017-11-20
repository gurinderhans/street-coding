#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {

  int lo = 0, hi = numsSize-1;

  while (lo < hi) {
    int mid = (lo+hi)/2;

    if (nums[mid] == target) {
      return mid;
    } else if (nums[lo] <= nums[mid]) { // left side is sorted
      if (target >= nums[lo] && target < nums[mid]) {
        hi = mid-1;
      } else {
        lo = mid+1;
      }
    } else { // right side is sorted
      if (target > nums[mid] && target <= nums[hi]) {
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }
  }

  /* printf("lo=%d, hi=%d\n", lo,hi); */


  return nums[lo] == target ? lo : -1;
}

int main(){
  int SIZE = 2;
  int *nums = malloc(sizeof(int) * SIZE);
  /* nums[0]=6;nums[1]=7;nums[2]=1;nums[3]=2;nums[4]=3;nums[5]=4;nums[6]=5; */
  nums[0]=1;nums[1]=3;//nums[2]=5;

  int idx = search(nums, SIZE, 1);
  printf("idx = %d\n", idx);

  return 0;
}
