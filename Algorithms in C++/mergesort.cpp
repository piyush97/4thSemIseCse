#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


//merge algorithm

void merge(int a[], int low, int middle, int high)
{
	int i,j,k;
	int b[500000];
	i=low; k=low; j=middle+1;

	//compare the two arrays 
	//and keep adding the smaller 
	//element in a new array
	while(i<=middle && j<=high)
	{
		if(a[i]<=a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	//if elements in any one array is over
	//copy the remaining elements in the 
	//other array in the new array
	while(i<=middle)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];

	//Now copy the new array back
	//to the original array

	for(k=0; k<=high; k++)
		a[k] = b[k];
}

void mergesort(int a[], int low, int high)
{
	int middle;
	if(low<high)
	{
		middle = (low+high)/2; //find the middle element
		mergesort(a,low,middle); // Apply mergesort to first half of array
		mergesort(a,middle+1,high); // Apply mergesort to second half of array
		merge(a,low,middle,high); //Merge the two halves
	}
}

void getElements(int a[], int size)
{
	for(int i=0; i<size; i++)
	{
		a[i] = rand()%100; // Random numbers 0-99
	}
}

void display(int a[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[500000];
	int low, middle, high;
	int size;	
	clock_t start,end;
	double totaltime;

	cout<<"Enter array size: ";
	cin>>size;

	getElements(a,size);
	
	// cout<<"Unsorted array: "<<endl;
	// display(a,size);


	start = clock();
		mergesort(a,0,size-1);
	end = clock();

	// cout<<"Sorted array: "<<endl;
	// display(a,size);

	totaltime = (double)(end-start)/(CLOCKS_PER_SEC);
	cout<<endl;
	cout<<"The time taken is " <<totaltime<< endl;

	return 0;
}
