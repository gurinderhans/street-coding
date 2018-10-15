p=[0,2,3,4]

cache={}
def cr(sz):
  if sz == 0: return 0

  if sz in cache:
    return cache[sz]
  else:
    cache[sz]=max(
                map(
                  lambda x: p[x]+cr(sz-x),
                  range(1,sz+1))
                )
  return cache[sz]

print cr(1)
