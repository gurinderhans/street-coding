import sys

m=[]

for line in sys.stdin:
  ln=map(int, line.strip("\n").split(" "))
  # print ln
  m.append(ln)

tm=[]
for i in range(len(m[0])):
  tm.append([])

ti=0
for i in m:
  for ii in range(len(i)):
    tm[ii].append(i[ii])
  ti+=1

for i in tm:
  print " ".join(map(str, i))
