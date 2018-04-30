#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int partition(int a[],int left,int right)
{
	int pivot = a[left]; //taking first element as pivot
	int i=left; int j=right+1;

	do{
		do{
			i=i+1;
		}while(a[i] < pivot);

		do{
			j=j-1;
		}while(a[j] > pivot);

		swap(a[i],a[j]);

	}while(i<j);

	swap(a[i],a[j]);
	swap(a[left],a[j]);
	return j;
}


void quicksort(int a[],int left,int right)
{
	if(left < right)
	{
		int s = partition(a,left,right); // s is split position
		quicksort(a,left,s-1);
		quicksort(a,s+1,right);
	}
}



void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
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
	int left,right;
	int size;
	clock_t start,end;
	double totaltime;

	cout<<"Enter array size: ";
	cin>>size;

	getElements(a,size);

	//cout<<"Unsorted array: "<<endl;
	//display(a,size);

	start = clock();
		quicksort(a,0,size-1);
	end = clock();

	//cout<<"Sorted array: "<<endl;
	//display(a,size);

	totaltime = (double)(end-start)/(CLOCKS_PER_SEC);
	cout<<endl;
	cout<<"The time taken is " <<totaltime<< " seconds. "<< endl;

	return 0;

}
