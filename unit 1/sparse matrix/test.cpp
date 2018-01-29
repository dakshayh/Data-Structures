#include<iostream>
#include "mySparse.h"
using namespace std;
int main()
{
	SMatrix obj(2,2,2),obj2,obj3;
	obj.read();
	obj2=obj.Ftranspose();
	obj3=obj.multiply(obj2);
	obj3.show();
}
