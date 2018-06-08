import time
def addEdge(graph, v1, v2, w):
	graph.setdefault(v1, {})
	graph[v1].update({v2:w})
def dijkstra(G, nodes, s):
	dist, prev = {}, {}
	for v in nodes:
		dist[v] = float('inf')
		prev[v] = None
	dist[s] = 0
	while nodes:
		u = min(nodes, key=dist.get)
		nodes.remove(u)
		for v in G[u]:
			alt = dist[u] + G[u][v]
			if alt < dist[v]:
				dist[v] = alt
				prev[v] = u
	return dist,prev
n = int(input('\nEnter number of edges of undirected graph: '))
g = {}
nodes = set()
print('u v cost(u,v)')
for i in range(n):
	a,b,w = raw_input().split()
	w = int(w)
	addEdge(g,a,b,w)
	addEdge(g,b,a,w)
	nodes.update([a,b])
src = raw_input('\nEnter source node: ')
start=time.clock()
d,p = dijkstra(g, nodes, src)
end=time.clock()
path = {}
print('Node\tLowest cost\tPath')
for i in sorted(d):
	path[i],it = [i],p[i]
	while it!=None:
		path[i] = [it] + path[i]
		it = p[it]
	print i,'\t', d[i],'\t\t', path[i]
print "The program ran for: ",end-start,"seconds"
