/*
输出
A::A() called.
B::B() called.
May you succeed!B::~B() called.
先调用基类 A 的构造函数：A::A() called.
再调用派生类 B 的构造函数：B::B() called
输出：May you succeed!
然后执行 delete a;，因为 a 是指向 B 对象的基类指针，而 A 的析构函数是 虚函数，所以会触发 多态析构，即：
先调用派生类 B 的析构函数：
执行 delete[] buf;（释放动态分配的内存）
输出：B::~B() called.
然后调用基类 A 的析构函数：
输出：A::~A() called.
*/
#include <iostream>
using namespace std;
class A
{public:
   A(){cout<<"A::A() called.\n";}
   virtual ~A(){cout<<"A::~A() called.\n";}
}; 
class B:public A
{ public:
     B(int i)
	 {  cout<<"B::B() called.\n";
        buf=new char[i];
	 }
     virtual ~B()
	 {  delete []buf;
        cout<<"B::~B() called.\n";
	 }
private:
   char *buf;
};
void fun(A *a)
{  cout<<"May you succeed!";
   delete a;
}
int main()
{
	A *a=new B(15);
    fun(a);
    return 0;
}