import time
graph = {}
e = input("Enter the number of edges")
def addEdge(graph, v1, v2, w):
	graph.setdefault(v1, {})
	graph[v1].update({v2:w})
print "u v weight"
for i in range(e):
	a,b,w = raw_input().split()
	a = int(a)
	b = int(b)	
	w = int(w)
	addEdge(graph,a,b,w)
	addEdge(graph,b,a,w)

def Prims():
	U,V=set([1]),set(graph.keys())
	result=[]
	total = 0
	while len(U) != len(V):
		minw=-1
		mine=[]
		for u in U:
			for v in graph[u]:
				if v in V-U:
					if minw==-1 or minw>graph[u][v]:
						minw=graph[u][v]
						mine=[u,v]
		mine.append(minw)
		total+=minw
		result.append(mine)
		U.add(mine[1])
	return result,total
start=time.clock() 
res,tot = Prims()
print res
print "Total =",tot
end=time.clock()
print "The program ran for: ",end-start,"seconds"
