class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashtbl = {}
        for i in range(len(nums)):
          if nums[i] in hashtbl:
            return [hashtbl[nums[i]], i]
          else:
            hashtbl[target - nums[i]] = i


res=Solution().twoSum([2,7,11,15], 9)
print(res)
