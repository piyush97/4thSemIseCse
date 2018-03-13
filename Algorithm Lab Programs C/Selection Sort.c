#include <stdio.h>
#include <time.h>
void main(){
        int i,n,temp,j,min;
        printf("Enter the value of n\n");
        scanf("%d",&n);
        int a[n];
        for(i=n; i>=1; i--) {
                a[n-i]=i;
        }
        clock_t start,end;
        double cputime;
        start=clock();
        for(i=0; i<n-1; i++)
        {
                min=i;
                for(j=i+1; j<n; j++)
                {
                        if(a[j]<a[min])
                                min=j;
                }
                temp=a[j];
                a[j]=a[min];
                a[min]=temp;
        }
        end=clock();
        cputime=((double)(end-start))/CLOCKS_PER_SEC;
        printf("time is %lf\n",cputime);
}
