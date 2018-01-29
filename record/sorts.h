#include<iostream>
#include "queueLinkedList.h"
using namespace std;
template<class T>
class arr
{
	T *a;
	int ms;
	public:
		arr(int m=10)
		{
			ms=m;
			a=new T[ms];	
		}
		void getdata();
		void putdata();
		void insertion_sort();
		void merge_sort(int,int,int);
		void merge_sort_r(int,int);
		void swap(T &,T &);
		void quick_sort(int,int);
		void radix_sort();
};
template<class T>
void arr<T>::insertion_sort()
{
	int i;T temp;
	for(i=1;i<=ms-1;i++)
	{
		temp=a[i];int j=i-1;
		while(a[j]>temp&&j>=0)
		{
			a[j+1]=a[j];j--;
		}
		a[j+1]=temp;
	}
}
template<class T>
void arr<T>::swap(T &a,T &b)
{
	T t=a;
	a=b;
	b=t;
}

template<class T>
  void arr<T>::quick_sort(int left,int right)
  {
  int l=left;int r=right;
  T pivot=a[left];
  while(l<r)
  {
  while(a[r]>=pivot&&l<r)
        r--;
        if(l<r)
        a[l]=a[r];
  while(a[l]<=pivot&&l<r)
        l++;
        if(l<r)
        a[r]=a[l];

  // swap(a[l],a[r]);
        a[l]=pivot;
        getdata();//to see intermediate stages
  }
//  swap(a[left],a[r]);
        getdata();
        if(left<l)
  quick_sort(left,r-1);
        if(right>l)
  quick_sort(r+1,right);
  }
/*
template<class T>
void arr<T>::quick_sort(int left,int right)
{
	int l = left, r = right;
      T tmp;
      T pivot = a[(left + right) / 2];
      while (l <= r) 
	  {
            while (a[l] < pivot)
                  l++;
            while (a[r] > pivot)
                  r--;
            if (l <= r) {
                  tmp = a[l];
                  a[l] = a[r];
                  a[r] = tmp;
                  l++;
                  r--;
            }
      }
      if (left < r)
            quick_sort(left, r);
      if (right > l)
            quick_sort(l, right);
}*/
template<class T>
void arr<T>::merge_sort(int l1s,int l1e,int l2e)
{
	int i=l1s;int j=l1e+1;
	T temp[10];int p=0;
	while(i<=l1e&&j<=l2e)
	{
		if(a[i]<=a[j])
		temp[p++]=a[i++];
		else
		temp[p++]=a[j++];
	}
	for(;i<=l1e;i++)
	temp[p++]=a[i];
	for(;j<=l2e;j++)
	temp[p++]=a[j];
	p=0;
	for(i=l1s;i<=l2e;i++)
	a[i]=temp[p++];	
}
template<class T>
void arr<T>::merge_sort_r(int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		merge_sort_r(l,m);
		merge_sort_r(m+1,r);
		merge_sort(l,m,r);	
	}
}
template<class T>
void arr<T>::getdata()
{
	cout<<"\nthe array is : ";
	for(int i=0;i<ms;i++)
	cout<<a[i]<<"  ";
}
template<class T>
void arr<T>::putdata()
{
	for(int i=0;i<ms;i++)
	cin>>a[i];
}
template<class T>
void arr<T>::radix_sort()
{
	T big;int dig;dig=0;
	for(int i=0;i<ms-1;i++)
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
	int count=0;
	QueueLL <T>obj[dig][10];
	for(int i=0;i<dig;i++)
	{
		if(count>0)
		{
			int p=0;
			for(int j=0;j<10;j++)
			{
				
				if(obj[count-1][j].isEmpty())
				continue;
				while(!obj[count-1][j].isEmpty())
				a[p++]=obj[count-1][j].Delete();
			}
		}
		count++;
		for(int j=0;j<ms;j++)
		{
			int k=a[j];int m;
			for(int p=0;p<count;p++)
			{
				m=k%10;
				k=k/10;
			}
			obj[i][m].insert(a[j]);
		}
	}
	int p=0;
	for(int j=0;j<10;j++)
	{
		if(obj[dig-1][j].isEmpty())
		continue;
		while(!obj[dig-1][j].isEmpty())
		a[p++]=obj[dig-1][j].Delete();
	}
}
