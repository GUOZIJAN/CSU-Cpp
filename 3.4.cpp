#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/*=================== 基类 Employee ===================*/
class Employee {
protected:
    string name;     // 姓名
    int    id;       // 编号
    int    grade;    // 级别
    double salary;   // 当月薪水

public:
    Employee(const string& n, int i)
        : name(n), id(i), grade(1), salary(0) {}

    virtual ~Employee() {}

    /* 升级：默认升 0 级，派生类可覆盖 */
    virtual void promote(int step = 0) { grade += step; }

    /* 计算月薪：派生类实现 */
    virtual void pay() = 0;

    /* 显示全部信息 */
    virtual void display() const {
        cout << left << setw(12) << name
             << setw(6) << id
             << setw(6) << grade
             << setw(10) << fixed << setprecision(2) << salary;
    }
};

/*==================== 经理 ====================*/
class Manager : public Employee {
public:
    Manager(const string& n, int i) : Employee(n, i) {}
    void promote(int step = 3) override { Employee::promote(step); } // 升3级→4
    void pay() override { salary = 8000; }
    void display() const override {
        Employee::display();
        cout << " 职位：经理" << endl;
    }
};

/*==================== 技术人员 ====================*/
class Technician : public Employee {
    double hours; // 当月工作小时数
public:
    Technician(const string& n, int i, double h = 0)
        : Employee(n, i), hours(h) {}
    void promote(int step = 2) override { Employee::promote(step); } // 升2级→3
    void pay() override { salary = hours * 100; }
    void display() const override {
        Employee::display();
        cout << " 职位：技术人员  工时：" << hours << "h" << endl;
    }
};

/*==================== 销售员 ====================*/
class Salesman : public Employee {
    double sales; // 当月个人销售额
public:
    Salesman(const string& n, int i, double s = 0)
        : Employee(n, i), sales(s) {}
    void pay() override { salary = sales * 0.04; }
    void display() const override {
        Employee::display();
        cout << " 职位：销售员  销售额：" << sales << endl;
    }
};

/*==================== 销售经理 ====================*/
class SalesManager : public Employee {
    double deptSales; // 部门销售额
public:
    SalesManager(const string& n, int i, double ds = 0)
        : Employee(n, i), deptSales(ds) {}
    void promote(int step = 2) override { Employee::promote(step); } // 升2级→3
    void pay() override { salary = 5000 + deptSales * 0.005; }
    void display() const override {
        Employee::display();
        cout << " 职位：销售经理  部门销售额：" << deptSales << endl;
    }
};

/*==================== main ====================*/
int main() {
    vector<Employee*> staff;
    staff.push_back(new Manager("Zhang", 1001));
    staff.push_back(new Technician("Li", 2001, 160));
    staff.push_back(new Salesman("Wang", 3001, 50000));
    staff.push_back(new SalesManager("Liu", 4001, 200000));

    /* 统一升级、计算月薪、输出信息 */
    for (auto e : staff) {
        e->promote(); // 按各自规则升级
        e->pay();
        e->display();
    }

    /* 释放资源 */
    for (auto e : staff) delete e;
    return 0;
}