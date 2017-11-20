n=0b10000000000
m=10101
i=2
j=6

while i <= j:
  last=m%10
  m/=10
  print last,i
  if last == 1:
    n |= 1<<i
  else:
    n &= ~(1<<i)

  i+=1

print(bin(n))
