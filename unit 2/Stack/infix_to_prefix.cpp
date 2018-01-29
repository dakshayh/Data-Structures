#include<iostream>
#include<cstring>
#include "myArrayStack.h"
using namespace std;
int main()
{
	cout<<"\nenter the expression : ";
	char q[80];Astack <char>ALPSTK(20);Astack <char>OPSTK(20);
	cin>>q;bool isOperator(char k);char ch;OPSTK.push('#');
	ALPSTK.push('#');
	int precedence(char k);
	for(int i=strlen(q);i>=0;i--)
	{
		ch=q[i];
		if((ch>=65&&ch<=91)||(ch>=97&&ch<=123))
		{
			ALPSTK.push(ch);
		}
		if(ch==')')
		{
			OPSTK.push(ch);
		}
		if(ch=='(')
		{
			while(OPSTK.getTop()!=')')
			ALPSTK.push(OPSTK.pop());
			char k=OPSTK.pop();
		}
		if(isOperator(ch))
		{
			while(precedence(OPSTK.getTop())<precedence(ch))
			ALPSTK.push(OPSTK.pop());
			OPSTK.push(ch);
		}
	}
	cout<<"\nthe expression is : ";
	while(OPSTK.getTop()!='#')
	ALPSTK.push(OPSTK.pop());
	while(ALPSTK.getTop()!='#')
	cout<<ALPSTK.pop();
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

