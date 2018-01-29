#include<iostream>
using namespace std;
template<class T>
class StackLL;
template<class T>
class Node
{
	T data;
	Node<T> *link;
	friend class StackLL<T>;	
};
template<class T>
class StackLL
{
	Node<T> *last;
	public:
		StackLL();
		void push(T);
		T pop();
		void display();
		bool isEmpty();
		T getTop();
};
template<class T>
StackLL<T>::StackLL()
{
	last=NULL;
}
template<class T>
void StackLL<T>::push(T val)
{
	Node<T> *temp=new Node<T>;
	temp->data=val;
	temp->link=last;
	last=temp;
}
template<class T>
T StackLL<T>::pop()
{
	if(isEmpty())
	throw "\nthe stack is empty...";
	Node<T> *temp;
	temp=last;
	last=last->link;
	T val=temp->data;
	delete temp;
	return val;
}
template<class T>
bool StackLL<T>::isEmpty()
{
	return (last==NULL);
}
template<class T>
void StackLL<T>::display()
{
	if(isEmpty())
	throw "\nthe stack is empty...";
	cout<<"\nthe stack is : ";
	Node<T> *temp=last;
	while(1)
	{
		cout<<temp->data<<endl;
		if(temp->link==NULL)
		break;
		temp=temp->link;
	}
}
template<class T>
T StackLL<T>::getTop()
{
	if(isEmpty())
	throw "\nthe stack is empty ....";
	return last->data;
}
