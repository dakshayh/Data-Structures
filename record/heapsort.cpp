#include<iostream>
#include "HeapTree.h"
using namespace std;
int main()
{
        cout<<"\nenter the number of numbers : ";
        int n;
        cin>>n;
        heap <int>obj(n);
        obj.getdata();
        obj.heapsort();
        obj.display();
}



