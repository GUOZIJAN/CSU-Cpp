/*
输出
class Base1!
class Base2!
class Level2!
class Base2!
class Level1!
class TopLevel!
先构造虚基类 Level2
1.1 Level2 内部先构造自己的虚基类 Base1 → 输出
class Base1!
1.2 再构造 Level2 的普通基类 Base2 → 输出
class Base2!
1.3 执行 Level2 构造函数体 → 输出
class Level2!
再构造普通基类 Level1（按继承列表顺序）
2.1 Level1 内部先构造自己的虚基类 Base1——但 Base1 已构造完，跳过；
2.2 构造 Level1 的普通基类 Base2 → 输出
class Base2!
2.3 执行 Level1 构造函数体 → 输出
class Level1!
最后构造 TopLevel 自身
执行 TopLevel 构造函数体 → 输出
class TopLevel!
*/
#include <iostream>
using namespace std;
class Base1
{
	public:
	Base1()
	{
		cout<<"class Base1!"<<endl;
	}
};
class Base2
{
	public:
	Base2()
	{
		cout<<"class Base2!"<<endl;
	}
};
class Level1:public Base2,virtual public Base1
{
public:
	Level1()
	{
		cout<<"class Level1!"<<endl;
	}
};
class Level2: public Base2,virtual public Base1
{
public:
	Level2()
	{
		cout<<"class Level2!"<<endl;
	}
};
class TopLevel:public Level1,virtual public Level2
{
public:
	TopLevel()
	{
		cout<<"class TopLevel!"<<endl;
	}
};
int main()
{
	TopLevel obj;
	return 0;
}