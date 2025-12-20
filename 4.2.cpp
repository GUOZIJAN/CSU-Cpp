#include <iostream>
using namespace std;

/*================  1. 基类：点  =================*/
class Point {
protected:
    double x, y;
public:
    Point() : x(0), y(0) {}
    virtual ~Point() {}          // 基类析构函数最好为虚
    virtual void set() {
        cout << "输入点坐标 x y：";
        cin >> x >> y;
    }
    virtual void display() const {
        cout << "Point: (" << x << ", " << y << ")\n";
    }
};

/*================  2. 派生：圆  =================*/
class Circle : public Point {
protected:
    double radius;
public:
    Circle() : Point(), radius(0) {}
    void set() override {
        Point::set();            // 先读 x,y
        cout << "输入圆半径：";
        cin >> radius;
    }
    void display() const override {
        cout << "Circle center: (" << x << ", " << y << "), radius: " << radius << '\n';
    }
};

/*================  3. 再派生：圆柱体  =================*/
class Cylinder : public Circle {
    double height;
public:
    Cylinder() : Circle(), height(0) {}
    void set() override {
        Circle::set();           // 先读圆心、半径
        cout << "输入圆柱高：";
        cin >> height;
    }
    void display() const override {
        cout << "Cylinder center: (" << x << ", " << y
             << "), radius: " << radius << ", height: " << height << '\n';
    }
};

/*================  4. 测试：虚函数多态  =================*/
int main() {
    Point *p = nullptr;

    int choice;
    cout << "1-Point  2-Circle  3-Cylinder\n选择要创建的对象类型：";
    cin >> choice;

    switch (choice) {
    case 1: p = new Point;     break;
    case 2: p = new Circle;    break;
    case 3: p = new Cylinder;  break;
    default: cout << "非法选择\n"; return 0;
    }

    p->set();      // 动态绑定到对应类的 set()
    cout << "\n=== 您输入的信息 ===\n";
    p->display();  // 动态绑定到对应类的 display()

    delete p;
    return 0;
}