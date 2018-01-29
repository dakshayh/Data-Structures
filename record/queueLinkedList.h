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
		QueueLL();
		void insert(T);
		T Delete();
		void display();
		bool isEmpty();
};
template<class T>
QueueLL<T>::QueueLL()
{
	front=rear=NULL;
}
template<class T>
void QueueLL<T>::insert(T val)
{
	Node<T> *temp=new Node<T>;
	temp->data=val;
	temp->link=NULL;
	if(isEmpty())
	front=rear=temp;
	else
	{
	rear->link=temp;
	rear=temp;
	}
}
template<class T>
T QueueLL<T>::Delete()
{
	if(isEmpty())
	throw "\nthe queue is empty ...";
	Node<T> *temp=front;
	front=front->link;
	T val=temp->data;
	delete temp;
	return val;
}
template<class T>
void QueueLL<T>::display()
{
	if(isEmpty())
	throw "\nthe queue is empty ....";
	Node<T> *temp=front;
	while(1)
	{
		cout<<temp->data<<"  ";
		if(temp->link==NULL)
		break;
		temp=temp->link;
	}
}
template<class T>
bool QueueLL<T>::isEmpty()
{
	return (front==NULL||rear==NULL);
}
