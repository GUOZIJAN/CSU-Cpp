#include <iostream>
using namespace std;
class A
{public:
        A(int i=0){m=i;}
        void show(){cout<<m;}
        ~A(){}
        int m;
};
int main()
{   A a(5);
a.m+=10;
a.show();
return 0;
}