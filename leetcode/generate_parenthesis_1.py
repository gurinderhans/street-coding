import sys


class Solution(object):
  def _gen(self, n, o, c, s):
    if n==o and c==o:
      return [s]

    r=[]
    if o<n:
      rs=self._gen(n, o+1, c,s+'(') # new open
      r+=rs

    if c<n and c<o:
      rs=self._gen(n, o, c+1,s+')') # new close
      r+=rs

    return r

  def generateParenthesis(self, n):
    return self._gen(n,0,0,'')

r=Solution().generateParenthesis(3)
print(len(r),r)
