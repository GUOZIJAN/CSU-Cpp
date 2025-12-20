/*
结果
=== 用带参构造函数创建 ===
基本工资: 8000
岗位津贴: 2000
房租: 1000
水费: 150
电费: 250
实发工资: 8600

=== 用无参构造函数+setXX ===
实发工资: 8100
*/
#include <iostream>
using namespace std;

class Salary
{
public:
    Salary() : Wage(0), Subsidy(0), Rent(0), WaterFee(0), ElecFee(0) {}

    Salary(double wage, double subsidy,
           double rent, double water, double elec)
        : Wage(wage), Subsidy(subsidy), Rent(rent),
          WaterFee(water), ElecFee(elec) {}


    void setWage(double f)     { Wage = f; }
    void setSubsidy(double f)  { Subsidy = f; }
    void setRent(double f)     { Rent = f; }
    void setWaterFee(double f) { WaterFee = f; }
    void setElecFee(double f)  { ElecFee = f; }


    double getWage()     const { return Wage; }
    double getSubsidy()  const { return Subsidy; }
    double getRent()     const { return Rent; }
    double getWaterFee() const { return WaterFee; }
    double getElecFee()  const { return ElecFee; }


    double RealSalary() const
    {
        return Wage + Subsidy - Rent - WaterFee - ElecFee;
    }

private:
    double Wage, Subsidy, Rent, WaterFee, ElecFee;
};


int main()
{
    Salary s1(8000, 2000, 1000, 150, 250);
    cout << "=== 用带参构造函数创建 ===" << endl;
    cout << "基本工资: " << s1.getWage() << endl;
    cout << "岗位津贴: " << s1.getSubsidy() << endl;
    cout << "房租: " << s1.getRent() << endl;
    cout << "水费: " << s1.getWaterFee() << endl;
    cout << "电费: " << s1.getElecFee() << endl;
    cout << "实发工资: " << s1.RealSalary() << endl;

    Salary s2;
    s2.setWage(7500);
    s2.setSubsidy(1800);
    s2.setRent(900);
    s2.setWaterFee(120);
    s2.setElecFee(180);
    cout << "\n=== 用无参构造函数+setXX ===" << endl;
    cout << "实发工资: " << s2.RealSalary() << endl;

    return 0;
}