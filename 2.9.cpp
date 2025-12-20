//结果4+2i

#include <iostream>
using namespace std;

class Complex
{
private:
    double real;   
    double imag;   
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    void show() const
    {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
    friend Complex add(const Complex &a, const Complex &b);
};


Complex add(const Complex &a, const Complex &b)
{
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main()
{
    Complex c1(3, 4), c2(1, -2);
    Complex c3 = add(c1, c2); 
    c3.show();               
    return 0;
}