count=0
m,n=raw_input("").split(" ")

mmap=[]

def check(m,n):
  c=0
  for i in range(m,n+1):
    c+=str(i).count('0')
  return c

print check(int(m),int(n))
