

def sumToK(arr, k):
  sm,cnt=0,0
  hsum={0:-1}
  for i, el in enumerate(arr):
    sm+=el
    if sm-k in hsum:
      cnt+=1
    hsum[sm]=i
  return cnt

arr=[0,0,0]
print sumToK(arr,0)
