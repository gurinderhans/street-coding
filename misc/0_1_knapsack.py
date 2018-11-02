
def _knapsack(W, val, items, i):
  if W<0:
    return 0

  if W==0 or i >= len(items):
    return val

  currItem=items[i]
  a=_knapsack(W-currItem[0], val+currItem[1], items, i+1)
  b=_knapsack(W, val, items, i+1)
  return max(a,b)

def maxValueKnapsack(W, items):
  return _knapsack(W, 0, items, 0)

W=25 # total weight of knapsack
items=[
    (24,24), # weight of item, value of item
    (10,18),
    (10,18),
    (7,10)
]

print maxValueKnapsack(W,items)
