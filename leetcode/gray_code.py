class Solution:
  def grayCode(self, n):
    res=map(lambda x: int(x,2), self._grayCode(n))
    return res

  def _grayCode(self, N):
    if N == 0:
      return ["0"]

    elif N == 1:
      return ["0","1"]

    prevRes = self._grayCode(N-1)

    res=[]
    for i in prevRes:
      res.append("0"+i)

    for j in reversed(prevRes):
      res.append("1"+j)

    return res


r=Solution().grayCode(21)
print(len(r),r)
