#include<iostream>
using namespace std;

void get_matrix(int n, int W[20][20])
{
  cout << "Enter adjacency matrix ";
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin >> W[i][j];
}

void BFS(int n, int W[20][20])
{
    int source;
    int visited[20];
    int queue[20];
    int front = 0, rear = -1, u ,v;

    for(int i=1;i<=n;i++)
        visited[i]=0;

    cout << " Enter the source node: ";
    cin >> source;
    visited[source]=1;

    queue[++rear] = source;
    while(front <= rear)
    {
      u = queue[front++];

      for(v=1; v<=n; v++)
      {
        if(W[u][v] && !visited[v])
        {
          queue[++rear] = v;
          visited[v] = 1;
        }
      }
    }

    for(int i=1; i<=n; i++)
    {
      if(visited[i])
        cout << "Node " << i <<" is reachable. " << endl;
      else
        cout << "Node " << i <<" is not reachable. " <<endl;
    }

}

int main()
{
  int n,W[20][20];

  cout << " Enter number of vertices: ";
  cin >> n;

  get_matrix(n, W);
  BFS(n,W);
  
}


/* OUTPUT 1 

Ashwanis-MacBook-Air:~ Ashwani$ ./a.out
 Enter number of vertices: 5
Enter adjacency matrix          
0 1 1 0 0 
1 0 1 0 0
1 1 0 0 0 
0 0 0 0 1
0 0 0 1 0
 Enter the source node: 1
Node 1 is reachable. 
Node 2 is reachable. 
Node 3 is reachable. 
Node 4 is not reachable. 
Node 5 is not reachable.


*/


/* OUTPUT 2

Ashwanis-MacBook-Air:~ Ashwani$ ./a.out
 Enter number of vertices: 10
Enter adjacency matrix 
0 0 1 1 1 0 0 0 0 0 
0 0 0 0 1 1 0 0 0 0
1 0 0 1 0 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0
1 1 0 0 0 1 0 0 0 0
0 1 1 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0 
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
 Enter the source node: 1
Node 1 is reachable. 
Node 2 is reachable. 
Node 3 is reachable. 
Node 4 is reachable. 
Node 5 is reachable. 
Node 6 is reachable. 
Node 7 is not reachable. 
Node 8 is not reachable. 
Node 9 is not reachable. 
Node 10 is not reachable.


*/
