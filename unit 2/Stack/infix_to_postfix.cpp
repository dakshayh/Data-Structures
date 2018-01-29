
#include<iostream>
#include<cstring>
#include "myArrayStack.h"
#include "paranthesis_check.h"
using namespace std;
int main()
{
	bool isOperator(char);int precedence(char);
	char q[100],p[100];Astack <char>stk(5);stk.push('#');
	cout<<"\nenter the expression : ";
	cin>>q;
	if(paran_check(q)==false)
	{
		cout<<"\nthe expression is not valid ....";
		exit(-1);
	}
	char ch;int j=0;
	for(int i=0;i<strlen(q);i++)
	{
		ch=q[i];
		if((ch>=65&&ch<=91)||(ch>=97&&ch<=123))
		{
			p[j++]=q[i];
		}
		if(ch=='(')
		stk.push(ch);
		if(ch==')')
		{
			while(stk.getTop()!='(')
			{
				p[j++]=stk.pop();
			}
			char k=stk.pop();
		}
		if(isOperator(ch))
		{
			while(precedence(stk.getTop())<=precedence(ch))
			{
				p[j++]=stk.pop();
			}
			stk.push(ch);
		}
		
	}
	while(stk.getTop()!='#')
		p[j++]=stk.pop();
		p[j]='\0';
	cout<<"\nthe expression in postfix form is : \n";
	for(j=0;j<strlen(p);j++)
		cout<<p[j];
return 1;
}
bool isOperator(char k)
{
	switch(k)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':return true;
		default:return false;
	}
}
int precedence(char k)
{
	switch(k)
	{
		case '!':return 1;
		case '^':return 2;
		case '*':
		case '/':
		case '%':return 3;
		case '+':
		case '-':return 4;
		default:return 5;
	}
}
