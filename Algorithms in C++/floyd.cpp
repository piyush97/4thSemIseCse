// Floyd's algorithm
#include <iostream>
using namespace std;

int min(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

void floyd(int n, int W[20][20])
{
	int i,j,k;

	for (k=0; k<n; k++)
		for (i=0; i<n; i++)
			for(j=0; j<n; j++)
				W[i][j] = min(W[i][j], W[i][k]+W[k][j]);
}

void get_matrix(int n, int W[20][20])
{
	cout << "Enter adjacency matrix: " <<endl;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> W[i][j];
}

void display(int n, int W[20][20])
{

	cout << "All pairs shortest path: " << endl;
	
	for(int i=0; i<n; i++)
	{

		for(int j=0; j<n; j++)
		{
			cout << W[i][j] << "\t" ;
		}
		cout << endl;
	}
}


int main()
{
	int n; // NUMBER OF NODES
	int W[20][20];

	cout << "Enter the number of nodes. " << endl;
	cin >> n;

	get_matrix(n, W);
	floyd(n, W);
	display(n, W);
	
	return 0;
}



/* OUTPUT

Enter the number of nodes. 
4
Enter adjacency matrix: 
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0
All pairs shortest path: 
0	10	3	4	
2	0	5	6	
7	7	0	1	
6	16	9	0

*/
