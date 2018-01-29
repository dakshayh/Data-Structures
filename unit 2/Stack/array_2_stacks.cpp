#include<iostream>
#include<stdlib.h>
using namespace std;
class Array2Stacks
{
        int *p;
        int ms;
        int top1,top2;
        void sizeDouble();
        public:
        Array2Stacks()
        {
                p=NULL;
                ms=0;
                top1=-1;top2=ms;
        }
        Array2Stacks(int q)
        {
                ms=q;
                top1=-1;
                top2=ms;
                p=new int[top2];
        }
        void push1(int);
        void push2(int);
        int pop1();
        int pop2();
        bool isOverflow();
        void display();
};
void Array2Stacks::push1(int q)
{
        if(isOverflow())
        {
                cout<<"\nsize overflow ,, doubling the size of stacks ...";
                sizeDouble();
        }
        p[++top1]=q;
}
void Array2Stacks::push2(int q)
{
        if(isOverflow())
        {
                cout<<"\nsize overflow ,, doubling the size of stacks ...";
                sizeDouble();
        }
        p[--top2]=q;
}
int Array2Stacks::pop1()
{
        if(top1==-1)
        {
                cout<<"\nstack empty...";
                exit(-1);
        }
        return p[top1--];
}
int Array2Stacks::pop2()
{
        if(top2==ms)
        {
                cout<<"\nstack empty...";
                exit(-1);
        }
        return p[top2++];
}
bool Array2Stacks::isOverflow()
{
        if(top1==top2-1)
        return true;
        else
        return false;
}
void Array2Stacks::sizeDouble()
{
        int *temp=new int[2*(ms)];
        for(int i=0;i<=top1;i++)
        temp[i]=p[i];
        for(int i=(2*ms)-1;i>=ms+top2;i--)
        temp[i]=p[i-ms];
        delete[]p;
        p=temp;
        top2=ms+top2;
        ms=ms*2;
}
void Array2Stacks::display()
{
        cout<<"\nthe first stack is : \n";
        for(int i=top1;i>=0;i--)
        cout<<p[i]<<endl;
        cout<<"\nthe second stack is : \n";
        for(int i=top2;i<ms;i++)
        cout<<p[i]<<endl;
}
int main()
{
        Array2Stacks stk(5);
        try
        {
        while(1)
        {
        int ch;
        cout<<"\npress 1 to push into 1st stack\npress 2 to push into 2nd stack\npress 3 to pop from 1st stack\npress 4 to pop from 2nd stack\npress 5 to display\npress 6 to exit\n: ";
        cin>>ch;int k;
        switch(ch)
        {
        case 1:cout<<"\nenter the value : ";cin>>k;stk.push1(k);break;
        case 2:cout<<"\nenter the value : ";cin>>k;stk.push2(k);break;
        case 3:cout<<"\nthe popped value is : "<<stk.pop1();break;
        case 4:cout<<"\nthe popped value is : "<<stk.pop2();break;
        case 5:stk.display();break;
        case 6:throw -1;
        default:cout<<"\nenter proper option : ";
        }
        }
        }
        catch(...)
        {
        cout<<"\nprogram exited ...";
        }
return 1;
}


