

class Solution(object):
  def largestNumber(self, nums):
    ns=map(str, nums)
    nstr=""
    while len(ns)>0:
      maxI=0
      maxn='0'
      for i in range(len(ns)):
        for j in range(len(min(maxn, ns[i]))):
          if ns[i][j] > maxn[j]:
            maxn=ns[i]
            maxI=i
            break
          elif ns[i][j] == maxn[j]:
            maxn=ns[i]
            maxI=i
            break
          elif ns[i][j] < maxn[j]:
            break

      nstr+=ns[maxI]
      del ns[maxI]

    return nstr

r=Solution().largestNumber([3,30,34,5,9])
print(r)

"""
int differingBit = 1;
        while ((differingBit & aXorB) == 0) {
            differingBit  < < = 1;
        }"""
