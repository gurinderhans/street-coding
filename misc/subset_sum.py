tcalls=0
cache={}
def subset_sum(inp, i, Sum):
  if i > len(inp)-1 or Sum <= 0:
    return Sum == 0
  
  key=(Sum,i)
  if key in cache:
    return cache[key]

  global tcalls; tcalls+=1

  r = subset_sum(inp, i+1, Sum-inp[i]) or subset_sum(inp, i+1, Sum)
  cache[key]=r
  return cache[key]

inp=[1,2,3,4,1]
print(len(inp))
r=subset_sum(inp,0, 11)
print(r,tcalls)
