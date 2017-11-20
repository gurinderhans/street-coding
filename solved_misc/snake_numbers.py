# SNAKE NUMBERS
import sys
# sys.setrecursionlimit(100)
from datetime import datetime

snakeNums={
    0:(1,),
    1:(0,2),
    2:(1,3),
    3:(2,4),
    4:(3,5),
    5:(4,6),
    6:(5,7),
    7:(6,8),
    8:(7,9),
    9:(8,)
}

def fgen(num, cnt, lim):
  if cnt >= lim:
    return [str(num)]

  res=[]
  iterator=snakeNums[num]
  if iterator is None:
    return []

  for el in iterator:
    r=fgen(el, cnt+1, lim)
    for rel in r:
      res.append(str(num)+rel)
  
  return res

def gen(num):
  strNum=str(num)
  numLength=len(strNum)

  snakeNums=[]

  firstDigit=int(strNum[0])
  for i in xrange(1,firstDigit+1):
    res=fgen(i,1,numLength)
    snakeNums.extend(res)

  while numLength>1:
    numLength-=1
    for i in xrange(1, 10):
      res=fgen(i,1,numLength)
      snakeNums.extend(res)

  return sorted(map(int, snakeNums))

# negative numbers?
def isSnake(num):
  if num <= 10:
    return True

  prev=num%10
  num/=10

  while num>0:
    diff=prev-(num%10)

    if abs(diff) != 1:
      return False

    prev=num % 10
    num/=10

  return True

# O(n)
def generateSnakes(num):
  snakeNumbers=[] # snake array
  for x in xrange(num, 0, -1): # loop backwards
    if isSnake(x):
      snakeNumbers.append(x)
  return snakeNumbers

N=int(raw_input()); print;

t=datetime.now()
r=gen(N); print len(r)
print (datetime.now()-t)

t=datetime.now()
generateSnakes(N)[::-1]
print (datetime.now()-t)
