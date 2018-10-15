

class Solution(object):
  def maxProduct(self, nums):
    a=nums[0]
    b=1
    c=False
    for n in nums:
      if n == 0:
        c=True
        b=1
        continue
      b=b*n
      a=max([b,a,n])

    if c:
      return max(0,a)
    
    return a

r=Solution().maxProduct([0,-2])
print(r)
