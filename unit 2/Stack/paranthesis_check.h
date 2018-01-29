#include<iostream>
using namespace std;
bool paran_check(char *exp)
{
	    Astack <char>stk(5);int flag=1;
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
       	return true;
        if((!stk.isEmpty())||(flag==0))
        return false;
}
