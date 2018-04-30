#include <iostream>
#include <math.h>
using namespace std;

int max(int a, int b)
{
 if(a>b)
 	return(a);
 else
 	return(b);

}

void warshal(int r[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
 		for(i=1;i<=n;i++)
  			for(j=1;j<=n;j++)
   				r[i][j] = max(r[i][j],r[i][k]&&r[k][j]);

   	cout<<"Transitive closure"<<endl;

	for(int i=1;i<=n;i++)
	{
 		for(int j=1;j<=n;j++)
 		{
  			cout<<r[i][j];
 		}
 		cout<<endl;
 	}

}
int main()
{
	int r[10][10],a[10][10],i,j,n;

	cout<<"Enter the number of vertices: "<<endl;
	cin>>n;
	cout<<"Enter adjacency matrix"<<endl;
	
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			cin>>r[i][j];

	warshal(r,n);


}
