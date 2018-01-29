#include<iostream>
using namespace std;
template<class T>
struct chainNode
{
	T element;
	chainNode<T> *next;
	chainNode()
	{}
	chainNode(T ele)
	{
		element=ele;
	}
	chainNode(T ele,chainNode<T> *s)
	{
		element=ele;
		next=s;
	}
};
template<class T>
class chain
{
	int size;
	chainNode<T> *firstnode;
	void checkIndex(int);
	public:
		chain()
		{
		size=0;
		firstnode=NULL;
		}
		chain(chain<T> &);
		T get(int);
		void insert(T,int);
	//	void display();   intermediate testing function
		void erase(int);
};
template<class T>
void chain<T>::checkIndex(int i)
{
	if(i>size)
	throw -1;
}
template<class T>
chain<T>::chain(chain<T> &s)
		{
			size=s.size;
			if(size==0)
			{
				//empty list
				firstnode=NULL;
				return;
			}	
			chainNode<T> *source=s.firstnode;
			firstnode=new chainNode<T>(source.element);
			source=source->next;
			chainNode<T> *target=firstnode;
			while(source!=NULL)
			{
				target->next=new chainNode<T>(source->element);
				target=target->next;
				source=source->next;
			}
			target->next=NULL;
		}
template<class T>
void chain<T>::insert(T ele,int i)
{
	checkIndex(i);
	if(i==0)
	{
		firstnode=new chainNode<T>(ele,firstnode);
	}
	else
	{
		chainNode<T> *p=firstnode;
		for(int k=0;k<i-1;k++)
		{
			p=p->next;
		}
		p->next=new chainNode<T>(ele,p);
	}
	size++;
}
/*template<class T>
void chain<T>::display()
{
	cout<<"   "<<firstnode->element;
}*///intermediate testing function defination
