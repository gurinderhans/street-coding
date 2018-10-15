class Node(object):
  def __init__(self, val, left=None, right=None):
    self.val=val
    self.L=left
    self.R=right

# create tmp tree
n=Node(5,
  Node(4,
    Node(7,
      Node(11),
      Node(12)
    ),
    Node(8,
      Node(13),
      Node(14)
    )
  ),
  Node(6,
    Node(9,
      Node(15),
      Node(16)
    ),
    Node(10,
      Node(17),
      Node(18)
    )
  )
)

def lca(root, lv, rv):
  if root is None:
    return None

  if root.val==lv or root.val==rv:
    return root

  left=lca(root.L, lv, rv)
  right=lca(root.R, lv, rv)

  if left is not None and right is not None:
    return root
  
  return left if left is not None else right

def find(root, val, acc=[]):
  if root is None:
    return None

  if root.val == val:
    acc.append(root.val)
    return root

  left=find(root.L,val,acc)
  right=find(root.R,val,acc)

  if left or right:
    acc.append(root.val)

  return left or right

def lca1(root, lv, rv):
  p1=[]; find(root, lv, p1)
  p2=[]; find(root, rv, p2)

  last=None
  for i, (a,b) in enumerate(zip(reversed(p1), reversed(p2))):
    last=a
    if a!=b:
      last = p1[len(p1)-i]
      break

  return last

a=8
b=13
print lca1(n,a,b)
print lca(n,a,b).val
