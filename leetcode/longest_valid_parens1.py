

class Solution(object):
  def _longestValidParentheses(self, s,r):
    final_max=0
    prev_max,curr_max=0,0
    o,c=0,0
    flag=False
    for ch in s:
      if ch=='(' and r:o+=1
      if ch==')' and not r:c+=1

      if o==c:
        curr_max=max(curr_max, o+c)
        if flag:
          prev_max+=curr_max
          curr_max=prev_max
          final_max=max([final_max,prev_max, curr_max])
        else:
          final_max=max([final_max,prev_max, curr_max])
          prev_max=curr_max

        flag=True
        o,c=0,0
        curr_max=0


      if c>o:
        print(c,o)
        if c-1==o:
          final_max=c-1+o
        flag = False
        o,c=0,0

    return final_max

  def longestValidParentheses(self, s):
    return max(self._longestValidParentheses(s,False), self._longestValidParentheses(reversed(s),True))

print(Solution().longestValidParentheses("(()(()"))
# print(Solution().longestValidParentheses("((("))
# print(Solution().longestValidParentheses(")))"))
# print(Solution().longestValidParentheses("((()"))
# print(Solution().longestValidParentheses(")()())"))
# print(Solution().longestValidParentheses("()())(()(())()()"))
