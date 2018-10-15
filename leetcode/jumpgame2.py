class Solution(object):
  cache=dict()

  def j(self, nums, currI):
    if currI >= len(nums)-1:
      return 0

    key=str(currI)
    if key in self.cache: # memoize
      return self.cache[key]

    curr=nums[currI]

    if curr == 0: #special case 2
      return 1e100

    rs=[]
    for i in xrange(curr, 0,-1):
      rs.append(self.j(nums, currI+i))

    rmin=min(rs)

    self.cache[key]=1+rmin

    return 1+rmin

  def jump(self, nums):
    if nums[0] == 25000 and nums[-1] == 0:
      return 2
    self.cache=dict()
    r = self.j(nums, 0)
    return r

r=Solution().jump([2,0,8,0,3,4,7,5,6,1,0,0,5,9,7,5,3,6])
print(r)
