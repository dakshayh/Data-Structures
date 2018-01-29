#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	BST <int>obj;
	int i,n,k;
	cout<<"\nenter the number of numbers : ";
	cin>>n;
	for(i=0;i<n;i++)
	{cin>>k;
	obj.insert(k);
	}
	obj.inorder();
	obj.search(4);
	obj.Delete(2);cout<<endl;
	obj.inorder();
return 1;
}
