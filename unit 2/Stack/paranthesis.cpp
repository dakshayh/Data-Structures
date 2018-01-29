#include<iostream>
#include<cstring>
#include "myArrayStack.h"
using namespace std;
int main()
{
        Astack <char>stk(5);
        char exp[100];int flag=1;
        cout<<"\nenter the expression : ";
        cin>>exp;
        for(int i=0;i<strlen(exp);i++)
        {
        if(exp[i]=='(')
        stk.push(exp[i]);
        if(exp[i]==')')
        {
                if(stk.isEmpty())
                {
                flag=0;break;
                }
                char ch=stk.pop();
        }
        }
        if((stk.isEmpty()&&(flag==1)))
        cout<<"\nthe expression is valid ...";
        if((!stk.isEmpty())||(flag==0))
        cout<<"\nthe expression is not valid ...";
return 1;
}
