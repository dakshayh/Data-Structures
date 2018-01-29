#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class array
{
        T *p;
        int size,length;void sizeDouble();
        public:
                array()
                {
                        size=0;length=1;
                        p=NULL;
                }
                array(int i)
                {
                        length=1;
                        size=i;
                        p=new T[size];
                        if(p==NULL)
                        throw "\nmemory not allocated ....";
                }
                void insert(T val,int i)
                {	
                		if(i<0)
                		throw "\nwrong input ...";
                        if((i>=length))
                        {
                                sizeDouble();
                        }
                        for(int k=length-1;k>=i;k--)
                        {
                                p[k+1]=p[k];
                        }
                        p[i]=val;
                        if(length<5)
                        length++;
                }
 void Delete(int i)
                {
                        if((i>=length)||(i<0))
                        {
                                throw "\ninvalid input...";
                        }
                        for(int k=i;k<length-1;k++)
                        {
                                p[k]=p[k+1];
                        }
                        length--;
                }
                void erase(int m,int n)
                {
                        if((m>=n)||(m<0)||(n>=length))
                        {
                                throw "\ninvalid input....";
                        }
                        for(int k=m;k<n;k++)
                        {
                                p[k]=p[k+(n-m)];
                        }
                        length-=(n-m);
                }
                void search(T srch)
                {
                        int flag=1;
                        for(int k=0;k<length;k++)
                        {
                                if(p[k]==srch)
                                {
                                        cout<<"\nsearch element found at "<<k<<" index.";
                                        flag=0;
                                        break;
                                }
                        }
                        if(flag==1)
                        {
                                cout<<"\nsearch element not found ....";
                        }
                }
   				int givelength()
                {
                        return length;
                }
                void putdata()
                {
                        T *a;
                        a=p;
                        cout<<"\nenter the data : \n";
                        for(int k=0;k<size;k++)
                        {
                                cin>>*(a++);
                        }
                                length=size;
                }
                void getdata()
                {
                        T *a;
                        a=p;
                        cout<<"\nthe vector is : ";
                        for(int k=0;k<length;k++)
                        {
                                cout<<" "<<*(a++);
                        }
                }
                T operator[](int);

};
template<class T>
T array<T>::operator[](int m)
                {
                        if((m>=size)||(m<0))
                        {
                                throw "\ninvalid input...";
                        }
                        return this->p[m];
                }
template<class T>
void array<T>::sizeDouble()
{
	T *temp=new T[2*size];
	copy(p,p+size,temp);
	delete []p;
	size*=2;
	p=temp;
}

