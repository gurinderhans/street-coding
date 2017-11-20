



class Solution(object):
  def lengthOfLongestSubstring(self, s):
    if len(s)==0: return 0
    d={}
    start,mx=0,0
    for i, ch in enumerate(s):
      if ch in d and d[ch]>=start:
        mx=max(mx, i-start)
        start=d[ch]+1
      d[ch]=i
    return max(mx,i-start+1)

print Solution().lengthOfLongestSubstring("abcdef")
print(Solution().lengthOfLongestSubstring("aabba"))
print(Solution().lengthOfLongestSubstring("dvdf"))
