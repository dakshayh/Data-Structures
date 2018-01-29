#include<iostream>
using namespace std;
template<class T>
class TBTree;
template<class T>
class TBTnode
{
	T data;
	TBTnode<T> *lc,*rc;
	bool lth,rth;
	public:
		TBTnode(T d,TBTnode<T> *l,TBTnode<T> *r)
		{
			data=d;
			rc=r;lc=l;
			lth=rth=true;
		}
		friend class TBTree<T>;
};
template<class T>
class TBTree
{
//	TBTnode<T> *root;
	TBTnode<T> * inorderSucc(TBTnode<T> *);
	TBTnode<T> * preSucc(TBTnode<T> *);
	public:
	TBTnode<T> *root;
	TBTree();
	TBTree(T,TBTree &,TBTree &);
	void inorder(TBTnode<T> *);
	void preorder(TBTnode<T> *);
	void insertRight(TBTree<T> &r);
			
};
template<class T>
TBTree<T>::TBTree()
{
	root=NULL;
}
template<class T>
TBTree<T>::TBTree(T d,TBTree<T> &l,TBTree<T> &r)
{
	root=new TBTnode<T>(d,l.root,r.root);
	l.root=NULL;
	r.root=NULL;
}
template<class T>
void TBTree<T>::inorder(TBTnode<T> *p)
{
	TBTnode<T> *temp=p;
	while(1)
	{
		temp=inorderSucc(temp);
		if(temp==p)
		break;
		cout<<"\t"<<temp->data;
	}
}
template<class T>
void TBTree<T>::preorder(TBTnode<T> *p)
{
	TBTnode<T> *temp=p;
	while(1)
	{
		temp=preSucc(temp);
		if(temp==p)
		break;
		cout<<"\t"<<temp->data;
	}
}
template<class T>
TBTnode<T> * TBTree<T>::preSucc(TBTnode<T> *p)
{
	if(p->lth==false)
	return p->lch;
	else
	{
		while(p->rth==true)
		p=p->rch;
		return p->rch;
	}
}
template<class T>
TBTnode<T> * TBTree<T>::inorderSucc(TBTnode<T> *p)
{
	TBTnode<T> *temp;
	temp=p->rc;
	if(!p->rth)
	while(!temp->lth)
	temp=temp->lc;
return temp;
}
template<class T>
void TBTree<T>::insertRight(TBTree<T> &q)
{
	TBTnode<T> *r,*s;
	r=root;s=q.root;
	r->rth=s->rth;
	r->lc=s;
	r->lth=true;
	s->rc=r;
	s->rth=false;
	if(!r->rth)
	{
		TBTnode<T> *temp=inorderSucc(r);
		temp->lc=r;
	}
}
