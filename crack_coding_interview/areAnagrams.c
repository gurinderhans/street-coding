#include <stdio.h>
#include <string.h>

int checkIfAnagrams(char *sa, char *sb)
{
  int la = strlen(sa);
  int lb = strlen(sb);

  if (la != lb)
    return 0;

  int ma = 0;
  int mb = 0;

  for (int i=0; i<la; ++i)
  {
    int a_ci = sa[i] - 'a';
    int b_ci = sb[i] - 'a';

    ma |= (1<<a_ci);
    mb |= (1<<b_ci);
  }

  return ma == mb;
}

int main()
{
  char *strA = "asdbz";
  char *strB = "zsbad";

  int a = checkIfAnagrams(strA, strB);
  printf("is same: %d\n", a);

  return 0;
}
