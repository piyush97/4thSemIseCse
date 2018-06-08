n=int(input("enter the number of items"))
W=int(input("enter the knapsack capacity"))
items=[0]
for i in range(1,n+1):
  items.append(i)
weights=[0]
value=[0]
for i in range(1,n+1):
  print("enter the weight for item ",i, " : ")
  wi=int(input())
  weights.append(wi)
  print("enter the value for item ",i ," : ")
  vi=int(input())
  value.append(vi)
print(items)
print(weights)
print(value)
M = [[0 for i in range(W+1)] for j in range(n+1)]
i = 1
while i <= n:
  x = 1
  while x <= W:
    if weights[i] > x:
      M[i][x] = M[i-1][x]
    else:
      M[i][x] = max(M[i-1][x],value[i]+M[i-1][x-weights[i]])
    x = x + 1
  i = i + 1
print(M)
print("maximum value= ",M[n][W])
i=n
k=W
cont=[]
while i>0 and k>0:
  if M[i][k]!=M[i-1][k]:
    cont.append(i)
    k=k-weights[i]
    i=i-1
  else:
    i=i-1
print("items in knapsack are: ")
print(cont)
