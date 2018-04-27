#include<iostream>
#include<math.h>
using namespace std;
int board[20],count;
int main()
{
  int n,i,j;
  void queen(int row,int n);
  cout<<"\nEnter number of Queens: ";
  cin>>n;
  queen(1,n);
}
void print(int n)
{
  int i,j;
  cout<<"\n\nSolution : "<<++count;
  for(i=1;i<=n;++i)
  {
  cout<<"\n"<<i;
    for(j=1;j<=n;++j)
    {
      if(board[i]==j)
        cout<<"\tQ";
      else
        cout<<"\t-";
    }
  }
}
int place(int row,int column)
{
  int i;
  for(i=1;i<=row-1;++i)
  {
    if(board[i]==column)
      return 0;
    else
      if(fabs(board[i]-column)==fabs(i-row))
        return 0;
    }
    return 1; 
}
void queen(int row,int n)
{
  int column;
  for(column=1;column<=n;++column)
  {
    if(place(row,column))
    {
      board[row]=column;
      if(row==n) 
        print(n); 
      else 
        queen(row+1,n);
    }
  }
}