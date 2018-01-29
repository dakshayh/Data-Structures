#include<iostream>
using namespace std;
template<class T>
class SLL;
template<class T>
class CNode
{
    T data;
    CNode<T>*link;
    friend class SLL<T>;
};
template<class T>
class SLL
{
    CNode<T> *first,*last;
public:
    bool isempty(){return first==NULL;}
    SLL(){first=NULL;}
    void LInsert(T &ele);
    void display();
    class chainiterator
    {
        CNode<T>*current;
        public:
                chainiterator(CNode<T>*cn)
                {
                        current=cn;
                }
                T *operator->()
                {
                        return &current->data;
                }
                chainiterator & operator++()
                {
                        current=current->link;
                        return *this;
                }
                bool operator!=(chainiterator right)
                {
                        return current!=right.current;
                }

    };
chainiterator begin()
{
        return chainiterator(first);
}
chainiterator end()
{
        return chainiterator(0);
}
};
template<class T>
void SLL<T>::LInsert(T &ele)
{
    CNode<T>*ptr=new CNode<T>;
    ptr->data=ele;
    ptr->link=NULL;
    if(first==NULL)
    {
        first=last=ptr;
    }
    else
    {
        last->link=ptr;
        last=ptr;
    }
}
template<class T>
void SLL<T>::display()
{
    if(isempty())
        throw "List is empty.Cannot display";
    for(CNode<T>*p=first;p!=NULL;p=p->link)
        cout<<p->data<<" ";
}


