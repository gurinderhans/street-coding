from pprint import pprint

class Node(object):
  def __init__(self, val=-1, child=None):
    self.val=val
    self.child=child
    self.max_dist=-1


A=[[9, 6, 5, 2],
   [8, 7, 6, 5],
   [7, 3, 1, 6],
   [1, 1, 1, 7]]

A=[[Node(v) for v in row] for row in A]

def travel(A,i,j):
  """
  BEGIN
    travel right, travel down, record parent, track dist,
    get max dist
  END;
  """

  # can use Node.max_dist property to record the dist from the child node
  # and calculate parent node dist based from that, this way our runtime
  # is only O(m*n) instead of right now, its O(m*n*2) i think? but it's
  # very expensive!

  dr,dd=0,0
  if j+1<len(A[0]) and abs(A[i][j].val-A[i][j+1].val) < 2: # can go right
    dr=travel(A,i,j+1)

  if i+1<len(A) and abs(A[i][j].val-A[i+1][j].val) < 2: # can go down
    dd=travel(A,i+1,j) # down

  max_d=max(dd,dr)
  if max_d > 0:
    if max_d == dd:
      A[i][j].child=A[i+1][j]
    elif max_d == dr:
      A[i][j].child=A[i][j+1]
  
  return 1+max(dd,dr)

def max_len_seq_from_top(A):
  max_dist=-1
  max_dist_loc=(-1,-1)
  tbl_cache=[[-1 for y in xrange(len(A[0]))] for x in xrange(len(A))]
  for i in xrange(len(A)-1,-1,-1):
    for j in xrange(len(A[0])-1,-1,-1):
      if tbl_cache[i][j]==-1:
        d=travel(A,i,j)
        tbl_cache[i][j]=d
        if d>max_dist:
          max_dist=d
          max_dist_loc=(i,j)

  y,x=max_dist_loc
  if x>-1 and y>-1:
    child=A[y][x]
    c_path=[]
    while child is not None:
      c_path.append(child.val)
      child = child.child
    return c_path, max_dist
  return None, None

print max_len_seq_from_top(A)
