def bf(adj_list,n,s):
    distance = [999 for i in range(n+1)]
    path = [[None] for i in range(n+1)]
    path[s] = [s]
    distance[s] = 0
    for i in range(n-1):
        for pair in adj_list:
            tmp = distance[pair[1]]
            distance[pair[1]] = min(distance[pair[1]], distance[pair[0]]+pair[2])
            if tmp != distance[pair[1]]:
                path[pair[1]] = path[pair[0]]+[pair[1]]
    del(distance[0])
    del(path[0])
    print(distance)
    for i in path:
          print (s,"--->",path.index(i)+1,":",i)
def main():
    adj_list=[]
    n=int(input("enter the number of vertices"))
    e=int(input("enter the number of edges"))
    for i in range(e):
        u = int(input("Enter the vertex u: "))
        v = int(input("Enter the vertex v: "))
        w = int(input("Enter the corresponding weights: "))
        l=[u,v,w]
        adj_list.append(l)
    print(adj_list)
    source = int(input("Enter a source:"))
    bf(adj_list,n,source)
main()
