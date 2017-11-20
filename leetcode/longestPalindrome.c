#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extendPalindrome(char *s, int len, int j, int k, int *maxLen, int *maxLo) {
  while (j >= 0 && k < len && s[j] == s[k]) {
    j--;
    k++;
  }
  if (*maxLen < k - j - 1) {
    *maxLo = j + 1;
    *maxLen = k - j - 1;
  }
}

char * longestPalindrome(char *s) {
  int len = strlen(s);

  if (len < 2)
    return s;

  int maxLen=0;
  int maxLo=-1;

  for (int i = 0; i < len-1; i++) {
    extendPalindrome(s,     len,    i, i,       &maxLen, &maxLo);  //assume odd length, try to extend Palindrome as possible
    extendPalindrome(s,     len,    i, i+1,     &maxLen, &maxLo); //assume even length.
  }

  char *new_str = malloc(sizeof(char) * (maxLen-1));
  for (int i=0; i<maxLen; ++i) {
    new_str[i] = s[i+maxLo];
  }

  return new_str;
}

int main() {
  char *a = longestPalindrome("hiabcbahi");
  printf("longest = [%s]\n", a);

  return 0;
}
