#include<iostream>
#include "sorts.h"
using namespace std;
int main()
{
	arr <int>obj(7);
	obj.putdata();
	obj.merge_sort_r(0,6);
	obj.getdata();
}
