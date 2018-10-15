
cache={}
def f(N):
  if N==0: return 1
  if N not in cache:
    cache[N]=sum([f(i) for i in
              xrange(max(0,N-3),N)])
  return cache[N]


print f(input())
