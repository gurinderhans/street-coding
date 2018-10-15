


class Solution(object):
  def findPeakElement(self, nums):
    if len(nums) == 1:
      return 0

    nums=[float("-inf")]+nums+[float("-inf")]

    for i in range(1,len(nums)-1):
      prev=nums[i-1]
      curr=nums[i]
      nxt=nums[i+1]

      if prev <= curr >= nxt:
        return i-1

inp=[1,2,1,3,5,6,4]
# inp=[1,2,3,4,5]
# inp=[5,4,3,2,1]
r=Solution().findPeakElement(inp)
print(r)
