#include<iostream>
#include"mySLL.h"
using namespace std;
struct term
{
        int coef,exp;
        term setterm(int c,int e)
        {
                coef=c;exp=e;
                return *this;
        }
};
class poly
{
        SLL<term>ll;
        public:
                void create()
                {
                        int c,e;
                        cout<<"\nEnter coefficient and exponent.Enter -1 for exponent for ending\n";
                        while(1)
                        {
                                cin>>c>>e;
                                if(e==-1)
                                break;
                                term t;
                                ll.LInsert(t=t.setterm(c,e));
                        }
                }
                void display()
                {
                        cout<<"\n";
                        SLL<term>::chainiterator ai=ll.begin();
                        for(;ai!=0;++ai)
                        {
                                cout<<ai->coef<<"x^"<<ai->exp<<" ";
                        }
                        cout<<"\n";
                }
 poly operator+(poly &y)
                {
                        SLL<term>::chainiterator a1=ll.begin(),a2=y.ll.begin();
                        poly c;term t;
                        while(a1!=0 && a2!=0)
                        {
                                if(a1->exp==a2->exp)
                                {
                                        int x=a1->coef+a2->coef;
                                        t=t.setterm(x,a1->exp);
                                        c.ll.LInsert(t);
                                        ++a1;++a2;
                                }
                                else if(a1->exp>a2->exp)
                                {
                                        t=t.setterm(a1->coef,a1->exp);
                                        c.ll.LInsert(t);
                                        ++a1;
                                }
                                else
                                {
                                        t=t.setterm(a2->coef,a2->exp);
                                        c.ll.LInsert(t);
                                        ++a2;
                                }
                        }
                        for(;a1!=0;++a1)
                        {
                                c.ll.LInsert(t=t.setterm(a1->coef,a1->exp));
                        }
                        for(;a2!=0;++a2)
                        {
                                c.ll.LInsert(t=t.setterm(a2->coef,a2->exp));
                        }
                        return c;
                }
};



