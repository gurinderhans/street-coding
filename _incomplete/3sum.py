


def twosum(arr, sum, exc):
  d={}
  for i,x in enumerate(arr):
    if i!=exc:
      d[sum-x]=x
  
  for i,x in enumerate(arr):
    if i!=exc and x in d:
      if x != d[x]:
        return [x,d[x]]
  return


def threesum(arr):
  rr=[]
  for i,x in enumerate(arr):
    # find a twosum using all the other elements in arr excluding the current one
    r=twosum(arr,-x,i)
    if r is not None:
      cr=sorted([x]+r)
      if cr not in rr:
        rr.append(cr)
  return rr

# arr=[-1, 0, 1, 2, -1, -4]
print threesum([-1,0,1,2,-1,-4])
