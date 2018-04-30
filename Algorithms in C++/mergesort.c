#include<stdio.h>
#define MAX 20

void merge(int [], int, int, int);
void part(int [], int, int);

void main()
{
	int a[MAX];
	int n, i;
	
	printf("Enter the number of elements to be sorted: \n");
	scanf("%d", &n);
	
	printf("Enter %d elements\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	part(a, 0, n - 1);
	
	printf("Sorted Elements are:\n");
	for(i = 0; i < n; i++)
		printf("%d\n", a[i]);
}

void part(int a[], int low, int high)
{
	int mid;
	
	if(low < high)
	{
		mid = (low + high) / 2;
		part(a, low, mid);
		part(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

void merge(int a[], int low, int mid, int high)
{
	int temp[30];
	int i,j,k,m;
	
	j = low;
	m = mid + 1;
	i = low;
	
	while(j <= mid && m <= high)
	{
		if(a[j] <= a[m])
		{
			temp[i] = a[j];
			j++;
		}
		
		else
		{
			temp[i] = a[m];
			m++;
		}
		i++;
	}
	
	if(j > mid)
	{
		for(k = m; k <= high; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
	
	else
	{
		for(k = j; k <= mid; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
	
	for(i = low; i <= high; i++)
		a[i] = temp[i];
}
