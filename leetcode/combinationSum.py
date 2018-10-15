class Solution:
  arr=[]
  def _combinationSum(self, nums, target, elms, prevIndex):
    if target < 0:
      return

    if target == 0:
      self.arr.append(elms)
      return

    for i in range(prevIndex, len(nums)):
      self._combinationSum(nums, target-nums[i], elms+[nums[i]], i)

  def combinationSum(self, candidates, target):
    self.arr=[]
    self._combinationSum(candidates, target, [], 0)
    return self.arr

w=Solution().combinationSum([7,6,3,2], 7)
print(w)
