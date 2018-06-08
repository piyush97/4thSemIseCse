# include<stdio.h>
# define max 505

int men[max][max],women[max][max],mmark[max],mc[max],wc[max];

int wprefer(int w,int m,int m1,int n)
{
  int i;
  for(i=1;i<=n;i++)
 {
   if(women[w][i]==m)
   return 1;
   else if(women[w][i]==m1)
   return 0;
 }
}

void stable_match(int n)
{
  int i,freecount;
  for(i=1;i<=max;i++)
 {
  wc[i]=-1;
  mmark[i]=0;
 }
  freecount=n;
  while(freecount>0)
 {
  int m;
  for(m=1;m<=n;m++)
  for(i=1;i<=n&&mmark[m]==0;i++)
  {
   int w=men[m][i];
   if(wc[w]==-1)
   {
    wc[w]=m;
    mmark[m]=1;
    freecount--;
   }
   else
   {
    int m1=wc[w];
    if(wprefer(w,m,m1,n))
    {
     wc[w]=m;
     mmark[m1]=0;
    mmark[m]=1;
   }
  }
 }
}
}

int main()
{
  int n,i,j;
  printf("enter the number of men and women\n");
  scanf("%d",&n);
  printf("enterthe preference list of women\n");
  for(i=1;i<=n;i++)
 {
  printf("enter the preference list of %d women:\n",i);
  for(j=1;j<=n;j++)
  {
   scanf("%d",&women[i][j]);
  }
 }
  printf("enter the preference list of men\n");
  for(i=1;i<=n;i++)
 {
  printf("enter the preference list of %d men:\n",i);
  for(j=1;j<=n;j++)
 {
  scanf("%d",&men[i][j]);
 }
}
  
  stable_match(n);
  for(i=1;i<=n;i++)
  mc[wc[i]]=i;
  printf("the stable matching is:\n");
  for(i=1;i<=n;i++)
  printf("%d woman with %d man\n",i,mc[i]);
return 0;
}
