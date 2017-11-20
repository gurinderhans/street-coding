#include <iostream>
#include <string>

using namespace std;

bool isUniqueCharsString(string testStr)
{
  int checkMask = 0;
  for (int i = 0; i < testStr.size(); ++i)
  {
    int cI = 'z' - testStr[i];
    if ((checkMask & (1 << cI)) > 0)
    {
      // this bit is set to one, because this char previously exists
      return false;
    }

    // set this bit to 1
    checkMask |= (1 << cI);
  }

  return true;
}

int main()
{
  cout << isUniqueCharsString("ztesla");
  cout << endl;

  return 0;
}
