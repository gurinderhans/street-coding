nodes=[1,2,3,4,5,6]
edges=[
    (1,3),
    (2,4),
    (3,5),
    (4,6),
    (5,1),
]

class DisjointSet(object):
  def __init__(self, initNode):
    self.node = initNode
    self.storage = [initNode]

  def find(self, element):
    return element in self.storage
  
  def union(self, otherSet):
    self.storage += otherSet.storage
    return self

dsets=[DisjointSet(n) for n in nodes]

for e in edges:
  nodeA, nodeB = e

  setA, setB = None, None
  setAFind = filter(lambda x: x.find(nodeA), dsets)
  setBFind = filter(lambda x: x.find(nodeB), dsets)

  if len(setAFind) > 0:
    setA = setAFind[0]
  if len(setBFind) > 0:
    setB = setBFind[0]

  if setA.node == setB.node:
    print "found a cycle"
    print "edge:",e
    print "storage:",setA.storage + [setB.node]
    break
  else:
    newSetList = [s for s in dsets if s.node != setA.node or s.node != setB.node]
    setC = setA.union(setB)
    newSetList.append(setC)
    dsets = newSetList

