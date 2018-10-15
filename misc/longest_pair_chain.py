





class Solution(object):
  cache={}

  def chain(self, pairs,i):
    key="%d-%d"%(pairs[i][0],pairs[i][1])
    if key in self.cache:
      return self.cache[key]

    if i==len(pairs)-1:
      return 1

    mx=1
    for j in xrange(i+1, len(pairs)):
      if pairs[j][0]>pairs[i][1]:
        r=1+self.chain(pairs,j)
        if r>mx:
          mx=r
    self.cache[key]=mx
    return mx

  def findLongestChain(self, pairs):
    pairs.sort(key=lambda x:x[1])
    print pairs
    return self.chain(pairs, 0)

# pairs=[[2,3], [3,4], [1,2],[5,6]]
# pairs=[[-1,1],[-2,7],[-5,8],[-3,8],[1,3],[-2,9],[-5,2]]
# pairs=[[7,9],[4,5],[7,9],[-7,-1],[0,10],[3,10],[3,6],[2,3]]
pairs=[[9,10],[9,10],[4,5],[-9,-3],[-9,1],[0,3],[6,10],[-5,-4],[-7,-6]]
print Solution().findLongestChain(pairs)
