#include<iostream>
using namespace std;
class heap
{
	int *a;
	int heapsize,ms;
	void heapify(int,int);
	public:
		heap(int m=5)
		{
			if(m<=0)
			throw "E";
			ms=++m;
			heapsize=0;
			a=new int[ms];
		}
		void insert();
		void display();
		void heapsort();
};
void heap::insert()
{
	int i;
	for(i=1;i<ms;i++)
	{cin>>a[i];heapsize++;}
}
void heap::display()
{
	cout<<endl;
	int i;
	for(i=1;i<ms;i++)
	cout<<a[i]<<"  ";
}
void heap::heapsort()
{
	int i;
	for(i=heapsize/2;i>=1;i--)
	heapify(i,heapsize);
	for(i=heapsize-1;i>=1;i--)
	{
		int t=a[1];
		a[1]=a[i+1];
		a[i+1]=t;
		heapify(1,i);
	}
	
}
void heap::heapify(int root,int n)
{
	int e=a[root];
	int j;
	for(j=2*root;j<=n;j=j*2)
	{
		if(j<n&&a[j]<a[j+1])
		j++;
		if(e>=a[j])
		break;
		a[j/2]=a[j];
	}
	a[j/2]=e;
}
int main()
{
	heap obj(7);
	obj.insert();
	obj.display();
	obj.heapsort();
	obj.display();
}

