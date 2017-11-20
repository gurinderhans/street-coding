#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int myAtoi(char* str) {
  int ret=0;

  int shouldLookForPlusOrMinus = 1;
  int isNeg = 0;

  int len=strlen(str);
  for (int i=0; i<len; ++i){
    int c = (int)str[i];
    if (c ==32) {
      printf("never her..\n");
      continue;
    }
    if (shouldLookForPlusOrMinus ==1 && str[i] == '-') {
      isNeg = 1;
    }
    if (c >=48 && c <=57) {
      shouldLookForPlusOrMinus = 0;
      ret = (ret * 10) + (c-48);
    }
  }

  return isNeg ? ret * -1 : ret;
}

int main() {
  int r = myAtoi("aa123a3da");
  printf("r: %d\n", r);
  return 0;
}
