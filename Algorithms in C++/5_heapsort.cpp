#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int h[50];
void heapify(int h[],int n)
{
  int i,j,k,heap,v;
  for(i=n/2;i>=1;i--)
  {
    k=i;
    v=h[k];
    heap=0;
    while(!(heap) && (2*k)<=n)
    {
      j=2*k;
      if(j < n)
        if(h[j] < h[j+1])
          j = j + 1;
      if(v >= h[j])
        heap = 1;
      else
      {
        h[k] = h[j];
        k = j;
        h[k] = v;
      }
    }
  }
}

  int main()
  {
    int i,n,size,t;
    clock_t start,end;
    double totaltime;
    cout<<"enter value of n\n";
    cin>>n;
    cout<<"enter array elements\n"; 
    for(i = 1;i <= n; i++)
    {
    //h[i]=rand();
      cin>>h[i];
    }
    //display elements
    /*
    cout<<"elements\n";
    for(i = 1;i <= n; i++)
    {
      cout<<h[i]<<endl;
    }
    */
    start=clock();
    heapify(h,n);
    cout<<"elemts heapified:\n";
    for(i = 1;i <= n;i++)
      cout<<h[i]<<endl;

    for(i = n;i >= 1; i--)
    {
      t=h[1];
      h[1]=h[i];
      h[i]=t;
      size=i-1;
      heapify(h,size);
    }
    end=clock();
    cout<<"elemtents sorted\n";

    for(i=1;i<=n;i++)
      cout<<h[i]<<endl;

    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"time taken is"<<totaltime;
  }