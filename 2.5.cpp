/*结果
三角形三边:a=3 b=4 c=5
周长： 12
面积： 6

三角形三边:a=5 b=12 c=13
周长： 30
面积： 30

三角形三边:a=2 b=2 c=3
周长： 7
面积： 1.98431
*/

#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
public:
    Triangle(double aa = 3, double bb = 4, double cc = 5)
    {
      a = aa;
      b = bb;
      c = cc;
    }

    double perimeter() { return a + b + c; }


    double area() 
    {
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }


    void show() 
    {
        cout << "三角形三边:a=" << a << " b=" << b << " c=" << c << endl;
        cout << "周长： " << perimeter() << endl;
        cout << "面积： " << area() << endl << endl;
    }

private:
    double a, b, c;
};

int main()
{
    Triangle t1;              
    Triangle t2(5, 12, 13);    
    Triangle t3(2, 2, 3);     

    t1.show();
    t2.show();
    t3.show();

    return 0;
}