/*结果
成绩最高者：学号=1004  成绩=95
*/
#include <iostream>
#include <string>
using namespace std;

class Student
{
    public:
        Student(std::string n,std::string s):num(n),score(s){};
        std::string    getNum()     { return num; }
        std::string getScore()  { return score; }
    private:
        std::string num,score;
};

void max(Student* s)
{
    Student* pmax = s;
    for(int i=1;i<5;i++)
    {
        if((s+i)->getScore()>pmax->getScore()) pmax = s+i;
    }
    cout << "成绩最高者：学号=" << pmax->getNum()
         << "  成绩=" << pmax->getScore() << endl;
}

int main()
{
    Student stu[5] = {
        Student("1001", "85"),
        Student("1002", "92"),
        Student("1003", "78"),
        Student("1004", "95"),
        Student("1005", "88")
    };

    max(stu);   // 传入数组首地址（即对象指针）
    return 0;
}