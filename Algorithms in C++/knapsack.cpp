#include<iostream>
using namespace std;
 
int max(int a,int b) 
{ 
         if(a>b) 
           return a; 
        else 
           return b; 
} 
 
void knapsack(int m,int n,int w[],int p[]) 
{ 
        int v[100][200],x[10],i,j,sum=0; 
 
        for(i=0;i<=m;i++) 
                v[0][i]=0;  
 
        for(i=0;i<=n;i++) 
        { 
                 for(j=0;j<=m;j++) 
                 { 
                          if(j>=w[i]) 
                                  v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]); 
                          else 
                                v[i][j]=v[i-1][j]; 
                } 
        } 
 
        for(i=0;i<=n;i++) 
                x[i]=0; 
 
        i=n; 
        j=m; 
        while(i>0&&j>0) 
        { 
                if(v[i][j]!=v[i-1][j]) 
                 { 
                        x[i]=1; 
                         j=j-w[i]; 
                 } 
                i--; 
        } 
 
        cout<<"\nThe optimal set of items is:\n"; 
        for(i=0;i<=n;i++) 
        { 
                 if(x[i]==1) 
                 { 
                        cout<<"\t"<<i; 
                        sum=sum+p[i]; 
                } 
 
        }
        cout<<"\n\ntotal profit="<<sum<<"\n"; 
} 
 
int main() 
{ 
        int w[10],p[10],m,n,i;
         
        cout<<"enter no of items:\n"; 
        cin>>n; 
        cout<<"enter the weights of the items:\n"; 
        for(i=1;i<=n;i++) 
                cin>>w[i]; 
        cout<<"enter the profits:\n"; 
        for(i=1;i<=n;i++) 
                cin>>p[i]; 
        cout<<"enter the capacity of knapsack:\n"; 
        cin>>m; 
        knapsack(m,n,w,p); 
        return 0; 
}
