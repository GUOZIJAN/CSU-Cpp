/*
输出
A constructor...9
A constructor...9
B constructor...9
C constructor...
D constructor...
11      11      11
destructor D....
destructor B...
destructor A...
destructor A...
B C D都为虚继承,只构造一个虚基类A,B中实例化一个A,故构造函数顺序为AABCD
A::f()  对共享虚基类 A 操作，x 由 9→10
Aobj.f() 对成员对象 Aobj 操作，Aobj.x 由 9→10
++y 让 y 由 9→10
输出时又都调用了一遍,故输出11 11 11
析构顺序与构造严格相反：
D → C → B → Aobj → 共享 A
*/
#include<iostream>
using namespace std;
class A{
public:
	A(int a):x(a){ cout<<"A constructor..."<<x<<endl;	}
	int f(){return ++x;}
	~A(){cout<<"destructor A..."<<endl;}
private:
	int x;
};
class B:public virtual A{
private:
	int y;
	A Aobj;
public:
	B(int a,int b,int c):A(a),y(c),Aobj(c){ cout<<"B constructor..."<<y<<endl;}
	int f(){
		A::f();
		Aobj.f();
		return ++y;
	}
	void display(){	cout<<A::f()<<"\t"<<Aobj.f()<<"\t"<<f()<<endl;	}
	~B(){cout<<"destructor B..."<<endl;}    
};
class C:public B{
public:
	C(int a,int b,int c):B(a,b,c),A(0){ cout<<"C constructor..."<<endl;}
};
class D:public C,public virtual A{
public:
	D(int a,int b,int c):C(a,b,c),A(c){ cout<<"D constructor..."<<endl;}
	~D(){cout<<"destructor D...."<<endl;}
};
int main()
{
	D d(7,8,9);
	d.f();
	d.display();
return 0;
}