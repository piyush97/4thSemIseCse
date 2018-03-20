#include <stdio.h>
#include <time.h>
void quicksort(int count,int number[count],int first,int last){
        int i, j, pivot, temp;

        if(first<last) {
                pivot=first;
                i=first;
                j=last;

                while(i<j) {
                        while(number[i]<=number[pivot]&&i<last)
                                i++;
                        while(number[j]>number[pivot])
                                j--;
                        if(i<j) {
                                temp=number[i];
                                number[i]=number[j];
                                number[j]=temp;
                        }
                }

                temp=number[pivot];
                number[pivot]=number[j];
                number[j]=temp;
                quicksort(count,number,first,j-1);
                quicksort(count,number,j+1,last);

        }
}

int main(){
        int i, count;

        printf("How many elements are u going to enter?: ");
        scanf("%d",&count);
        int number[count];
        for(i=count; i>0; i--)
                number[count-i]=i;
        clock_t start,end;
        start=clock();
        quicksort(count,number,0,count-1);
        end=clock();
        printf("Order of Sorted elements: ");
        for(i=0; i<count; i++)
                printf(" %d",number[i]);
        float time=(float)(end-start)/CLOCKS_PER_SEC;
        printf("time taken is = %f ",time);
        return 0;
}
