/*
结果
默认时间: 00:00:00
指定时间: 23:59:55
动态设置后: 09:08:07
*/
#include <iostream>
#include <iomanip> 
using namespace std;

class Clock
{
    public:
        Clock(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){};
        void setTime(int h,int m,int s)
        {
            hour = h;
            minute = m;
            second = s;
        }
        void show()
        {
            cout << setfill('0') << setw(2) << hour   << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << endl;
        }
    private:
        int hour;
        int minute;
        int second;
};

int main()
{
    Clock c1;
    cout << "默认时间: ";
    c1.show();

    Clock c2(23, 59, 55);
    cout << "指定时间: ";
    c2.show();

    c1.setTime(9, 8, 7);
    cout << "动态设置后: ";
    c1.show();

    return 0;
}