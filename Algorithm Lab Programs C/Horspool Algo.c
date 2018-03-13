#include <stdio.h>
#include <string.h>
int table[128];
void shifttable(char pattern[])
{
        int i,j,m;
        m=strlen(pattern);
        for(i=0; i<128; i++)
                table[i]=m;
        for(j=0; j<m-1; j++)
                table[pattern[j]]=m-j-1;
}
int horspool(char pattern[],char text[])
{
        int i,k,m,n;
        shifttable(pattern);
        m=strlen(pattern);
        n=strlen(text);
        i=m-1;
        while(i<n)
        {
                k=0;
                while(k<m && text[i-k]==pattern[m-1-k])
                        k++;
                if(k==m)
                        return(i-m+1);
                else
                        i+=table[text[i]];
        }
        return -1;
}
void main()
{
        int j;
        char pattern[100];
        char text[100];
        printf("Enter The Text\n");
//scanf("%s",text);
        gets(text);
        printf("Enter The Pattern\n");
//scanf("%s",pattern);
        gets(pattern);
        j=horspool(pattern,text);
        if(j)
                printf("Pattern found at position %d ",j+1);
        else
                printf("Pattern not found\n");
}
