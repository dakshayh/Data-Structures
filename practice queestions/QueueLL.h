#include<iostream>
using namespace std;
template<class T>
class QueueLL;
template<class T>
class Node
{
	T data;
	Node<T> *link;
	friend class QueueLL<T>;
};
template<class T>
class QueueLL
{
	Node<T> *front,*rear;
	public:
		QueueLL()
		{
			front=rear=NULL;
		}
		bool isEmpty()
		{
			return front==NULL;
		}
		void insert(T val)
		{
			Node<T> *ptr=new Node<T>;
			ptr->data=val;
			ptr->link=NULL;
			if(isEmpty())
			front=rear=ptr;
			else
			{
				rear->link=ptr;
				rear=ptr;
			}
		}
		T Delete()
		{
			if(isEmpty())
			throw "E";
			Node<T> *ptr=front;
			if(front==rear)
			front=rear=NULL;
			else
			front=front->link;
			T val=ptr->data;
			delete ptr;
			return val;
		}
		void display()
		{
			if(isEmpty())
			throw "E";
			Node<T> *ptr=front;
			while(1)
			{
				cout<<ptr->data;
				if(ptr->link==NULL)
				break;
				ptr=ptr->link;
			}
		}
};
