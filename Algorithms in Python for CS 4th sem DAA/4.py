import time
def bfs(s,ver) :
    visited=[0 for i in range(ver+1)]
    visited[s]=1
    level=[[s]]
    i=0
    tree=[]
    while level[i]:
      level.append([])
      for u in level[i]:
        for v in a[u]:
          if visited[v]==0:
            visited[v]=1
            tree.append((u,v))
            level[i+1].append(v)
      i=i+1
    level.pop()
    print("the tree has the following edges")
    print(tree)
    print("layers:")
    print(level)

ver=int(input("enter the number of vertices"))
e=int(input("enter the number of edges"))
a={}

for i in range(ver+1):
    a[i]=[]

for i in range(e):
  u=int(input("enter u"))
  v=int(input("enter v"))
  a[u].append(v)
  a[v].append(u)
#print (a)
  
for i in range(ver+1):
    a[i].sort()
del a[0]
print (a)
x=int(input("enter the start vertex"))
start=time.clock()
bfs(x,ver)
end=time.clock()
print("The program ran for: ",end-start,"seconds")
