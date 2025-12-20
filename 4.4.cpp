#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int y, m, d;

    /* 闰年判断 */
    static bool isLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    /* 当月天数 */
    static int daysOfMonth(int year, int month) {
        static int tab[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        return (month == 2 && isLeap(year)) ? 29 : tab[month];
    }

    /* 日期合法性检查 */
    bool isValid() const {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;
        return d <= daysOfMonth(y, m);
    }

    /* 把日期调整为合法范围（加减天数核心）*/
    void normalize() {
        if (!isValid()) {           // 只处理非法情况
            while (d < 1) {         // 往前借月
                --m;
                if (m < 1) { --y; m = 12; }
                d += daysOfMonth(y, m);
            }
            while (d > daysOfMonth(y, m)) { // 往后进月
                d -= daysOfMonth(y, m);
                ++m;
                if (m > 12) { ++y; m = 1; }
            }
        }
    }

public:
    /* 默认构造：2012-01-01 */
    Date(int yy = 2012, int mm = 1, int dd = 1): y(yy), m(mm), d(dd) {
        if (!isValid()) { y = 2012; m = 1; d = 1; } // 非法则回滚
    }

    /* 动态设置 */
    void setYear(int yy)  { int old = y; y = yy;   if (!isValid()) y = old; }
    void setMonth(int mm) { int old = m; m = mm;   if (!isValid()) m = old; }
    void setDay(int dd)   { int old = d; d = dd;   if (!isValid()) d = old; }

    /* 输出 yyyy-m-d */
    friend ostream& operator<<(ostream& os, const Date& dt) {
        os << dt.y << '-' << dt.m << '-' << dt.d;
        return os;
    }

    /* 关系运算 */
    bool operator==(const Date& o) const { return y == o.y && m == o.m && d == o.d; }
    bool operator!=(const Date& o) const { return !(*this == o); }
    bool operator< (const Date& o) const {
        return y != o.y ? y < o.y : (m != o.m ? m < o.m : d < o.d);
    }
    bool operator> (const Date& o) const { return o < *this; }

    /* 加减天数 */
    Date& operator+=(int days) { d += days; normalize(); return *this; }
    Date& operator-=(int days) { return *this += -days; }

    /* 前后置 ++、-- */
    Date& operator++()    { return *this += 1; }          // 前置++
    Date  operator++(int) { Date tmp = *this; ++*this; return tmp; }
    Date& operator--()    { return *this -= 1; }          // 前置--
    Date  operator--(int) { Date tmp = *this; --*this; return tmp; }
};

/*==================== 测试 ====================*/
int main() {
    Date d1;                      // 2012-01-01
    Date d2(2023, 2, 28);
    cout << "d1: " << d1 << '\n';
    cout << "d2: " << d2 << '\n';

    ++d2; cout << "++d2: " << d2 << '\n';   // 2023-03-01
    d2 += 365; cout << "+365: " << d2 << '\n';

    Date d3(2000, 2, 29);         // 闰年
    cout << "d3: " << d3 << '\n';
    --d3; cout << "--d3: " << d3 << '\n';   // 2000-02-28

    cout << boolalpha;
    cout << "d1 < d2 ? " << (d1 < d2) << '\n';
    cout << "d2 == d3 ? " << (d2 == d3) << '\n';
    return 0;
}