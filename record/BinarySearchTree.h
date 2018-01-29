#include<iostream> 
#include "stackLinkedList.h"
using namespace std;
template<class T>
class BST;
template<class T>
class BSTnode
{
        T data;
        BSTnode<T> *lc,*rc;
        public:
                BSTnode(T d,BSTnode<T> *l,BSTnode<T> *r)
                {
                        lc=l;
                        rc=r;
                        data=d;
                }
        friend class BST<T>;
};
template<class T>
class BST
{
        BSTnode<T> *root;
        public:
                BST()
                {
                root=NULL;
                }
                void insert(T);
                void Delete(T);
                void search(T);
                void inorder();
                void inorder_c(BSTnode<T> *);
};
template<class T>
void BST<T>::insert(T val)
{
        BSTnode<T> *ptr=root;
        BSTnode<T> *pp;
        if(ptr!=NULL)
        {
        while(ptr!=NULL)
        {
        	pp=ptr;
                if(val<ptr->data)
                {
                ptr=ptr->lc;}
                else if(val>ptr->data)
                {
                ptr=ptr->rc;
                }
                else
               { cout<<"\nduplication of values not allowed ....";break;}
        }
        if(val<pp->data)
        pp->lc=new BSTnode<T>(val,NULL,NULL);
        else if(val>pp->data)
        pp->rc=new BSTnode<T>(val,NULL,NULL);
        }
        else
        {
        root=new BSTnode<T>(val,NULL,NULL);
        }
}
template<class T>
void BST<T>::search(T val)
{
        BSTnode<T> *ptr=root;int flag=0;
        while(ptr)
        {
                if(val<ptr->data)
                ptr=ptr->lc;
                else if(val>ptr->data)
                ptr=ptr->rc;
                else
                {
                        cout<<"\nelement found ....";
                        flag=1;break;
                }
        }
        if(flag==0)
        cout<<"\nelement not found .....";
}
template<class T>
void BST<T>:: inorder()
{
        inorder_c(root);
}
template<class T>
void BST<T>::inorder_c( BSTnode<T> *p)
{

        StackLL <BSTnode<T> *>s;
        while(1)
        {
                while(p)
                {
                        s.push(p);
                        p=p->lc;
                }
                if(s.isEmpty())
                break;
                p=s.pop();
                cout<<p->data<<" ";
                p=p->rc;
        }
}
template<class T>
void BST<T>::Delete(T val)
{
        BSTnode<T> *pp;
        BSTnode<T> *ptr=root;int flag=0;
        while(ptr!=NULL)
        {
        if(val<ptr->data)
        {pp=ptr;ptr=ptr->lc;}
        else if(val>ptr->data)
        {pp=ptr;ptr=ptr->rc;}
        else
        {
        	flag=1;
			if(ptr->lc==NULL&&ptr->rc==NULL)//no child
			{
				if(pp->data>val)
				{
					pp->lc=NULL;
					delete ptr;
				}
				else
				{
					pp->rc=NULL;
					delete ptr;
				}
				break;
			}
			else if(ptr->lc!=NULL&&ptr->rc==NULL)//left child
			{
				if(pp->data>val)
				{
					pp->lc=ptr->lc;
					delete ptr;
				}
				else
				{
					pp->rc=ptr->lc;
					delete ptr;
				}
				break;
			}
			else if(ptr->lc==NULL&&ptr->rc!=NULL)//right child
			{
				if(pp->data>val)
				{
					pp->lc=ptr->rc;
					delete ptr;
				}
				else
				{
					pp->rc=ptr->rc;
					delete ptr;
				}
				break;
			}
			else   //both child
			{
				BSTnode<T> *temp=ptr;
				ptr=ptr->lc;
				while(ptr->rc!=NULL)
				ptr=ptr->rc;
				if(pp->data>val)
				{
					pp->lc=ptr;
					ptr->rc=temp->rc;
				}
				else
				{
					pp->rc=ptr;
					ptr->rc=temp->rc;
				}
				break;
			}
        }
        }
        if(flag==0)
        cout<<"\ndeletion not possible...";
        else
        cout<<"\ndeletion successful....";
}

