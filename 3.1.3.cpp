/*
输出
A constructor...
A constructor...
B constructor...
(1,2)(1,1)(3,4)
(2,5)(1,1)(8,11)
destructor B...
destructor A...
destructor A...
A父类构造,Aobj构造,B构造,
x,y加上1,3; i,j加上5,7
析构逆向
*/
#include<iostream>
using namespace std;
class A{
public:
	A(int a,int b):x(a),y(b){ cout<<"A constructor..."<<endl;	}
	void Add(int a,int b){ x+=a;y+=b;}
	void display(){ cout<<"("<<x<<","<<y<<")";}
	~A(){cout<<"destructor A..."<<endl;}
private:
	int x,y;
};
class B:private A{
private:
	int i,j;
	A Aobj;
public:
	B(int a,int b,int c,int d):A(a,b),i(c),j(d)	,Aobj(1,1){ cout<<"B constructor..."<<endl;}
	void Add(int x1,int y1,int x2,int y2)
	{
		A::Add(x1,y1);
		i+=x2; j+=y2;
	}
	void display(){
		A::display();
		Aobj.display();
		cout<<"("<<i<<","<<j<<")"<<endl;
	}
	~B(){cout<<"destructor B..."<<endl;}    
};
int main()
{
	B b(1,2,3,4);
	b.display();
	b.Add(1,3,5,7);
	b.display();
    return 0;
}