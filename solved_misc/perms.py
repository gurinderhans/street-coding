
def perms(chars):
  if len(chars) == 1:
    return chars

  r=[]
  for x in xrange(len(chars)):
    chars[x],chars[0]=chars[0],chars[x]
    r.extend(map(lambda x: chars[0]+x, perms(chars[1:])))
    chars[x],chars[0]=chars[0],chars[x]
  return r


r=perms(list('abcd'))
print '------------'
print len(r)
print r
