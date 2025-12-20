/*
结果
(1,2)
(1,4)
(3,4)
(3,2)
4
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Point
{
    public:
        Point(float x_=0,float y_=0):x(x_),y(y_){};
        float x,y;
};

class Rect
{
    public:
        Rect(Point* a_,Point* b_):a(a_),b(b_){};

        void show()
        {
            cout<<'('<<a->x<<','<<a->y<<')'<<'\n'
            <<'('<<a->x<<','<<b->y<<')'<<'\n'
            <<'('<<b->x<<','<<b->y<<')'<<'\n'
            <<'('<<b->x<<','<<a->y<<')'<<'\n';
        }

        void cals()
        {
            cout<<abs((a->x)-(b->x))*abs((a->y)-(b->y));
        }
    private:
        Point* a;
        Point* b;
};

int main()
{
    Point* a = new Point(1.0,2.0);
    Point* b = new Point(3.0,4.0);
    Rect R(a,b);
    R.show();
    R.cals();
    return 0;
}