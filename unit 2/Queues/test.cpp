#include<iostream>
#include "CircleQueue.h"
using namespace std;
int main()
{
	cQueue <int>obj;
	obj.insert(5);
	obj.display();
	obj.insert(10);
	obj.insert(15);
	obj.insert(20);
	obj.display();
	obj.Delete();
	obj.Delete();
	obj.insert(25);
	obj.insert(30);
	obj.display();
	obj.insert(35);
	obj.display();
	cout<<endl<<obj.isFull();
}
