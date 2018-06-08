n = int(input('Enter the number of vertices (> 2): '))
print('Enter the cost matrix (-1 if no edge exists):')
c = []
for _ in range(n):
    c.append(list(map(int, input().split())))
bound = 0
smallest = []
solution = 1
for i in c:
    i = sorted(filter(lambda x: x != -1, i))
    smallest.append(i[0])
    bound += i[0]
    solution += i[-1]
visited = {0}
current_path = [0]
best_path = []
def tsp(cost, bound, path_cost, path):
    if len(path) == n:
        if cost[path[-1]][path[0]] != -1:
            path_cost += cost[path[-1]][path[0]]
            global solution, best_path
            if solution > path_cost:
                solution = path_cost
                best_path = path[:]
    else:
        for i in range(n):
            if i not in visited and cost[path[-1]][i] != -1:
                path_cost_i = path_cost + cost[path[-1]][i]
                bound_i = bound - smallest[path[-1]]
                if bound_i + path_cost_i < solution:
                    visited.add(i)
                    path.append(i)
                    tsp(cost, bound_i, path_cost_i, path)
                    path.pop()
                    visited.remove(i)
tsp(c, bound, 0, current_path)
if best_path:
    best_path.append(0)
    print(solution)
    print('Path:', best_path)
else:
    print('No cycle exists')
