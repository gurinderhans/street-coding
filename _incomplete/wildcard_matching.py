





class Solution(object):
  def isMatch(self, s, p):
    # if s=="" and len(p)==p.count('*'): return True
    si,pi=0,0
    while si<len(s) and pi<len(p):
      # print 'si:',si,'pi:',pi,'len(s):',len(s),'len(p):',len(p)
      if p[pi] == '*':
        if pi+1==len(p):
          return True
        j=pi
        # print j
        while j<len(p)-1 and p[j]=='*':j+=1
        pi=max(0,j-1)
        # print j
        j=si
        mx=j
        while j<len(s):
          if s[j]==p[pi+1] and j>mx:
            mx=j
          j+=1
        si=mx
        pi+=1
        print '--:',si,pi,s[si],p[pi]
        if p[pi]!='?' and s[si]!=p[pi]:
          return False
      else:
        if p[pi]=='?' or p[pi]==s[si]:
          si+=1
          pi+=1
        else:
          return False
    
    while pi<len(p) and p[pi]=='*': pi+=1
    print pi,si,p,s
    return si==len(s) and pi==len(p)



a="abefcdgiescdfimde"
b="ab*cd?i*de"
# print Solution().isMatch("","*")
# print Solution().isMatch("a","*")
print Solution().isMatch("hi","*?")

