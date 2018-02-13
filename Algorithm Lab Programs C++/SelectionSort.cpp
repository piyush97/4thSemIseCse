#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void selectSort(int arr[], int n)
{
	int pos_min,temp;
	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;
		for (int j=i+1; j < n; j++)
		{
			if (arr[j] < arr[pos_min])
        pos_min=j;
		}
		
        if (pos_min != i)
        {
             temp = arr[i];
             arr[i] = arr[pos_min];
             arr[pos_min] = temp;
        }
	}
}

int main() 
{ 
  int i,n,a[50000]; 
  clock_t start,end; 
  double totaltime;  
  cout<<"enter the value of n\n";
  cin>>n;
 
  //Generate n random numbers 
  for(i=0;i<n;i++) 
  { 
     a[i]=rand(); 
  } 
 
 
//Call selection sort function 
start=clock(); 
selectSort(a,n); 
end=clock(); 
 
//Display sorted array 
//cout<<"sorted array\n"; 
//for(i=0;i<n;i++) 
//	cout<<a[i]<<endl; 
 
//Display the time taken to sort the elements 
totaltime=(double)(end-start)/CLOCKS_PER_SEC; 
cout<<"time taken is "<<totaltime;  
}