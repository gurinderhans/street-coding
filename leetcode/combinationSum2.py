class Solution:
  arr=set()
  def _combinationSum(self, nums, target, elms, prevIndex):
    if target < 0:
      return

    if target == 0:
      self.arr.add('/'.join(map(lambda x:str(x), sorted(elms))))
      return

    for i in range(prevIndex, len(nums)):
      self._combinationSum(nums, target-nums[i], elms+[nums[i]], i+1)

  def combinationSum2(self, candidates, target):
    self.arr=set()
    self._combinationSum(candidates, target, [], 0)
    return [map(lambda x: int(x),s.split('/')) for s in self.arr]

w=Solution().combinationSum2([5,12,3,17,1,18,15,3,17], 8)
print(w)
