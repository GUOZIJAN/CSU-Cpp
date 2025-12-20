#include <iostream>
using namespace std;
class intArray
{
    public:
        intArray(int size);//构造函数
        intArray(const intArray &x);//复制构造函数
        ~intArray();//析构函数
        bool Set(int i, int elem);//设置第i个数组元素的值，设置成功返回true，失败返回false
        bool Get(int i, int &elem); //获取第i个数组元素的值，获取成功返回true，失败返回false
        int Length( ) const;//获取数组的长度
        void ReSize ( int size ); //重置数组
        void Print();//输出数组
    private:
        int *element;            //指向动态数组的指针
        int arraysize;            //数组的当前长度
};

intArray::intArray(int size):arraysize(size)
{
    element = new int[size]; 
}

intArray::intArray(const intArray &x)
{
    arraysize = x.arraysize;
    element = new int[arraysize];
    for (int i = 0; i < arraysize; ++i)
        element[i] = x.element[i];
}
intArray::~intArray()
{
    delete[] element;
}

bool intArray::Set(int i, int elem)
{
    if (i<0||i>=arraysize) return false;
    element[i] = elem;
    return true;
}

bool intArray::Get(int i, int &elem)
{
    if (i<0||i>=arraysize) return false;
    elem = element[i];
    return true;
}
int intArray::Length( ) const
{
    return arraysize;
}
void intArray::ReSize(int size)
{
    if (size <= 0) return;
    int *newElem = new int[size];
    int minSize = (size < arraysize) ? size : arraysize;
    for (int i = 0; i < minSize; ++i)
        newElem[i] = element[i];
    delete[] element;
    element = newElem;
    arraysize = size;
}

void intArray::Print()
{
    for (int i = 0; i < arraysize; ++i)
    {
        cout << element[i] << ' ';
        cout << endl;
    }
}
