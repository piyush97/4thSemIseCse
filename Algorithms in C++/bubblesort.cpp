/*This program uses random variables to insert the elements of the array. 
If you want to see the result, uncomment the commented lines. */

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Bubble
{
	int size;
	int a[200000];
	public:
		Bubble()		//constructor to get the size at the time of creating the object
		{
			cout<<"Enter the size: ";
			cin >> size;	
		}
		
		
		
		void swap(int &x, int &y)
		{
			int temp;
			temp = x;
			x = y;
			y = temp;
		}
		
		void getElements()
		{
			int i;
			//cout<<"Put the elements in: " <<endl;
			
			for(i=0; i<size; i++)
				a[i] = rand() % 100; // Generating random numbers between 0 to 99 and assigning it to array.
		}
		
	//Algorithm for bubble sort.
		void bubbleSort()
		{
			int i,j;
			
			for(i=0; i<size; i++)
				for(j=0; j<size-1-i; j++)
				{
					if(a[j] > a[j+1])
					{
						swap(a[j], a[j+1]);
					}
				}
						
		}
		
		void display()
		{
			int i;
			for(i=0; i<size; i++)
				cout << a[i] << "  ";
		}
};


int main()
{
	Bubble obj;
	
	obj.getElements();
	//cout<<"Unsorted elements are: " << endl;
	//obj.display();
	clock_t start, end;
	double total_time;
	start = clock();	
	obj.bubbleSort();
	end = clock();
	total_time =(double) (end - start)/(CLOCKS_PER_SEC);
	//cout<<endl << "Sorted elements are: " << endl;
	//obj.display();
	cout<< endl << "The time taken is " << total_time <<" seconds."<<endl;
	
	return 0;
		
}
// You may also want to check out the graph for the program the link for which is given below.
// Copy the url and paste it in your browser's address bar to see the graph.

/************* GRAPH ***************/
/*

https://drive.google.com/file/d/0B4UekpEoeMP8RjNxYThtcERBUTg/view?usp=sharing

*/
