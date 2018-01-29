#include<iostream>
#include "myPoly.h"
using namespace std;
int main()
{
	poly p1(3,2),p2(3,2),p3;
	p1.putdata();
	p2.putdata();
	p3=p1+p2;
	p3.getdata();
return 1;
}
