#include <iostream>
using namespace std;

class Rectangle {
    public:

        int width;
        int length;
};

Rectangle rect;

void setSize(void) 
{
    cin >> rect.width;
    cin >> rect.length;
}

void getArea(void) 
{
    int area = rect.width * rect.length;
    cout << "Area is: " << area << endl;
}
int main() 
{
    setSize();
    getArea();
    return 0;
}

