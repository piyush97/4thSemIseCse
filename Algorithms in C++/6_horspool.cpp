#include <iostream>
#include <string.h>
#define MAX 200
using namespace std;


int t[MAX];
void shifttable(string p)
{
	int i,j,m;
	m=p.size();
	for(i=0;i<MAX;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[(int)p[j]]=m-1-j;
}

int horspol(string src, string p)
{
	int i,j,k,m,n;
	n=src.size();
	m=p.size();
	cout<<"\nlength of text= "<<n;
	cout<<"\nlength of pattern="<<m<<endl;
	i=m-1;
	while(i<=n-1)
	{   
		k=0;
		while((k<=m-1)&&(p[m-1-k]==src[i-k]))
		k++;
		if(k==m)
			return(i-m+1);
		else
			i+=t[src[i]];
	}
	return -1;
}
 
int main()
{
	string src,p;
	int pos;
	cout<<"enter the text:\n";
	getline(cin,src);
	cout<<"enter the pattern:\n";
	getline(cin,p);
	shifttable(p);
	pos=horspol(src,p);
	if(pos>=0)
		cout<<"The pattern is found at position "<<pos+1<<endl;
	else
		cout<<"The pattern is not in the text\n";
}
