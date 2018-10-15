class Solution(object):
  def longestValidParentheses(self, s):
    maxxL=-1
    for i in range(len(s)):
      o=0
      c=0
      for j in range(i, len(s)):
        if s[j] == '(':
          o+=1
        else: # will prolly lead to a bug, so DON'T DO THIS!!!!
          c+=1

        if c>o:
          c=0
          o=0

        if o==c and o+c > maxxL:
          maxxL = o+c

    return maxxL

r=Solution().longestValidParentheses(')())()()(')
print(r)
