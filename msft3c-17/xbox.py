import json
import math

def dist(a,b):
  return math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2 + (a[2]-b[2])**2)

inp=raw_input()
jsond = json.loads(inp)
for i in jsond["Skeletons"]:
  pos = i['Position']
  pX=int(pos['X'])
  pY=int(pos['Y'])
  pZ=int(pos['Z'])
  print dist((0,0,0), (pX,pY,pZ))
