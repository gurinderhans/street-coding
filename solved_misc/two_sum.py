class Solution(object):
  def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """

    d={}
    for i in range(len(nums)):
      d[target-nums[i]] = (nums[i], i)

    for i in range(len(nums)):
      if nums[i] in d:
        if i != d[nums[i]][1]:
          return [i, d[nums[i]][1]]

arr=[3,2,4]
target=6

Solution().twoSum(arr,target)
