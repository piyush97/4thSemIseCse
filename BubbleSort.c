#include <stdio.h>
#include <time.h> 
  double totaltime;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void bubbleSort(int arr[], int n)
{
  clock_t start,end;
  start=clock();
   int i, j;
   for (i = 0; i < n-1; i++)      
 

       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
               end=clock();
   totaltime= ((double) (end - start)) / CLOCKS_PER_SEC;
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 

int main()
{
int i;
int arr[40];
    for(i=0;i<40;i++)
    {
    	arr[i]=random();
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
     printf("Total time %lf",totaltime);
    return 0;
   }
