#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N,H;cin>>N>>H;
  vector<int> up(H);
  vector<int> down(H);
  for(int i=0; i<N;++i)
  {
    int h;cin>>h;
    if (i&1) up[h-1]++;
    else down[h-1]++;
  }

  for (int i=H-2; i>=0; --i)
  {
    up[i]+=up[i+1];
    down[i]+=down[i+1];
  }

  int numLevels=-1;
  int minHit=N+1;
  for (int i=0;i<H;++i)
  {
    int hitSum=up[H-1-i]+down[i];
    if (hitSum < minHit)
    {
      minHit=hitSum;
      numLevels=1;
    }
    else if (hitSum==minHit)
    {
      numLevels++;
    }
  }

  cout <<minHit<<" "<<numLevels<<endl;

  return 0;
}
