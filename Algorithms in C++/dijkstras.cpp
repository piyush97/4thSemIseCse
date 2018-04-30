#include <iostream>
using namespace std;

void get_matrix(int n, int W[20][20])
{
	cout<<"Enter the weighted adjacency matrix " <<endl;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
	 	{
	  		cin>>W[i][j];
	 	}
	}	
}

void dijkstras(int n, int W[20][20])
{
	int visited[20];
	int distance[20];
	int source;
	int u;
	int min;

	cout << "Enter the source node Index: " << endl;
	cin >> source;

	for(int i=0; i<n; i++)
	{
		visited[i]=0;
	    	distance[i]=W[source][i];
	}

	visited[source] = 1;
	distance[source] = 0;

	for (int i=1; i<n; i++)
	{
		min = 999;

		for(int j=1; j<n; j++)
		{
			if(visited[j] == 0)
			{
				if(distance[j] < min)
				{
					min = distance[j];
					u = j;
				}
			}
		}

		visited[u] = 1;

		for(int k=0; k<n; k++)
		{
			if(W[u][k] != 999 && visited[k] == 0)
			{
				if(distance[k]>W[u][k]+distance[u])
					distance[k]=W[u][k]+distance[u];
			}
		}

	}

	for(int i=0; i<n; i++)
		if(i!=source)
  			cout<<"\nshortest path from " 
  			    <<source <<" to "<< i << " is " << distance[i] << endl;
}

int main()
{
	int n, W[20][20];

	cout << "Enter the number of vertices: " << endl;
	cin >> n;

	get_matrix(n,W);
	dijkstras(n, W);

}


/* OUTPUT 


Enter the number of vertices: 
5
Enter the weighted adjacency matrix 
0 3 999 7 999
3 0 4 2 999
999 4 0 5 6
7 2 5 0 4
999 999 6 4 999
Enter the source node Index: 
0

shortest path from 0 to 1 is 3

shortest path from 0 to 2 is 7

shortest path from 0 to 3 is 5

shortest path from 0 to 4 is 9


Time Complexity of the implementation is O(V^2). 
If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap.

*/
