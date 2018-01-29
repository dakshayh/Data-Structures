#include<iostream>
#include "myArrayStack.h"
#include "myArray.h"
using namespace std;
int main()
{
	cout<<"\nenter the maximum size : ";
	int n;
	cin>>n;
	Astack <array>obj(n);
	try
	{
		while(1)
		{
			int ch;
			cout<<"\npress 1 to push data\npress 2 to pop data\npress 3 to get the top element\npress 4 to display the stack\npress 5 to exit \n: ";
			cin>>ch;
			switch(ch)
			{
			case 1:{
				int k;
				cout<<"\nenter the value to be pushed : ";
				cin>>k;
				obj.push(k);
				}break;
			case 2:{
				int k=obj.pop();
				cout<<"\nthe removed element is : "<<k;
				break;
				}
			case 3:{
				int k=obj.pop();
				cout<<"\nthe top most element is : "<<k;
				break;
				}
			case 4:
				{
					cout<<"\nthe stack is : ";
					obj.display();
					break;
				}
			case 5:{
			throw "program exited...";
				break;
				}
			default:cout<<"\nwrong choice ...enter again : ";
			}
		}
	}	
	catch(const char *p)
	{
		cout<<"\nexception caught : "<<p;
	}
return 1;
}
