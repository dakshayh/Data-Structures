#include<iostream>
#include<ctype.h>

using namespace std;

template<class T>
class aqueue
{
        T *q;
        int front, rear, ms;
public:
        aqueue(){ms=0;}
        aqueue(int size)
        {
                if(size <=0 )
                        throw "INVALID SIZE";
                ms = size;
                q = new T[ms];
                front = -1;
                rear = -1;
        }
        ~aqueue()
        {
                delete[] q;
        }

        void insert(T ele);
        T del();
        T first();
        T last();
        void display();
		void mergeQueues(aqueue &B);
        bool isfull()
        {
                return rear == ms-1;
        }
        bool isempty()
        {
                return (front == -1 && rear == -1) || (front > rear);
        }
};

template<class T>
void aqueue<T> :: insert(T ele)
{
        if(isfull())
                throw "No elment can be inserted as queue is full";
        if(isempty())
                front++;
        q[++rear] = ele;
}

template<class T>
T aqueue<T> :: del()
{
        T ele = q[front];
        if(isempty())
                throw "There are no elements in the queue to delete";
        front++;
        return ele;
}

template<class T>
T aqueue<T> :: first()
{
        return q[front];
}

template<class T>
T aqueue<T> :: last()
{
        return q[rear];
}

template<class T>
void aqueue<T> :: display()
{
        cout << endl;
        for(int i=front ; i<=rear ; i++)
                cout  << q[i] << " ";
        cout << endl;
}

template<class T>
void aqueue<T> :: mergeQueues( aqueue<T> &B)
{
    aqueue<T> *ptr=new aqueue<T>(ms+B.ms);
    while((!isempty()) || (!B.isempty()))
    {
        if (!isempty())
            ptr->insert(del());
        if (!B.isempty())
            ptr->insert(B.del());
    }
   // return *ptr;
   ptr->display();
}

