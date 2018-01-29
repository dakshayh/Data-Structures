#include<iostream>
using namespace std;
int main()
{
	int i;int k=0;
	for(i=0;i<=1000;i++)
	{
		if((i%15)==0||(i%35==0)||(i%40)==0)
		k++;
	}
	cout<<k;
}
