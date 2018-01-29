#include<iostream>
#include "queueLinkedList.h"
using namespace std;
int main()
{
	QueueLL <int>obj;
	int ch;
	try
	{
		while(1)
		{
			cout<<"\nenter 1 to insert\nenter 2 to delete\nenter 3 to display queue\npress 4 to exit \n  :";
			cin>>ch;
			switch(ch)
			{
				case 1:cout<<"\nenter the value : ";int k;cin>>k;obj.insert(k);break;
				case 2:cout<<"\nthe deleted value is :"<<obj.Delete();break;
				case 3:obj.display();break;
				case 4:throw "\nprogram exited....";
				default:"\nenter proper option : ";
			}
		}
	}
	catch(const char *p)
	{
		cout<<"\nexception caught : "<<p;
	}
}

