#include<iostream>

#include<stdlib.h>

using namespace std;

class hash

{

 int *a,n;

 public:

  hash(int size)

  {

   n=size;

   a=new int[n];

  }

  void display();

  void moddiv(int &ele);

  void openadd(int &ele,int &k);

  void fill(void);

  void del(int &ele);

  int search(int &ele);

};

void hash::fill(void)

{

 for(int i=0;i<n;i++)

  a[i]=0;

}

void hash::display()

{

 for(int i=0;i<n;i++)

  cout<<a[i]<<"\t";

}

void hash::moddiv(int &ele)

{

 int k;

 k=ele%n;

 if(a[k]==0)

  a[k]=ele;

 else

  openadd(ele,k);

}

void hash::openadd(int &ele,int &k)

{

 for(int i=k+1;i<n;i++)

 {

  if(a[i]==0)

  {

   a[i]=ele;

   return;

  }

 }

 for(int i=0;i<k;i++)

 {

  if(a[i]==0)

  {

   a[i]=ele;

   return;

  }

 }

 throw"No space to insert element...";

 }

int hash::search(int &ele)

{

 int k=ele%n;

 if(a[k]==ele)

  return k;

 else

 {

  for(int i=k+1;i<n;i++)

  {

   if(a[i]==ele)

    return i;

  }

  for(int i=0;i<k;i++)

  {

   if(a[i]==ele)

    return i;

  }

 }

 return -1;

}

void hash::del(int &ele)

{

 int k=search(ele);

 if(k==-1)

  cout<<"Element doesnt exists...";

 else

 {

  int t=a[k];

  a[k]=0;

  cout<<"Element "<<t<<" is deleted...";

 }

}

int name()

{

 int ch;

 cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";

 cout<<"Enter your option: ";

 cin>>ch;

 return ch;

}

int main()

{

 int ch,ele,k;

 try

 {

  hash h(5);
  h.fill();

  while(1)

  {

   ch=name();

   switch(ch)

   {

    case 1:{

            cout<<"Enter element to insert: ";

            cin>>ele;

            h.moddiv(ele);

            break;

           }

    case 2:{

            cout<<"Enter element to search: ";

            cin>>ele;

            k=h.search(ele);

            if(k==-1)

             cout<<"Element doesnt exists...";

            else

             cout<<"Element exists...";

            break;

           }

    case 3:{

            cout<<"Enter element to delete: ";

            cin>>ele;

            h.del(ele);

            break;

           }

    case 4:h.display();

           break;

    case 5:cout<<"Exit...";

           exit(0);

   }

  }

 }

 catch(const char *p)

 {

  cout<<"\nException caught...\n"<<p<<"\n";

 }

 return 0;

}
