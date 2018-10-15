
def remove(lst, start):
  if len(lst)<2:
    return lst

  keep_lst=[]
  for i in xrange(start, len(lst), 2):
    keep_lst.append(lst[i])

  if len(lst)%2!=0:
    if start == 0:
      start=1
    else:
      start=0

  return remove(keep_lst, start)


def circle_remove(n):
  print remove(range(1,n+1), 0)[0]

circle_remove(100)
