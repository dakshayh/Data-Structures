#include<iostream>
using namespace std;
template<class T>
class cQueue
{
	T *q;
	int front,rear,ms;
	void sizeDouble();
	public:
		cQueue(int s=5);
		void display();
		void insert(T);
		T Delete();
		bool isFull();
		bool isEmpty();
};
template<class T>
cQueue<T>::cQueue(int s)
{
	ms=s;
	ms++;
	q=new T[ms];
	front=rear=0;
}
template<class T>
void cQueue<T>::insert(T val)
{
	if(isFull())
	throw "\nthe queue is full ...";
	rear=(rear+1)%ms;
	q[rear]=val;
}
template<class T>
T cQueue<T>::Delete()
{
	if(isEmpty())
	throw "\nthe queue is empty ...";
	front=(front+1)%ms;
	return q[front];
}
template<class T>
void cQueue<T>::display()
{
	if(isEmpty())
	throw "\nthe queue is empty ...";
	cout<<endl;
	int i;
	if(front>rear)
	{
	for(i=(front+1)%ms;i<ms;i++)
	cout<<q[i]<<" ";
	for(i=0;i<=rear;i++)
	cout<<q[i]<<" ";
	}
	else
	{
		for(i=front+1;i<=rear;i++)
		cout<<q[i]<<" ";
	}
}
template<class T>
bool cQueue<T>::isFull()
{
	return (rear+1)%ms==front;
}
template<class T>
bool cQueue<T>::isEmpty()
{
	return front==rear;
}
template<class T>
void cQueue<T>::sizeDouble()
{
        T *temp=new T[2*ms];
        if(front<rear)
        {
        copy(q,q+ms,temp);
        ms=ms*2;
        }
        else
        {
        int j=0;int i;
        for(i=(front+1)%ms;i<(ms);i++)
        temp[++j]=q[i];
        for(i=0;i<=rear;i++)
        temp[++j]=q[i];
        delete q;
        q=temp;
        rear=ms-1;
        front=0;
        ms=ms*2;
        }

} 
