#include<iostream>
using namespace std;
template<class T>
class doubleLinkList;
template <class T>
class DNode
{
        T data;
        DNode<T> *left,*right;
        friend class doubleLinkList<T>;
};
template<class T>
class doubleLinkList
{
        DNode<T> *first,*last;
        public:
                doubleLinkList();
                void display();
                T FDelete();
                T MDelete(int);
                T LDelete();
                void Finsert(T);
                void Linsert(T);
                void Minsert(T,int);
};
template<class T>
doubleLinkList<T>::doubleLinkList()
{
first=last=NULL;
}
template<class T>
void doubleLinkList<T>::Finsert(T val)
{
        DNode<T> *temp=new DNode<T>;temp->data=val;
        if(first==NULL)
        {
                temp->left=NULL;
                temp->right=NULL;
                first=last=temp;
        }
        else
        {
                temp->left=NULL;
                temp->right=first;
                first->left=temp;
                first=temp;
        }
}
template<class T>
void doubleLinkList<T>::Linsert(T val)
{
        DNode<T> *temp=new DNode<T>;temp->data=val;
        if(first==NULL)
        {
                temp->left=NULL;
                temp->right=NULL;
                first=last=temp;
        }
        else
        {
                temp->right=NULL;
                last->right=temp;
                temp->left=last;
                last=temp;
        }
}
template<class T>
void doubleLinkList<T>::Minsert(T val,int p)
{
        if(first==NULL)
        throw "\nempty list ....";
        DNode<T> *temp=first;int i=1;
        DNode<T> *ptr=new DNode<T>;ptr->data=val;
        while(i<p-1)
        {
                temp=temp->right;
                i++;
        }
        ptr->left=temp;
        ptr->right=temp->right;
        temp->right=ptr;
}
template<class T>
T doubleLinkList<T>::FDelete()
{
        if(first==NULL)
        throw "\nthe list is empty ...";
        DNode<T> *temp;
        temp=first;
        T val=temp->data;
        if(temp->right==NULL)
        {
        first=last=NULL;
        }
        else
        {
        first->right->left=NULL;
        }
        first=first->right;
        delete temp;
        return val;
}
template<class T>
T doubleLinkList<T>::LDelete()
{
        if(last==NULL)
        throw "\nthe list is empty ...";
        DNode<T> *temp;
        temp=last;
        T val=temp->data;
        if(temp->left==NULL)
        first=last=NULL;
        else
        last->left->right=NULL;
        last=last->left;
        delete temp;
        return val;
}
template<class T>
T doubleLinkList<T>::MDelete(int p)
{
        if(first==NULL)
        throw "\nthe list is empty ...";
        DNode<T> *temp,*ptr;
        int i=1;temp=first;
        while(i<p-1)
        {
                temp=temp->right;
                i++;
        }
        ptr=temp->right;
        T val=ptr->data;
        temp->right=ptr->right;
        ptr->right->left=temp;
        delete ptr;
        return val;
}
template<class T>
void doubleLinkList<T>::display()
{
        if(first==NULL)
        throw "\nthe list is empty ...";
        cout<<endl;
        DNode<T> *temp;temp=first;
        do
        {
                cout<<temp->data<<"  ";
                temp=temp->right;
        }while(temp->right!=NULL);
}

