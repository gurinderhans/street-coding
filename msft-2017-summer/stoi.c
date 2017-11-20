#include <stdio.h>
#include <math.h>

int stoi(char ** pc)
{
  char *rev=0x0;
  for(char *c=*pc;*c>='0'&&*c<='9';c++)
  {
    rev=c;
  }

  int res=0;
  for(char *c=rev,p=0;c!=(*pc)-1;--c,++p)
  {
    res+=pow(10,p)*(*c - 48);
  }
  return res;
}

int main()
{
  char * xyz="123";
  printf("%d\n", stoi(&xyz));
  return 0;
}
