/*
输出
Base::g1()...1
Base::g4()...2
------------------
Deri::g1()...2
Base::g2()...3
Base::g3()...4
Base::g4()...5
------------------
Deri::g1()...6
Base::g2()...7
Base::g3()...8
Base::g4()...9
------------------
Deri::g1()...10
Base::g2()...11
Base::g3()...12
Base::g4()...13
对象切片会丢失多态行为
非虚函数调用取决于静态类型
虚函数调用取决于实际对象类型
*/
#include <iostream>
using namespace std;
class Base{
protected:
	int n;
public:
	Base (int m){	n=m++; 		}
	virtual void g1(){cout<<"Base::g1()..."<<n<<endl; g4();}
	virtual	void g2(){cout<<"Base::g2()..."<<++n<<endl;g3();}
			void g3(){cout<<"Base::g3()..."<<++n<<endl; g4();}
			void g4(){cout<<"Base::g4()..."<<++n<<endl;}

};
class Derive:public Base{
	int j;
public:
	Derive(int n1,int n2):Base(n1){  j=n2;	}
	void g1(){cout<<"Deri::g1()..."<<++n<<endl;g2();}
	void g3(){cout<<"Deri::g2()..."<<++n<<endl;g4();}
};
int main(){
	Derive Dobj(1,0);
	Base Bobj=Dobj;
	Bobj.g1();
	cout<<"------------------"<<endl;
	Base *bp=&Dobj;
	bp->g1();
	cout<<"------------------"<<endl;
	Base &bobj2=Dobj;
	bobj2.g1();
	cout<<"------------------"<<endl;
	Dobj.g1();
    return 0;
}