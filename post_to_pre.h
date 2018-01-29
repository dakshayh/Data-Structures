#include<iostream>
#include<cstring>
#include"myArrayStack.h"
using namespace std;
string post2pre(char *post)
{
        Astack<string>pre(30);
        string A,B,temp,s;
        for(int i=0;post[i]!='\0';i++)
        {
                if(isalpha(post[i]))
                {
                    temp=post[i];
                    pre.push(temp);
                }
                else
                {
                    A=pre.pop();
                    B=pre.pop();
                    temp=post[i];
                    temp=temp+B+A;
                    pre.push(temp);
                }
        }
        return pre.getTop();
}
