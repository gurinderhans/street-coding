while 1:
  s=input()
  n=int(s)
  if n==0:
    break
  if n%11==0:
    print("{} is a multiple of 11.".format(s))
  else:
    print("{} is not a multiple of 11.".format(s))
