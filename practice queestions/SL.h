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
	Node<T> *top;
	public:
		StackLL(){
			top=NULL;
		}	
		void display();
		T pop();
		void push(T);
		T getTop();
		bool isEmpty(){
			return top==NULL;
		}
};
template<class T>
void StackLL<T>::display()
{
	if(isEmpty())
	throw "E";
	Node<T> *temp=top;
	while(1)
	{
		cout<<temp->data<<"\n";
		if(temp->link==NULL)
		break;
		temp=temp->link;
	}
}
template<class T>
void StackLL<T>::push(T val)
{
	Node<T> *temp=new Node<T>;
	temp->data=val;
	temp->link=top;
	top=temp;
}
template<class T>
T StackLL<T>::pop()
{
	if(isEmpty())
	throw "E";
	Node<T> *temp=top;
	top=top->link;
	T val=temp->data;
	delete temp;
	return val;
}
template<class T>
T StackLL<T>::getTop()
{
	if(isEmpty())
	throw "E";
	return top->data;
}
