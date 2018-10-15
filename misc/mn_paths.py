# class Solution(object):
#   def paths(self, m,n,r):
#     if m==0 or n==0: return r
#     a=self.paths(m-1,n, r+1)
#     b=self.paths(m,n-1, r+1)
#     return a+b
#   def paths(self, m, n, L,R):
#     if m==0 and n==0: return L+R
#     self.paths(m-1
#
#   def uniquePaths(self, m, n):
#     r=0
#     print self.paths(m-1,n-1, r)
#     return r
#
# print Solution().uniquePaths(2,2)

class Solution(object):
  cache={}
  def paths(self, m,n):
    key="%d-%d"%(m,n)
    if key not in self.cache:
      if m==0 or n==0: return 1
      self.cache[key]=self.paths(m-1,n)+self.paths(m,n-1)
    return self.cache[key]

  def uniquePaths(self, m, n):
    return self.paths(m-1,n-1)

print Solution().uniquePaths(100,100)

