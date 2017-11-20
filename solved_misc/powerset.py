def pset(iset):
  if len(iset) == 1:
    return iset

  ret=[iset[0]]
  r=pset(iset[1:])

  for i in r:
    ret.append(iset[0]+i)

  ret.extend(r)
  return ret

r=['']
r.extend(pset(list(raw_input())))
print len(r)
print r
