#include <stdio.h>
#include <math.h>

int get_num(char ** pc)
{
  char *orig_pc=*pc;
  for(;;(*pc)++)
  {
    char l=**pc;
    if(l>='0'&&l<='9')
      continue;
    else if(l=='(')
      orig_pc++;
    else
      break;
  }

  int res=0;
  for(char *c=(*pc)-1,p=0;c!=orig_pc-1;--c,++p)
  {
    res+=pow(10,p)*(*c - 48);
  }
  return res;
}

// (8)/(4)
int br(char ** c)
{
  char *expr_end;
  if(**c=='(')
  {
    // feed it expr
  }
  return 0;
}

int div(char ** c)
{
  int a=get_num(c);
  while(**c=='/')
  {
    (*c)++;
    a=a/get_num(c);
  }
  return a;
}

int mul(char ** c)
{
  int a=div(c);
  while(**c=='*')
  {
    (*c)++;
    int b=div(c);
    a*=b;
  }
  return a;
}

int add(char ** c)
{
  int a=mul(c);
  while(**c=='+')
  {
    (*c)++;
    int b=mul(c);
    a+=b;
  }
  return a;
}

// BEDMAS
int main()
{
  char * expr = "3*(4+5)";
  printf("num=%d\n",add(&expr));

  return 0;
}
