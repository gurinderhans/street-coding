#!/bin/python

import sys
from collections import defaultdict

def isValid(s):
  sh=defaultdict(int)
  for i in s:
    sh[i]+=1

  fmap=defaultdict(int)
  for v in sh.itervalues():
    fmap[v]+=1

  print dict(fmap)

  if len(fmap) == 1:
    return "YES"
  elif len(fmap) == 2:
    a,b=fmap.keys()
    if b>1 and a == 1 and fmap[a] == 1:
      return "YES"
    elif a>1 and b == 1 and fmap[b] == 1:
      return "YES"
    elif a==1 and b==2 and fmap[b]==1:
      return "YES"
    elif b==1 and a==2 and fmap[a]==1:
      return "YES"
    elif abs(a-b) == 1 and (fmap[a]==1 and fmap[b]==1):
      return "YES"

  return "NO"

s = raw_input().strip()
result = isValid(s)
print(result)


