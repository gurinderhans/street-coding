class Solution(object):
  def groupAnagrams(self, strs):
    strmaps=["".join(sorted(i)) for i in strs]
    
    from collections import defaultdict
    groups=defaultdict(list)
    for i,v in enumerate(strmaps):
      groups[v].append(strs[i])

    return [g for k,g in groups.items()]

inp=["eat", "tea", "tan", "ate", "nat", "bat"]
r=Solution().groupAnagrams(inp)
print(r)
