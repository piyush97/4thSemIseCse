#include<iostream>
using namespace std;
void BFS(int[20][20],int,int[20],int);

int main()
{
  int n,a[20][20],i,j,visited[20],source;

  cout<<"enter number of vertices:";
  cin>>n;

  cout<<"\nenter adjacency matrix\n";
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cin>>a[i][j];

    for(i=1;i<=n;i++)
      visited[i]=0;

    cout<<"\nEnter the source node:";
    cin>>source;
    visited[source]=1;

    BFS(a,source,visited,n);

    for(i=1;i<=n;i++)
    {
      if(visited[i]!=0)
        cout<<"\nnode "<<i<<" is reachable";
      else
        cout<<"\nnode "<<i<<" is not reachable";
    }
    cout<<endl;
  }

  void BFS(int a[20][20], int source, int visited[20], int n)
  {
    int queue[20],f,r,u,v;
    f=0;r=-1;
    queue[++r]=source;
    while(f<=r)
    {
      u=queue[f++];
      for(v=1;v<=n;v++)
      {
        if(a[u][v]==1 && visited[v]==0)
        {
          queue[++r]=v;
          visited[v]=1;
        }
      }
    }
  }