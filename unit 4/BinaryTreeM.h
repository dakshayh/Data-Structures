#include<iostream>
#include "stackLinkedList.h"
using namespace std;
template<class T>
class BTree;
template<class T>
class BTnode
{
	T data;
	BTnode<T> *lc,*rc;
	public:
		BTnode(T d,BTnode<T> *l,BTnode<T> *r)
		{
			data=d;
			rc=r;lc=l;
		}
		friend class BTree<T>;
};
template<class T>
class BTree
{
	BTnode<T> *root;
	public:
		BTree();
		BTree(T,BTree<T> &,BTree<T> &);
		void Traversal();
		bool isEmpty();
		BTree<T>* leftSubtree();
		BTree<T>* rightSubtree();
		void preorder(BTnode<T> *);
		void postorder(BTnode<T> *);
		void inorder(BTnode<T> *);
		void levelorder();
		int height();
		int nodes();
	     int height_r(BTnode<T> *);
		int nodes_r(BTnode<T> *);
		void preorder_nr();
		void postorder_nr();
		void inorder_nr();
};
template<class T>
int BTree<T>::height()
{
	return height_r(root);
}
template<class T>
int BTree<T>::nodes()
{
	return nodes_r(root);
}
template<class T>
BTree<T>::BTree()
{
	root=NULL;
}
template<class T>
BTree<T>::BTree(T val,BTree<T> &l,BTree<T> &r)
{
	root=new BTnode<T>(val,l.root,r.root);
	l.root=r.root=NULL;
}
template<class T>
void BTree<T>::Traversal()
{
	cout<<"\nPreorder:\n";
	preorder(root);
	cout<<"\nPostorder:\n";
	postorder(root);
	cout<<"\nInorder:\n";
	inorder(root);
/*	cout<<"\nLevelorder:\n";
	levelorder();*/
}
template<class T>
void BTree<T>:: preorder(BTnode<T> *p)
{
	if(p)
	{
		cout<<p->data;
		preorder(p->lc);
		preorder(p->rc);
	}
}
template<class T>
void BTree<T>:: postorder(BTnode<T> *p)
{
	if(p)
	{
		postorder(p->lc);
		postorder(p->rc);
		cout<<p->data;
	}
}
template<class T>
void BTree<T>:: inorder(BTnode<T> *p)
{
	if(p)
	{
		inorder(p->lc);
		cout<<p->data;
		inorder(p->rc);
	}
}
template<class T>
bool BTree<T>::isEmpty()
{
	return (root==NULL);
}
template<class T>
int BTree<T>::nodes_r(BTnode<T> *p)
{
	if(p==NULL)
	return 0;
	else if(p->lc==NULL&&p->rc==NULL)
	return 1;
	else
	return (1+nodes_r(p->lc)+nodes_r(p->rc));
}
template<class T>
BTree<T> * BTree<T>::leftSubtree()
{
	BTree<T> *temp=new BTree<T>;
	temp->root=root->lc;
	return temp;
}
template<class T>
BTree<T> * BTree<T>::rightSubtree()
{
	BTree<T> *temp=new BTree<T>;
	temp->root=root->rc;
	return temp;
}
template<class T>
int BTree<T>::height_r(BTnode<T> *p)
{
	if(p==NULL)
	return 0;
	else if(p->lc==NULL&&p->rc!=NULL)
	return 1+height_r(p->lc);
	else if(p->lc!=NULL&&p->rc==NULL)
	return 1+height_r(p->lc);
	else if(p->lc!=NULL&&p->rc!=NULL)
	{
		if(height_r(p->lc)>height_r(p->rc))
		return 1+height_r(p->lc);
		else
		return 1+height_r(p->rc);
	}
	else
	return 1;
}
template<class T>
void BTree<T>::inorder_nr()
{
	BTnode<T> *p=root;
	StackLL <BTnode<T> *>s;
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
		cout<<p->data;
		p=p->rc;
	}
}
template<class T>
void BTree<T>::preorder_nr()
{
	BTnode<T> *p=root;
	StackLL <BTnode<T> *>s;
	while(1)
	{
		while(p)
		{
			s.push(p);
			cout<<p->data;
			p=p->lc;
		}
		if(s.isEmpty())
		break;
		p=s.pop();
		p=p->rc;
	}	
}

