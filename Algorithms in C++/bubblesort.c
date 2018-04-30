
#include<stdio.h>
 
void bubble_sort(int [], int);
 
void main()
{
	int arr[30], num, i, j, temp;
 
	printf("Enter no of elements:\t");
	scanf("%d", &num);
 
	printf("Enter array elements:\n");
	for (i = 0; i < num; i++)
		scanf("%d", &arr[i]);
		
	for (i = 1; i < num; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	printf("Sorted array elements:\n");
	for(i = 0; i < num; i++)
		printf("%d\n", arr[i]);
}
