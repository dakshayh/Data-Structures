#include<iostream>
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
//		BTnode<T> *root;
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
	     int height(BTree<T> *);
		int nodes(BTree<T> *);
};
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
int BTree<T>::nodes(BTree<T> *p)
{
/*	BTnode<T> *ltemp,*rtemp;
	int i,j;i=j=0;
	ltemp=root->lc;
	rtemp=root->rc;
	while(1)
	{
		if(ltemp==NULL&&rtemp==NULL)
		{
			break;
		}
		else if(rtemp==NULL)
		{
			if(ltemp->lc==NULL&&ltemp->rc==NULL)
			{
				i++;ltemp=NULL;
			}
			else if(ltemp->lc==NULL)
			{
				i++;
				ltemp=ltemp->rc;
			}
			else if(ltemp->rc==NULL)
			{
				i++;
				ltemp=ltemp->lc;
			}
			
		}
		else if(ltemp==NULL)
		{
			if(rtemp->lc==NULL&&rtemp->rc==NULL)
			{
				j++;rtemp=NULL;
			}
			else if(rtemp->lc==NULL)
			{
				j++;
				rtemp=rtemp->rc;
			}
			else if(rtemp->rc==NULL)
			{
				j++;
				rtemp=rtemp->lc;
			}
		}
		else if(ltemp->lc==NULL&&ltemp->rc!=NULL)
		{
			i++;
			ltemp=ltemp->rc;
		}
		else if(ltemp->rc==NULL&&ltemp->lc!=NULL)
		{
			i++;
			ltemp=ltemp->lc;
		}
		else if(rtemp->lc==NULL&&rtemp->rc!=NULL)
		{
			j++;
			rtemp=rtemp->rc;
		}
		else if(rtemp->rc==NULL&&rtemp->lc!=NULL)
		{
			j++;
			rtemp=rtemp->lc;
		}
	}
	 
	if(i>j)
	return i+1;
	else
	return j+1;*/
	if(p->root==NULL)
	return 0;
	else if(p->root->lc==NULL&&p->root->rc==NULL)
	return 1;
	else
	return (1+nodes(p->leftSubtree())+nodes(p->rightSubtree()));
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
int BTree<T>::height(BTree<T> *p)
{
	if(p->root==NULL)
	return 0;
	else if(p->root->lc==NULL&&p->root->rc!=NULL)
	return 1+height(p->rightSubtree());
	else if(p->root->lc!=NULL&&p->root->rc==NULL)
	return 1+height(p->leftSubtree());
	else if(p->root->lc!=NULL&&p->root->rc!=NULL)
	{
		if(height(p->leftSubtree())>height(p->rightSubtree()))
		return 1+height(p->leftSubtree());
		else
		return 1+height(p->rightSubtree());
	}
	else
	return 1;
}
