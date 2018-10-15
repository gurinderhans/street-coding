class Solution:
  arr=set()
  def _generateParenthesis(self, n, _str, _open, _close):
    if _open == n and _close == n:
      self.arr.add(_str)
      return
    
    if _open == n and _close < n: # need to start closing now
      self._generateParenthesis(n, _str+')', _open, _close+1)

    if _open < n and _close < n:
      self._generateParenthesis(n, _str+'(', _open+1, _close)
    
    if _close < n and _open > _close:
      self._generateParenthesis(n, _str+')', _open, _close+1)


  def generateParenthesis(self, n):
    self.arr=set()
    self._generateParenthesis(n,'',0,0)
    return list(self.arr)

r=Solution().generateParenthesis(4)
print(r)
