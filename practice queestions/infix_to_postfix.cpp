#include<iostream>
#include<cstring>
#include "SL.h"
using namespace std;
int main()
{
	char p[80];StackLL<char> ALPSTK;StackLL<char> OPSTK;
	ALPSTK.push('#');OPSTK.push('#');char ch;
	cin>>p;bool isOperator(char);int precedence(char);
	for(int i=strlen(p)-1;i>=0;i--)
	{
		ch=p[i];
		if((ch>=65&&ch<=91)||(ch>=97&&ch<=123))
		ALPSTK.push(ch);
		else if(ch==')')
 		OPSTK.push(ch);
		else if(ch=='(')
		{
			while(OPSTK.getTop()!=')')
			ALPSTK.push(OPSTK.pop());
			ch=OPSTK.pop();
		}
		else if(isOperator(ch))
		{
			while(precedence(OPSTK.getTop())<precedence(ch))
			ALPSTK.push(OPSTK.pop());
			OPSTK.push(ch);
		}
	}
	while(OPSTK.getTop()!='#')
	ALPSTK.push(OPSTK.pop());
	cout<<"\n";
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

