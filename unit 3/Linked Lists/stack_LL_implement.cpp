#include<iostream>
#include "stackLinkedList.h"
using namespace std;
int main()
{
	StackLL <int>obj;
	try
	{
		int ch;
		while(1)
		{
			cout<<"\nenter 1 to push\nenter 2 to pop\nenter 3 to display stack\nenter 4 to get topelement\npress 5 to exit \n  :";
			cin>>ch;
			switch(ch)
			{
				case 1:cout<<"\nenter the value : ";int k;cin>>k;obj.push(k);break;
				case 2:cout<<"\nthe popped value is :"<<obj.pop();break;
				case 3:obj.display();break;
				case 4:cout<<"\ntop element is : "<<obj.getTop();break;
				case 5:throw "\nprogram exited....";
				default:"\nenter proper option : ";
			}
		}
	}
	catch(const char *p)
	{
		cout<<"\nexception caught : "<<p;
	}
return 1;
}

