adj_map={}
n=input()
files=raw_input().split(" ")
for i in xrange(n):
  fl,count=raw_input().split(" ")
  imports=[]
  for j in xrange(int(count)):
    inp=raw_input().lstrip("import ").split(", ")
    imports.extend(inp)
  adj_map[fl]=imports


def traverse(graph):
  vertices=graph.keys()
  stack=[]
  visited=[]

  stack.insert(0,vertices[0])
  stack.append(vertices[0])


  while len(stack) > 0:
    el=stack.pop(0)
    siblings=graph[el]
    print el
    for s in siblings:
      if s not in visited:
        stack.insert(0,s)
        visited.append(s)

traverse(adj_map)
