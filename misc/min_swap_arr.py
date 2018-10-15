
# A=[3, 1, 4, 5, 2]
A=map(int, raw_input().split(" "))
As=sorted(A)
# # print A,As
c=0
while 1:
  for i in range(1,len(A)):
    if A[i] < A[i-1]:
      t=A[i]
      A[i]=A[i-1]
      A[i-1]=t

      c+=1
  if A==As:
    print A
    break

print c
