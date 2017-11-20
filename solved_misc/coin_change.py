# https://www.hackerrank.com/challenges/coin-change/problem

cache={}
def _getWays(c,i,n):
  key="%d-%d"%(i,n)
  if key in cache:
    return cache[key]

  if n<0:
    return 0

  if n==0:
    return 1

  ways=0
  for x in xrange(max(0,i-1), len(c)):
    ways+=_getWays(c, x+1, n-c[x])
  
  cache[key]=ways

  return ways

def getWays(n, c):
  return _getWays(c,0,n)

n,m=10,4
c=[2,5,3,6]
ways = getWays(n, c)
print ways
