#include<iostream>
using namespace std;
template<class T>
class test
{
        T a;
        public:
                void get()
                {
                        cout<<"\nenter value : ";
                        cin>>a;
                }
                void show()
                {
                        cout<<"\nthe value is : ";
                        cout<<a;
                }
};
class sample
{
        int b;
        public:
                friend istream& operator>>(istream &sin,sample &s)
                {
                        sin>>s.b;
                        return sin;
                }
                friend ostream& operator<<(ostream &sout,sample &s)
                {
                        sout<<s.b;
                        return sout;
                }
};
int main()
{
        test <sample>obj;
        obj.get();
        obj.show();
        return 1;
}
