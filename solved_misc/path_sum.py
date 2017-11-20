

class Solution(object):
  def hasPathSum(self, root, sum):
    return self.sum(root, sum - root.value)

  def sum(self, root, sum):
    if sum == 0:
      return True

    if sum < 0:
      return False

    return self.sum(root.left, sum - root.left.val) or self.sum(root.right, sum - root.right.val)

