#include<iostream>
using namespace std;
class sh
{
	int *a;
	int ms;
	public:
			void fill();
		sh(int s=5)
		{
			ms=5;
			a=new int[ms];
		}
		void moddiv(int);
		int search(int);
		void display();
		void Delete(int);
};
void sh::moddiv(int val)
{
	int r=val%ms;
	for(int i=r;i<ms;i++)
	{
		if(a[i]==0)
		{a[i]=val;return;}
	}
	for(int i=0;i<r;i++)
	{
		if(a[i]==0)
		{
			a[i]=val;return;
		}
	}
	throw "\nno space";
}
int sh::search(int val)
{
	int r=val%ms;
	int i;
	for(i=r;i<ms;i++)
	{
		if(a[i]==r)
		return i;
	}
	for(i=0;i<r;i++)
	{
		if(a[i]==r)
		return i;
	}
	return -1;
}
void sh::Delete(int val)
{
	int k=search(val);
	if(k==-1)
	throw "\nno element present ....";
	a[k]=0;
	cout<<"\ndeletion successful...";
}
void sh::display()
{
	for(int i=0;i<ms;i++)
	cout<<a[i]<<"  ";
}
void sh::fill()
{
	for(int i=0;i<ms;i++)
	a[i]=0;
}
int main()
{
	sh obj(5);
	obj.fill();
	for(int i=0;i<5;i++)
	{
		int k;
		cin>>k;
		obj.moddiv(k);
	}
	cout<<"\n";
	obj.display();
}
