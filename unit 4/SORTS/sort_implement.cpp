#include<iostream>
#include "sorts.h"
using namespace std;
int main()
{
        cout<<"\nenter the number of numbers : ";
        int n;
        cin>>n;
        try
        {
        arr <int>obj(n);
        cout<<"\nenter the numbers : ";
        obj.putdata();
        while(1)
        {
                int ch;
                cout<<"\npress 1 for quicksort\npress 2 for merge sort\npress 3 for insertion sort\npress 4 to display\npress 5 to exit :";
                cin>>ch;
                switch(ch)
                {
                case 1:obj.quick_sort(0,n-1);break;
                case 2:obj.merge_sort(0,2,n-1);break;
                case 3:obj.insertion_sort(n);break;
                case 4:obj.getdata();break;
                case 5:throw "program exited ..";
                }
        }
        }
        catch(const char *P)
        {
        cout<<"\nexception caught : "<<P;
        }
}


