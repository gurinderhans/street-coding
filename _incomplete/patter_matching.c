#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool confirmMatch(char *str, int ssize, int sidx, char *pattern, int psize) {
  for (int i=0; i<psize; ++i, ++sidx) {
    if (pattern[i] == '*') {
      char p_next = pattern[i+1];
      while(sidx < ssize) {
        if (str[sidx] == p_next) {
          // we get an extra increment, because of the increment
          // in the main loop level, so we undo that here
          --sidx;
          break;
        }
        ++sidx;
      }
    } else if (pattern[i] != str[sidx]) {
      return false;
    }
  }
  return true;
}

int findIndex(char *str, int ssize, char *pattern, int psize) {
  for (int i=0; i<ssize; ++i) {
    if (str[i] == pattern[0]) {
      if (confirmMatch(str,ssize,i,pattern,psize)) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  char *str = "helloworldiamme";
  char *p = "w*m";
  printf("idx: %d\n", findIndex(str, 15, p, 3));
  return 0;
}
