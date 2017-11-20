#include <stdio.h>
#include <string.h>

void reverseInPlace(char s[])
{
  int sSize = strlen(s);

  for (int i=0; i<sSize/2; ++i)
  {
    int lI = i;
    int rI = sSize-i-1;

    char tmp = s[lI];
    s[lI] = s[rI];
    s[rI] = tmp;
  }
}

void reverseInPlace2(char * str)
{
  char* end = str;
  char tmp;
  if (str)
  {
    while(*end)
    {
      ++end;
    }
    --end;
    while(str < end)
    {
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
}



int main(){
  char name[] = "abcd";
  reverseInPlace2(name);
  reverseInPlace(name);
  printf("%s\n", name);
  return 0;
}
