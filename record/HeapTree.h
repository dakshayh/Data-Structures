#include<iostream>
using namespace std;
template<class T>
class heap
{
        T *h;
        int heapsize,maxsize;
        void heapify(int,int);
        void sizedouble();
        public:
                heap(int ms=10)
                {
                        if(ms<=0)
                        throw "\nwrong size input ...";
                        maxsize=++ms;
                        h=new T[maxsize];
                        heapsize=0;
                }
                void insert(T);
                T Delete();
                void display();
                void heapsort();
                void getdata();
};
template<class T>
void heap<T>::insert(T val)
{
        int cn=++heapsize;
        while(cn!=1&&h[cn/2]<val)
        {
                h[cn]=h[cn/2];
                cn=cn/2;
        }
        h[cn]=val;
}
template<class T>
T heap<T>::Delete()
{
        if(heapsize==0)
        throw "\nthe heap tree is empty...";
        T last=h[heapsize--];
        T first=h[1];
        int cn=1;int child=2;

        while(child<=heapsize)
        {
                if((child<heapsize)&&(h[child]<h[child+1]))
                child++;
                if(last>=h[child])
                        break;
                        h[cn]=h[child];
                        cn=child;
                        child=cn*2;
        }
        h[cn]=last;
        return first;
}
template<class T>
void heap<T>::display()
{
        cout<<"\nthe heap is : ";
        for(int i=1;i<=heapsize;i++)
        cout<<h[i]<<"  ";
}
template<class T>
void heap<T>::getdata()
{
        for(int i=1;i<maxsize;i++)
        {
                heapsize++;
                cin>>h[i];
        }
}
template<class T>
void heap<T>::heapsort()
{
        for(int i=heapsize/2;i>=1;i--)
        heapify(i,heapsize);
        for(int i=heapsize-1;i>=1;i--)
        {
                int t=h[1];
                h[1]=h[i+1];
                h[i+1]=t;
                heapify(1,i);
        }
}
template<class T>
void heap<T>::heapify(int root,int n)
{
        T e=h[root];
        int j;
        for(j=2*root;j<=n;j*=2)
        {
                if(j<n&&h[j]<h[j+1])
                j++;
                if(e>=h[j])
                break;
                h[j/2]=h[j];
        }
        h[j/2]=e;
}


