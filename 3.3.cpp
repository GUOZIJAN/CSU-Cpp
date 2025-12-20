#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*==================== 1. 分数类 ====================*/
class Score {
private:
    double Chinese;
    double English;
    double Mathematics;

public:
    /*----- 构造函数 -----*/
    Score() : Chinese(0), English(0), Mathematics(0) {}
    Score(double c, double e, double m)
        : Chinese(c), English(e), Mathematics(m) {}

    /*----- 成员函数 -----*/
    double sum() const { return Chinese + English + Mathematics; }

    void print() const {
        cout << "Chinese   = " << Chinese
             << "\nEnglish   = " << English
             << "\nMath      = " << Mathematics
             << "\nSum       = " << sum() << endl;
    }

    void modify() {
        cout << "Input Chinese English Mathematics: ";
        cin  >> Chinese >> English >> Mathematics;
    }
};

/*==================== 2. 学生类 ====================*/
class Student {
private:
    string Num;
    string Name;
    Score  MyScore;      // 成绩对象

public:
    /*----- 构造函数 -----*/
    Student() {}
    Student(const string& num, const string& name, const Score& s)
        : Num(num), Name(name), MyScore(s) {}

    /*----- 成员函数 -----*/
    double sum() const { return MyScore.sum(); }

    void print() const {
        cout << "Num   : " << Num
             << "\nName  : " << Name << endl;
        MyScore.print();
    }

    void modify() {
        cout << "Input Num Name: ";
        cin  >> Num >> Name;
        MyScore.modify();
    }
};

/*==================== 3. 主函数 ====================*/
int main() {
    const int N = 3;              // 学生人数
    Student stuArr[N];            // 先定义对象数组

    /* 循环赋值 */
    for (int i = 0; i < N; ++i) {
        cout << "\nInput info for student " << i + 1 << ":\n";
        stuArr[i].modify();
    }

    /* 输出结果 */
    cout << "\n========== All Students ==========\n";
    for (int i = 0; i < N; ++i) {
        cout << "\n----- Student " << i + 1 << " -----\n";
        stuArr[i].print();
    }
    return 0;
}