#include<iostream>
#include "sorts.h"
using namespace std;
int main()
{
	arr <int>obj(5);
	obj.putdata();
	obj.quick_sort(0,4);
	obj.getdata();
}
