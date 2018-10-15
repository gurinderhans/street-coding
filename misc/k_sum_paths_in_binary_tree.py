class Node:
  def __init__(self, val, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

def inner(root, target, Sum, incpath=[], all_paths=[[]]):

  if target == Sum:
    all_paths.append(incpath)

  if root.left is not None:
    inner(root.left, target, Sum+root.left.val, incpath+[root.left.val], all_paths)

  if root.right is not None:
    inner(root.right, target, Sum+root.right.val, incpath+[root.right.val], all_paths)

def outer(root, target, all_paths=[[]]):
  
  if root is None:
    return

  inner(root, target, root.val, [root.val], all_paths)

  outer(root.left, target, all_paths)
  outer(root.right, target, all_paths)

root=Node(1, Node(3), Node(-1))
root.left.left=Node(2)
root.left.right=Node(1,Node(1))
root.right=Node(-1)
root.right.left=Node(4,Node(1),Node(2))
root.right.right=Node(5,Node(6))

all_paths=[]
outer(root, 5, all_paths)
print(all_paths)
