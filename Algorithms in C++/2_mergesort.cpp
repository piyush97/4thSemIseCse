#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
 
void merge(int a[],int low,int mid,int high) 
{ 
  int i,j,k,b[50000]; 
  i=low;j=mid+1;k=low; 
 
  while(i<=mid && j<=high) 
  { 
    if(a[i]<=a[j]) 
      b[k++]=a[i++]; 
    else 
      b[k++]=a[j++]; 
  } 
 
  while(i<=mid) b[k++]=a[i++]; 
  while(j<=high)b[k++]=a[j++]; 
 
 
  for(k=low;k<=high;k++) 
    a[k]=b[k]; 
} 
 
 
 
 
void mergesort(int a[],int low,int high) 
{ 
  int mid; 
  if(low>=high) 
  return; 
 
  mid=(low+high)/2; 
  mergesort(a,low,mid); 
  mergesort(a,mid+1,high); 
  merge(a,low,mid,high); 
} 
 
 
 
 
int main() 
{ 
  int n,a[50000],k,r; 
  clock_t start,end; 
  double totaltime; 
  cout<<"enter value of n \n"; 
  cin>>n;
  for(k=0;k<n;k++) 
  { 
    r=rand(); 
    a[k]=r; 
  } 
 
  start=clock(); 
  mergesort(a,0,n-1); 
  end=clock(); 
 
 
  /*for(k=0;k<n;k++) 
  cout<<a[k]<<endl;*/
  totaltime=(double)(end-start)/CLOCKS_PER_SEC; 
  cout<<"time taken is: "<<totaltime<<endl; 
  
}