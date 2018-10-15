class Node:
  def __init__(self, val, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

def preorder(tree):
  def inner(t, l):
    if t is None:
      return []

    r=[]

    r+=inner(t.left, l)
    r+=[t.val]
    r+=inner(t.right, l)

    return r
  return inner(tree, [])


'''
      4
   /     \
  2       6
 / \     / \
1   3   5   7
'''
t = Node(4, Node(2), Node(6))
t.left.left=Node(1)
t.left.right=Node(3)
t.right.left=Node(5)
t.right.right=Node(7)

r=preorder(t)
print(r)
