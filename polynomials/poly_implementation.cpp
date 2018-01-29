#include<iostream>
#include "myPoly.h"
using namespace std;
int main()
{
        int m,n;
        poly p1,p2,p3;
        try
        {
                cout<<"\nenter maximum size and lenght of polynomial 1 : ";
                cin>>m>>n;
                if(n>m)
                throw -2;
                p1=poly(m,n);
                cout<<"\nenter the maximum size and length of polynomial 2 : ";
                cin>>m>>n;
                if(n>m)
                throw -2;
                p2=poly(m,n);
                int ch;
                while(1)
                {
                cout<<"\npress 1 to putdata\npress 2 to getdata\npress 3 to add\npress 4 to multiply\npress 5 to exit \n: ";
                cin>>ch;
                switch(ch)
                {
 case 1:{cout<<"\nenter the data in polynomial 1 :\n";
                        p1.putdata();
                        cout<<"\nenter the data in polynomial 2 :\n";
                        p2.putdata();
                        break;
                        }
                case 2:{cout<<"\npolynomial 1 : \n";
                        p1.getdata();
                        cout<<"\npolynomial 2 : \n";
                        p2.getdata();
                        break;
                        }
                case 3:{poly p3;
                        p3=p1+p2;
                        cout<<"\naddition is : \n";
                        p3.getdata();
                        break;
                        }
                case 4: {poly p3;
                        p3=p1*p2;
                        cout<<"\nmultiplication is : \n";
                        p3.getdata();
                        break;
                        }
                case 5:throw -1;
                default:cout<<"\nenter appropriate option ...";
                }
                }
        }
 catch(int k)
        {
        if(k==-1)
        cout<<"\nprogram exited ...";
        if(k==-2)
        cout<<"\nwrong input...";
        }
return 1;
}
                         
