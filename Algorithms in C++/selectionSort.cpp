#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Selection
{
	int size;
	int a[200000];
	
	public:
		Selection()
		{
			cout<<"Enter the size: "<<endl;
			cin>>size;
		}
		
		//generating random numbers from 0 to 99.
		void getElements()
		{
			for(int i=0; i<size; i++)
			{
				a[i] = rand() % 100;
			}
		}

	
		//selection sort algorithm
		void selectionSort()
		{
			int i,j;
			int min;
	
			for(i=0; i<size-1; i++)
			{
				min = i;
		
				for(j=i+1; j<size; j++)
				{
					if(a[j] < a[min])
						min = j;
				}
//call the swap function only when it is required. Omitting this condition takes up space in the stack and increases computation time.
				if(min != i)	//optional condition
					swap(a[min], a[i]);
		
			} // end outer for	
		}	

	
		//swapping two numbers
		void swap(int &x, int &y)
		{
			int temp;
			temp = x;
			x=y;
			y=temp;
		}
	
		//display in the case of test output
		//You need to make a call to this function.
		void display()
		{
			for(int i=0; i<size; i++)
				cout<<a[i]<<" ";
		}
		
}; // end of class

int main()
{
	Selection obj;
	obj.getElements();
	
	clock_t start,end;
	double total_time;
	
	start=clock();		//get the time just before the algorithm starts
	obj.selectionSort();
	end = clock();		//get the time just after the algorithm ends

	
	total_time = (double)(end - start)/(CLOCKS_PER_SEC);	
	
	cout<<endl<<"The time taken is " << total_time << "seconds."<<endl;
	
	return 0;
}
