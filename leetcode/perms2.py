
def perms2(arr,ai):
  if len(arr) == 1:
    return [arr]
  res=[]
  for i,v in enumerate(arr):
    newarr = arr[:i] + arr[i+1:]
    for rr in perms2(newarr, ai+1):
      res.append([v] + rr)
  return res




inp=[1,1,2]
r=perms2(inp,0)
cache=set()
res=[]
for x in r:
  y=str(x)
  if y not in cache:
    cache.add(y)
    res.append(x)
print(res)
