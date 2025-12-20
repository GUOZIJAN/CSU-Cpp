/*
输出
This Number is:  13
This Number is:  14
This Number is:  13
This Number is:  10
*/
#include<iostream>
using namespace std;
class Number{
	int n;
public:
	Number(int x):n(x){}
	Number& operator++(){ ++n; 	return *this;	}
	Number& operator++(int){	n++;		return *this;}
	friend Number &operator--(Number &o);
	friend Number &operator--(Number &o,int); 
	void display(){cout<<"This Number is:  "<<n<<endl;}
};
Number &operator--(Number &o){--o.n;	return o;	}
Number &operator--(Number &o,int){o.n--;	return o;	}
int main(){
	Number N1(10);
	++ ++ ++N1;
	N1.display();
	N1++;
	N1.display();
	--N1;
	N1.display();
	N1-- -- --;
	N1.display();
    return 0;
}	