import sys

header=raw_input().split(':')
sc=int(header[0])# output slot count
re=header[1].strip()

if re=='True':
  re=True
else:
  re=False

nodes=[]
inempsc=0
in_emp_cnt=[]
in_nodecount=0

obc=0
istr=""
for l in sys.stdin: istr+=l
isp=istr.split("\n")
for ri in isp:
  i=ri.strip().strip("\n")
  if len(i)>0:
    if i[0]=='[':
      obc+=1
      continue
    elif i[0]==']':
      obc-=1

  if obc == 2:
    if i == "":
      inempsc+=1
    nodes.append(i)
  elif obc==1 and i[0]==']':
    in_nodecount+=1
# print re
if re:
  nodes=filter(lambda x:x!="", nodes)

# print len(nodes)
outnodes=[]
for i in range(0,len(nodes),sc):
  arr=nodes[i:i+sc]
  outnodes.append(arr)
  if len(arr)<sc:
    for kk in range(len(arr),sc):
      outnodes[len(outnodes)-1].append("")

# print len(outnodes[len(outnodes)-1])

out_empsc=0
for i in outnodes:
  for j in i:
    if j =="":
      out_empsc+=1

print len(outnodes)
print len(outnodes)-in_nodecount
print (out_empsc-inempsc)
print (out_empsc)
print '['
for i in outnodes:
  print '['
  for j in i:
    print j
  print ']'
print ']'



