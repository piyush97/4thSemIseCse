#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	/*int a[10]={6,2,4,7,1,3,8,9,0,5};
	bsort(a,10);*/

	cout<<"Bubble sort \n";
	double totaltime,temp,r;
	clock_t start,end;
	int i, j,n;
	double arr[100000];

	cout<<"Enter value of n \n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		arr[i]=rand();
		/*r=rand()%50000;
		arr[i]=(double)r;*/
		/*cout<<arr[i]<<endl;*/
	}

	start = clock();


	for(i=0;i<n;i++)
		for (j=0; j < n-i-1; j++)
		{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
		}

		end = clock();

		totaltime = (double) (end-start)/CLOCKS_PER_SEC;
		cout<<"Total time = "<<totaltime<<endl;
}