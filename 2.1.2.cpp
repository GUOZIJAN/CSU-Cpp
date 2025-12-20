static int s_dummy;
class X
{ private:
    int a=0;
    int &b;
    int c;
    
    
public:
    X():a(0), b(s_dummy) {}
    X(int i, int& j, int k) : a(i), b(j), c(k) {}
    X(int i) : a(i), b(s_dummy) {}
    void setC(int k) { c += k; }
    void setA(int i) { a = i; }
};
int main()
{
    int external = 10;
    X x1;
    X x2(2);
    X x3(1,external,3);
    x1.setA(3);
    return 0;
}