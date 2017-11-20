


def add(sa,sb):
  lng,shrt=None,None
  if len(sa)>len(sb):
    lng,shrt=sa,sb
  else:
    shrt,lng=sa,sb

  ans=""
  carry=0

  for x in xrange(len(lng)-1, -1, -1):
    li=x
    si=x-(len(lng)-len(shrt))

    a=lng[li]
    b=0
    if si>-1:
      b=shrt[si]

    r=int(a)+int(b)+carry
    if r>9:
      carry=r/10
    else:
      carry=0

    ans=str(r%10)+ans

  return ans



a="123"
b="503924"
print add(a,b)
print int(a)+int(b)
