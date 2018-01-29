#include<iostream>
using namespace std;
int main()
{
	int *v1,*v2;int n;
	cin>>n;
	v1=new int[n];
	v2=new int[n];
	for(int i=0;i<n;i++)
	cin>>v1[i];
	for(int i=0;i<n;i++)
	cin>>v2[i];
	int i,j,k,*spro;int m;m=0;
/*	for(i=0;i<n;i++)
	{
		spro=0;
		for(j=0,k=i;j<n;j++,k++)
		{	if(k>=n)
			k=k-n;
				spro+=v1[k]*v2[k];
		}
		if(m==0)
		m=spro;
		else
		{
			if(m>spro)
			m=spro;
		}
		
		
	}
	cout<<m;*/
	spro=new int[n*n*n];
	int **count=new int*[n];
	for(i=0;i<n;i++)
	count[i]=new int[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		count[i][j]=v1[i]*v2[j];
	}
	int *lsum=new int[n];
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
		if(count[i][j]<count[i][j+1])
		{
		lsum[i]=count[i][j];spro[j]++;}
		else
		{lsum[i]=count[i][j+1];spro[j+1]++;}
		}
	}*/
	
	f
}
