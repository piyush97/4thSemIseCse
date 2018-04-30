#include <iostream>
using namespace std;

void get_array(int n, int A[500000])
{
	cout<<"Enter " << n << " elements. " << endl;

	for(int i=0; i<n; i++)
	{
		cin >> A[i];
	}
}



void get_array_random(int n, int A[500000])
{
	for(int i =0; i<n; i++)
	{
		A[i] = rand()%100;
	}
}



void print_array(int n, int A[500000])
{
	for(int i=0; i<n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


void heapify(int n, int A[500000], int root)
{
	int largest = root;
	int left = 2*root + 1;
	int right = 2*root + 2;

	if(left < n && A[left] > A[largest])
		largest = left;

	if(right < n && A[right] > A[largest])
		largest = right;

	if(largest != root)
	{
		swap(A[root], A[largest]);
		heapify(n,A,largest);
	}
}

void heapsort(int n, int A[500000])
{
	for (int i= n/2 - 1; i>=0; i--)
		heapify(n,A,i);

	for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(A[0], A[i]);
 
        // call max heapify on the reduced heap
        heapify(i, A, 0);
    }
}

int main()
{
	int n, A[500000];
	clock_t start, end;
	double total_time;

	cout << "Enter the number of elements: " << endl;
	cin >> n;

	//get_array(n,A);
	get_array_random(n,A);

	//cout<<"Unsorted array: " << endl;
	//print_array(n,A);

	start = clock();
	heapsort(n,A);
	end = clock();

	// cout<<"Sorted array: " << endl;
	// print_array(n,A);

	total_time = (double)(end-start)/CLOCKS_PER_SEC;
	cout << "Total time taken is " << total_time << endl;
}


/*OUTPUT
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ g++ heapsort.cpp
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
5
Enter 5 elements. 
2 7 4 10 3
Unsorted array: 
2 7 4 10 3 
Sorted array: 
2 3 4 7 10 
Total time taken is 5e-06
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ 

*/


/*OUTPUT

Ashwani@Ashwanis-MacBook-Air ~ $ cd Desktop
Ashwani@Ashwanis-MacBook-Air Desktop $ cd algorithmslab
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ g++ heapsort.cpp
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
20000
Total time taken is 0.010048
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
40000
Total time taken is 0.016997
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
60000
Total time taken is 0.027301
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
80000
Total time taken is 0.030228
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $ ./a.out
Enter the number of elements: 
100000
Total time taken is 0.033005
Ashwani@Ashwanis-MacBook-Air algorithmslab (master) $

*/