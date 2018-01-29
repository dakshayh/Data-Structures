#include<iostream>
#include "QueueLL.h"
using namespace std;
int main()
{
	int *a;
	void radix(int *,int);
	int n;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	radix(a,n);
}
void radix(int *a,int ms)
{
	int big,dig;dig=0;
	int i,j;
	for(i=0;i<ms-1;i++)
	{
		if(a[i]>a[i+1])
		big=a[i];
		else
		big=a[i+1];
	}
	while(big!=0)
	{
		dig++;
		big=big/10;
	}
	QueueLL<int> q[dig][10];
	int count=0;
	for(i=0;i<dig;i++)
	{
		if(count>0)
		{
			int p=0;
			for(j=0;j<10;j++)
			{
				if(q[count-1][j].isEmpty())
				continue;
				while(!q[count-1][j].isEmpty())
				a[p++]=q[count-1][j].Delete();
			}
		}
		count++;
		for(j=0;j<ms;j++)
		{
			int k,m;int p=a[j];
			for(k=0;k<count;k++)
			{
				m=p%10;
				p=p/10;
			}
			q[count-1][m].insert(a[j]);
		}
	}
	for(i=0;i<10;i++)
	{
		if(q[dig-1][i].isEmpty())
		continue;
		while(!q[dig-1][i].isEmpty())
		cout<<q[dig-1][i].Delete()<<"  ";
	}
}
