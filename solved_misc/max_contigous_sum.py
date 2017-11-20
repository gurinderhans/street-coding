
def maxSum(arr):
  globalMax=0
  gs,ge=0,0
  currMax=0
  ts,te=0,0
  for i,el in enumerate(arr):
    if el > el+currMax:
      ts,te=i,i
      currMax=el
    else:
      if currMax+el>currMax:
        te=i
      currMax+=el

    if currMax>globalMax:
      gs,ge=ts,i
      globalMax=currMax

  return arr[gs:ge+1]

arr=[-1,2,2,-1,-1,2]
maxSum(arr)
