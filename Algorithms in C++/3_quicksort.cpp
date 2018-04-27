#include <iostream> 
#include <stdlib.h>
#include <time.h> 
using namespace std; 
/* Program3: Quicksort*/ 
 
//Finds split position in the given array 
int partition(int a[], int low, int high) 
{ 
  int key,i,j,temp,k; 
  key=a[low]; 
  i=low+1; 
  j=high; 
  while(i<=j) 
  { 
    while(i<=j && key>=a[i]) 
    i=i+1; 
 
    while(key<a[j]) 
    j=j-1; 
 
    if(i<j) 
    { 
      temp=a[i]; 
      a[i]=a[j]; 
      a[j]=temp; 
    } 
    else 
    { 
      k=a[j]; 
      a[j]=a[low]; 
      a[low]=k; 
    } 
  } 
 
return j; 
} 
  
//Sorts array in ascending order 
void quicksort(int a[],int low,int high) 
{ 
  int pos; 
  if (low>=high)
    return;

   pos=partition(a,low,high); 
   quicksort(a,low,pos-1); 
   quicksort(a,pos+1,high); 
  
} 
 
 
int main() 
{ 
  int i,n,a[500000]; 
  clock_t start,end; 
  double totaltime;  
  cout<<"enter the value of n\n";
  cin>>n;
 
  //Generate n random numbers 
  for(i=0;i<n;i++) 
  { 
     a[i]=rand(); 
  } 
 
 
//Call quicksort function 
start=clock(); 
quicksort(a,0,n-1); 
end=clock(); 
 
//Display sorted array 
//cout<<"sorted array\n"; 
//for(i=0;i<n;i++) 
//cout<<a[i]<<endl; 
 
//Display the time taken to sort the elements 
totaltime=(double)(end-start)/CLOCKS_PER_SEC; 
cout<<"time taken is "<<totaltime;  
}