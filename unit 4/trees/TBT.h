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
			if(l==NULL)
			{lc=this;lth=true;}
			else
			{lth=false;lc=l;}
			if(r==NULL)
			{rc=this;rth=true;}
			else
			{rth=false;rc=r;}
		//	cout<<1;
		}
	friend class TBTree<T>;
};
template<class T>
class TBTree
{
	TBTnode<T> *root;
	TBTnode<T> * inorderSucc(TBTnode<T> *);
	public:
		void insertLeft(TBTnode<T> *p,TBTnode<T> *q=NULL);
		void insertRight(TBTnode<T> *);
				
};
template<class T>
 TBTnode<T> * TBTree<T>::inorderSucc(TBTnode<T> *p)
{
	if(p->rth)
	return p->rc;
	else
	{
		p=p->rc;
		while(!p->lth)
		p=p->lc;
		return p;
	}
}
template<class T>
void TBTree<T>::insertLeft(TBTnode<T> *p,TBTnode<T> *q)
{
	if(q==NULL)
	{
		q=p;
		p=root;cout<<2;
	}
	cout<<3;
	q->lc=p->lc;
	q->lth=p->lth;
	q->rc=p;
	q->rth=true;
	p->lc=q;cout<<4;
	p->lth=false;
	if(!q->lth)
	{
		TBTnode<T> *temp=inorderSucc(q);
		temp->rc=q;
	}
}
