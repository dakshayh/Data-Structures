#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class array
{
        T *p;
        int size,length;
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
                }
                void insert(T val,int i)
                {
                        if((i>=length)||(i<0))
                        {
                                throw -1;
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
                                throw -1;
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
                                throw -1;
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
                                throw -1;
                        }
                        return this->p[m];
                }
/*int main()
{
        cout<<"\nenter the length of array : ";
        int n;
        cin>>n;
        array <int>obj(n);
 try
        {
        obj.putdata();
        obj.getdata();
        cout<<"\nthe present length is : "<<obj.givelength();
        obj.insert(22,2);
        obj.getdata();
        cout<<"\nthe present length is : "<<obj.givelength();
        obj.Delete(2);
        obj.getdata();
        cout<<"\nthe present length is : "<<obj.givelength();
        obj.insert(70,3);
        obj.getdata();
        cout<<"\nthe present length is : "<<obj.givelength();
        cout<<"\nthe second element is : "<<obj[1];
        obj.erase(2,8);
        obj.getdata();
        cout<<"\nthe present length is : "<<obj.givelength();
        }
        catch(...)
        {
        cout<<"\nOUT OF BOUNDS....";
        }
return 1;

}*/
