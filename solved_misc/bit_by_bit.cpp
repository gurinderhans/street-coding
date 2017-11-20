#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
  for(;;)
  {
    int n;cin>>n;
    if (n==0) break;

    uint32_t chk=0, val=0;

    while(n--)
    {
      string code; cin>>code;

      if (code == "SET")
      {
        int i;cin>>i;
        chk |= 1<<i;
        val |= 1<<i;
      }
      else if (code == "CLEAR")
      {
        int i;cin>>i;
        chk |= 1<<i;
        val &= ~(1<<i);
      }
      else if (code == "AND")
      {
        //Store in bit i the logical AND of the contents of bits i and j.
        int i,j;cin>>i>>j;

        // if both bits are set, get their logical AND value and set to i
        if ((1&(chk>>i))==1 && (1&(chk>>j))==1)
        {
          int bi=1&(val>>i);
          int bj=1&(val>>j);

          if (bi==1&&bj==1)
          {
            val |= 1<<i;
          }
          else
          {
            val &= ~(1<<i);
          }
        }
        else
        {
          // one of the bits isn't set, thus the result is unkown
          chk &= ~(1<<i);
        }
      }
      else if (code == "OR")
      {
        //Store in bit i the logical AND of the contents of bits i and j.
        int i,j;cin>>i>>j;

        if ((1&(chk>>i))==1 && (1&(chk>>j))==1)
        {
          int bi=1&(val>>i);
          int bj=1&(val>>j);

          val &= ~(1<<i);
          if (bi==1 || bj==1)
          {
            val |= 1<<i;
          }
        }
        else
        {
          chk &= ~(1<<i);
        }
      }
    }

    for (int i=31;i>=0;--i)
    {
      if ((1 & (chk>>i))==1)
      {
        cout << (1&(val>>i));
      }
      else
      {
        cout <<'?';
      }
    }
    cout << endl;
  }

  return 0;
}

