import time
graph = []
e = input("Enter number of edges")
for i in range(e):
	x = input("enter first node")
	y = input("second node")
	z = input("weight")
	graph.append([x,y,z])
graph.sort(key=lambda x:x[2])
parent=[-1]*e
def find(i):
	if parent[i]==-1:
		return i
	else:
		return find(parent[i])
def union(i,j):
	i_s=find(i)
	j_s=find(j)
	parent[i_s]=j_s
result=[]
total = 0
for k in range(0,len(graph)-1):
	u=graph[k][0]
	v=graph[k][1]
	u_s=find(u)
	v_s=find(v)
	if u_s != v_s:
		result.append([u,v,graph[k][2]])
		total +=graph[k][2]
		union(u,v)
start=time.clock()
print result
print "total =",total
end=time.clock()
print "The Program ran for: ",end-start,"seconds"
