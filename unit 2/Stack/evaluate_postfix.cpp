#include<iostream>
#include<cstring>
#include<cmath>
#include "myArrayStack.h"
using namespace std;
int main()
{
	cout<<"\nenter the postfix expression : ";
	char p[80];bool isOperator(char);
	float Operate(float,float,char);
	cin>>p;int i;Astack <char>stk(5);
	char ch;int j=0;float r;
	for(int i=0;i<strlen(p);i++)
	{
		ch=p[i];
		if((ch>=65&&ch<=91)||(ch>=97&&ch<=123))
		{
			stk.push(ch);
		}
		if(isOperator(ch))
		{
			float a,b;
			if(j==0)
			{
			cout<<"\nenter the value of "<<stk.pop()<<" : ";
			cin>>a;
			cout<<"\nenter the value of "<<stk.pop()<<" : ";
			cin>>b;
			r=Operate(b,a,ch);j++;
			}
			else
			{
				cout<<"\nenter the value of "<<stk.pop()<<" : ";
				cin>>b;
				r=Operate(r,b,ch);
			}
		}
		
	}
	cout<<"\nthe result is : "<<r;
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
float Operate(float p,float q,char k)
{
		switch(k)
		{
		case '+':return p+q;
		case '-':return p-q;
		case '*':return p*q;
		case '/':return p/q;
		case '%':return int(p)%int(q);
		case '^':return pow(p,q);
		default:return -(1.0);
		}
}
