/*compute the transitive closure of a give directed grapgh using warshall's algorithm. Give the trace of thyis algorithm. */

#include <iostream>
using namespace std;

void warshall(int** a,int n)
{
    int i,j,k;

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j] = (a[i][j]||(a[i][k] && a[k][j]));
}

void floyd(int** a,int n)
{
    int i,j,k;

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
}

int main()
{
    int n,ch;
    int** a;

    cout<<"Enter 1 for warshall and 2 for floyds \n";
    cin>>ch;


    cout<<"Enter the order of the matrix: ";
    cin>>n;


    a = new int*[n];                 //n=rows
    for (int i = 0; i < n; ++i)
    a[i] = new int[n];             //n=cols

    cout<<"Enter the values of the matrix \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];


    switch(ch)
    {
        case 1:
            warshall(a,n);
            cout<<endl<<endl<<"Transitive closure: \n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<a[i][j]<<"\t";
                cout<<endl;
            }
        break;

        case 2:
            floyd(a,n);
            cout<<endl<<endl<<"shortest distance matrix: \n \n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<a[i][j]<<"\t";
                cout<<endl;
            }
        break;
        default:cout<<"Invalid choice \n";
    }
}