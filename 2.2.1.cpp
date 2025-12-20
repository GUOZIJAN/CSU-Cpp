//期望是a=4,b=8,a=4,b=8,结果是a=0,b=0,a=4,b=8
//A m,n(4,8);先是用A()构造了m,又用A(4,8)构造了n
#include <iostream>
using namespace std;
class A {
 public:
A();
A(int i,int j);
void print( );
 private:
int a,b;
};
A::A( )
 {
   a=b=0;
   cout<<"Default constructor called.\n";
 }
A::A(int i,int j)
{
 a=i;
b=j;
cout<<"Constructor called.\n";
}
void A::print()
{
 cout<<"a="<<a<<",b="<<b<<endl;
}
int main()
{
A m,n(4,8);
m.print();
n.print();
return 0;
}