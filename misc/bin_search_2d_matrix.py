
class Solution(object):
  def searchList(self,arrList,target):
    lo,hi=0,len(arrList)-1
    while lo<=hi:
      mid=(lo+hi)/2
      if target==arrList[mid]:
        return True
      elif target>arrList[mid]:
        lo=mid+1
      elif target<arrList[mid]:
        hi=mid-1
    return False

  def searchMatrix(self,matrix, target):
    lo,hi=0,len(matrix)-1
    while lo<=hi:
      mid=(lo+hi)/2
      if len(matrix[mid])==0:
        return False
      if target>=matrix[mid][0] and target<=matrix[mid][-1]:
        return self.searchList(matrix[mid], target)
      elif target>matrix[mid][-1]:
        lo=mid+1
      elif target<matrix[mid][0]:
        hi=mid-1
    return False

mm=[
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
    ]
print Solution().searchMatrix([],4)
