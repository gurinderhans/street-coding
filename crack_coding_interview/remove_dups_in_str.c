#include <stdio.h>
#include <string.h>

void cleanupStr(char testStr[], int *strSz, int *existsStrIdx, int *existsLen)
{
  if ((*existsStrIdx) > -1 && (*existsLen) > 0)
  {

    for (int j = ((*existsStrIdx) + (*existsLen)), k=0; j < (*strSz); ++j, ++k) {
      testStr[(*existsStrIdx) + k] = testStr[j];
    }

    (*strSz) -= (*existsLen);

    (*existsStrIdx) = -1;
    (*existsLen) = 0;
  }
}

void removeDups(char testStr[])
{
  int strSz = strlen(testStr);

  int dupCheckMask = 0;

  int existsStrIdx = -1;
  int existsLen = 0;

  for (int i=0; i<strSz; ++i)
  {
    int cI = testStr[i] - 'a';
    if ((dupCheckMask & (1<<cI)) > 0)
    { // char exists
      ++existsLen;
      if (existsStrIdx < 0)
      { existsStrIdx = i; }

      continue;
    }

    cleanupStr(testStr, &strSz, &existsStrIdx, &existsLen);

    // mark as exists
    dupCheckMask |= (1<<cI);
  }

  cleanupStr(testStr, &strSz, &existsStrIdx, &existsLen);

  testStr[strSz] = '\0';
}

int main()
{
  char str[] = "aaaa";
  removeDups(str);
  printf("str: %s\n", str);

  return 0;
}
