#include<iostream>
#include"polyll.h"
using namespace std;
int main()
{
        poly p1,p2,p3;
        p1.create();
        p2.create();
        p3=p1+p2;
        p1.display();
        p2.display();
        p3.display();
return 0;
}

