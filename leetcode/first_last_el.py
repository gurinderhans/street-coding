
class Solution:

	fl=(-1,-1)

	def _searchRange(self, nums, target, start, end):
		if end < start:
			return

		mid = start + ((end-start) // 2)
		if target == nums[mid]:
			# find left most index with el
			LL,RR=mid,mid
			while LL >= 0 and target == nums[LL]:
				LL-=1
			while RR <= len(nums)-1 and target == nums[RR]:
				RR += 1
			self.fl=(LL+1,RR-1)
		elif nums[mid] < target:
			self._searchRange(nums, target, mid+1, end)
		else:
			self._searchRange(nums, target, start, mid-1)


	def searchRange(self, nums, target):
		self._searchRange(nums, target, 0, len(nums)-1)
		return list(self.fl)


nums=[1]
target=1
r=Solution().searchRange(nums, target)
print(r)
