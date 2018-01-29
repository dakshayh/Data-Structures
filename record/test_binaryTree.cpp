#include<iostream>
#include "BinaryTreeM.h"
using namespace std;
int main()
{
	BTree<char> a;//using here a as null address
	BTree<char> X('D',a,a);
	BTree<char> Y('E',a,a);
	BTree<char> Z('B',X,Y);
	BTree<char> P('F',a,a);
	BTree<char> Q('C',P,a);
	BTree<char> R('A',Z,Q);
	BTree<char> S('I',R,a);
	S.Traversal();
	cout<<"\nNODES:"<<S.nodes();
	cout<<"\nHEIGHT:"<<S.height();
	cout<<"\ninorder_nonrecursive:";S.inorder_nr();
	cout<<"\npreorder_nonrecursive:";S.preorder_nr();
return 1;
}
