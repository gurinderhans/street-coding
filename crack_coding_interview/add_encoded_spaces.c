#include <stdio.h>
#include <string.h>

void add520spaces(char str[])
{
  int oldSz = strlen(str);
  int newSz = oldSz;
  for (int i = 0; i < oldSz; ++i)
    if (str[i] == ' ')
      newSz+=2;
  
  str[newSz] = '\0';
  for (int i = oldSz-1, j = newSz-1; i > 0; --i, --j) {
    if (str[i] != ' ') {
      str[j] = str[i];
    } else {
      str[j-2] = '%';
      str[j-1] = '2';
      str[j-0] = '0';
      j-=2;
    }
  }

}

int main()
{
  char str[] = "hello how are you?";
  add520spaces(str);
  printf("new: %s\n", str);
  return 0;
}
