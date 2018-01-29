#include<iostream>
using namespace std;
class term
{
        int coef,exp;
        friend class poly;
};
class poly
{
        term *t;
        int ms,nt;
        void attach(int,int);
        public:
                poly()
                {
                        ms=nt=0;
                        t=NULL;
                }
                poly(int m,int n)
                {

                        ms=m;nt=n;
                        t=new term[ms];
                }
                void putdata();
                void getdata();
                poly operator+(poly);
                poly operator*(poly);
};
void poly::putdata()
                {
                        int i;
                        for(i=0;i<nt;i++)
                        {
                                cout<<"\nenter the coefficient and exponent of the "<<i<<" term :\n";
                                cin>>t[i].coef>>t[i].exp;
                        }
                }
void poly::getdata()
                {
                        int i;
                        cout<<"\nthe polynomial is : \n";
                        for(i=0;i<nt;i++)
                        {
                                if(t[i].coef>=0)
                                cout<<" "<<"+"<<t[i].coef<<"X"<<"^"<<t[i].exp;
                                else
                                cout<<" "<<t[i].coef<<"X"<<"^"<<t[i].exp;

                        }
                }
poly poly::operator+(poly s)
{
        poly temp;
        temp=poly(ms+s.ms,0);
        int i,j;
        i=j=0;
        while(i<nt&&j<s.nt)
        {
                if(t[i].exp==s.t[j].exp)
                {
                        int k=t[i].coef+s.t[j].coef;
                        if(k)
                        temp.attach(k,t[i].exp);i++;j++;
                }
                else if(t[i].exp>s.t[j].exp)
                {
                        temp.attach(t[i].coef,t[i].exp);
                        i++;
                }
                else
                {
                        temp.attach(s.t[j].coef,s.t[j].exp);
                        j++;
                }
        }
 for(;i<nt;i++)
        {
                temp.attach(t[i].coef,t[i].exp);
        }
        for(;j<s.nt;j++)
        {
                temp.attach(s.t[j].coef,s.t[j].exp);
        }
return temp;
}
void poly::attach(int p,int q)
{
        t[nt].coef=p;
        t[nt].exp=q;
        nt++;
}
poly poly::operator*(poly s)
{
        poly temp;
        temp=poly(ms*s.ms,0);
        int i,j;
        for(i=0;i<nt;i++)
        {
                for(j=0;j<s.nt;j++)
                {
                        temp.attach(t[i].coef*s.t[j].coef,t[j].exp+s.t[j].exp);
                }
        }
        poly temp1(ms*s.ms,0);
        for(i=0;i<nt+s.nt;i++)
        {
                for(j=i+1;j<nt+s.nt;j++)
                {
                        if(temp.t[j].exp==0)
                        continue;
                        if(temp.t[i].exp==temp.t[j].exp)
                        {
                                temp.t[i].coef+=temp.t[j].coef;
                                temp.t[j].exp=0;
                        }
                }
        }
        for(i=0;i<nt+s.nt;i++)
        {
                if(temp.t[i].exp==0)
                continue;
                else
                temp1.attach(temp.t[i].coef,temp.t[i].exp);
         }
return temp1;
}

