#include <stdio.h>
#include <time.h> 
  double totaltime;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
  clock_t start,end;

  start=clock();
    int i, j, min_idx;
 

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 

        swap(&arr[min_idx], &arr[i]);
    }
    end=clock();
   totaltime= ((double) (end - start)) / CLOCKS_PER_SEC;
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int i,arr[40];
    printf("Enter Elements");
    for(i=0;i<40;i++)
    {
    	arr[i]=rand();
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("Total time %lf",totaltime);
    return 0;
}
