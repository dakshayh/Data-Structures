#include<iostream>
#include<cmath>
#include<cstring>
#include "myArrayStack.h"
using namespace std;
int main()
{
	cout<<"\nenter the  expression in prefix : ";
	char p[80];Astack <char>stk(10);
	cin>>p;char ch;float Operate(float,float,char);
	bool isOperator(char);int j=0;float r;
	for(int i=strlen(p)-1;i>=0;i--)
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
				r=Operate(a,b,ch);j++;
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
		default:return -1.0;
	}
}
