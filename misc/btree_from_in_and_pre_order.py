class TreeNode(object):
  def __init__(self, val):
    self.val=val
    self.left=None
    self.right=None

def in_order(root):
  arr=[]
  if root.left is not None:
    arr.extend(in_order(root.left))
  arr.append(root.val)
  if root.right is not None:
    arr.extend(in_order(root.right))
  return arr

def gen_tree(io,po):
  if len(io) == 0: return
  ri=io.index(po.pop(0))
  n=TreeNode(io[ri])
  n.left=gen_tree(io[:ri], po)
  n.right=gen_tree(io[ri+1:], po)
  return n

io=[1,4,6,7,8,10,13]
po=[7,4,1,6,10,8,13]
t=gen_tree(io,po)
i=in_order(t)
print i
print io
