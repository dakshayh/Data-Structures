#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a;int n;
	cin>>n;
	a=pow(3+sqrt(5),n);
	int b=a;
	int i=0;int r=0;
	while(i<3)
	{
		int k=b%10;
		r=r*10+k;
		b=b/10;
		i++;
	}
	i=0;
	while(i<3)
	{
		cout<<r%10;
		r=r/10;i++;
	}
}
