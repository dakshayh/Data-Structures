#include<iostream>
using namespace std;
template<class T>
class Astack
{
        T *s;
        int ms,top;
        void sizeDouble();
        public:
                Astack();
                Astack(int);
                ~Astack();
                bool isFull();
                bool isEmpty();
                void push(T val);
                T pop();
                T getTop();
                void display();
};
template<class T>
Astack<T>::Astack()
{
        s=NULL;ms=0;top=-1;
}
template<class T>
Astack<T>::Astack(int size)
{
        if(size<=0)
        throw "INVALID VALUE OF SIZE ...";
        ms=size;top=-1;
        s=new T[ms];
        if(s==NULL)
        throw "memory not able to allocate ....";
}
template<class T>
Astack<T>::~Astack()
{
        delete []s;
}
template<class T>
bool Astack<T>::isFull()
{
        return top==ms-1;
}
template<class T>
bool Astack<T>::isEmpty()
{
        return top==-1;
}
template<class T>
void Astack<T>::push(T val)
{
        if(isFull())
        {
        cout<<"\nsize overflow ,, increasing the size of the stack...";
        sizeDouble();
        }
        s[++top]=val;
}
template<class T>
T Astack<T>::pop()
{
        if(isEmpty())
        throw "empty list...";
        return s[top--];
}
template<class T>
T Astack<T>::getTop()
{
        if(isEmpty())
        throw "empty list...";
        return s[top];
}
template<class T>
void Astack<T>::display()
{
        if(top==-1)
        throw "empty list...";
        for(int i=top;i>=0;i--)
        cout<<"\n"<<s[i];
}
template<class T>
void Astack<T>::sizeDouble()
{
        T *temp;
        ms=ms*2;
        temp=new T[ms];
        for(int i=0;i<=top;i++)
        {
                temp[i]=s[i];
        }
        delete []s;
        s=temp;
}
