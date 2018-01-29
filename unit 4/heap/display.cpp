#include<iostream>
#include "HeapTree.h"
using namespace std;
int main()
{
	heap<int> obj;
	obj.insert(10);
	obj.insert(1000);
	obj.insert(20000);
	obj.insert(5);
	obj.display();
obj.Delete();
	obj.display();
return 1;
}
