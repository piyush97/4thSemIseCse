#include <stdio.h>
 
void main()
{
	int a[10], n, i, j, max, temp;
 
	printf("Enter number of elements\n");
	scanf("%d", &n);
 
	printf("Enter %d integers\n", n);
 
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
 
	for(i = 0; i < (n - 1); i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[max] > a[j])
			max = j;
		}
		if (max != i)
		{
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}
 
	printf("Sorted list in ascending order:\n");
 
	for(i = 0; i < n; i++ )
		printf("%d\n", a[i]);
}
