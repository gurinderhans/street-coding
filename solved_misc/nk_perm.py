
class Solution(object):
  def perms(self, s):
    if len(s)==1:
      return s

    rr=[]
    for i in xrange(len(s)):
      s[0],s[i]=s[i],s[0]
      cr=[s[0]+x for x in self.perms(s[1:])]
      rr.extend(cr)
      s[0],s[i]=s[i],s[0]
    return rr

  def getPermutation(self, n, k):
    return self.perms([str(x+1) for x in range(n)])[k]


print Solution().getPermutation(3,2)
# print perms(list('123'))[2]

