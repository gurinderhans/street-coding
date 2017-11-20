


def convert(s,numRows):
  i=0
  r=[[] for _ in xrange(numRows)]
  while i<len(s):
    a=s[i:i+numRows]
    for j,ch in enumerate(a):
      r[j].append(ch)
      pass
    ii=numRows/2
    if numRows%2==0:
      ii-=1
      pass
    r[ii].append(s[i+numRows:i+numRows+1])
    i+=numRows+1
    pass

  res=""
  for i in r:
    for j in i:
      if j:
        res+=j
        pass
      pass
    pass
  return res


print convert("ABCD", 2)
