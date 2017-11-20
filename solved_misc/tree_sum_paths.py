class Node(object):
  def __init__(self, val, left=None, right=None):
    self.val=val
    self.left=left
    self.right=right

  def __str__(self):
    return str(self.val)

  def __repr__(self):
    return str(self)

def _pathSum(root, Sum):
  if Sum<0:
    return []

  if Sum==0:
    return [[root]]

  allPaths=[]

  if root.left:
    paths=_pathSum(root.left, Sum - root.left.val)
    if len(paths)>0:
      allPaths.extend([path+[root] for path in paths])

  if root.right:
    paths=_pathSum(root.right, Sum - root.right.val)
    if len(paths)>0:
      allPaths.extend([path+[root] for path in paths])

  return allPaths

def findSumPaths(root, Sum):
  if root is None:
    return []

  allPaths=[]
  allPaths.extend(_pathSum(root,Sum-root.val))
  allPaths.extend(findSumPaths(root.left, Sum))
  allPaths.extend(findSumPaths(root.right, Sum))

  return allPaths

root=Node(4,
  Node(2,
    Node(1,
      Node(4),
      Node(2,Node(2))
    ),
    Node(2,
      None,
      Node(3)
    )
  ),
  Node(3,
    Node(1),
    Node(2,
      Node(1,
        Node(1),
        Node(2)
      ),
      Node(3)
    )
  )
)

paths=findSumPaths(root, 7)
for p in paths:
  print p
