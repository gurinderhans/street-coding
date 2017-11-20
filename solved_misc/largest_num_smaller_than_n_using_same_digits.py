
"""
find the largest number smaller than the given `N`
using the same digits that `N` is made up of.
"""

N=1342

def nextSmallest(N):
  lN=list(str(N))
  for i in xrange(len(lN)-1,0,-1):
    if lN[i]<lN[i-1]:
      lN[i],lN[i-1]=lN[i-1],lN[i]
      return int(''.join(lN))
  return N
