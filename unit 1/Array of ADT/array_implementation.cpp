#include<iostream>
#include "myArray.h"
using namespace std;
int main()
{
	cout<<"\nenter the size of the array : ";
	int n,ch;
	cin>>n;
	try
	{
		array <int>obj(n);
		while(1)
		{
			cout<<"\n\npress 0 to putdata\npress 1 for insertion\npress 2 deletion\npress 3 for erasing\npress 4 to display\npress 5 to givelength \npress 6 to exit\nEnter your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 0:{obj.putdata();
					break;
				}
				case 1:{int val,i;cout<<"\nenter the value to be input : ";
						cin>>val;
						cout<<"\nenter the index : ";
						cin>>i;
						obj.insert(val,i);
					break;
				}
				case 2:{int i;cout<<"\nenter the index of the to be deleted item : ";
						cin>>i;
						obj.Delete(i);
					break;
				}
				case 3:{int m,n;cout<<"\nenter the range within which values are to be deleted : ";
						cin>>m>>n;
						obj.erase(m,n);
					break;
				}
				case 4:{obj.getdata();
					break;
				}
				case 5:{
					cout<<"\nthe length of the array is : "<<obj.givelength();
					break;
				}
				case 6:{
					throw float(1.0);
					break;
				}
				default:cout<<"\nenter an appropriate value ...";
			}
		}
	}
	catch(float a)
	{
		cout<<"\nprogram exited .....";
	}
	catch(char ch)
	{
		cout<<"\ninsufficient space ....";	
	}
	catch(...)
	{
		cout<<"\nOUT OF BOUNDS ...";
	}
return 1;
}
