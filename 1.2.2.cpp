#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    private:
        std::string accountNo;
        int balance;
        std::string holderName;
    public:
        BankAccount(std::string accountNo_,int balance_,std::string holderName_):accountNo(accountNo_),balance(balance_),holderName(holderName_){}
        void withdraw(int value)
        {
            if(balance>=value)  balance-=value;
            else cout<<"余额不足"<<endl;
        }
        void deposit(int value)
        {
            if(value>0)  balance+=value;
            else cout<<"请输入正确数值"<<endl;
        }
        void showBalance()
        {
            cout<<"Balance:"<<balance<<endl;
        }
        void showDetails()
        {
            cout<<"accountNo:"<<accountNo<<'\n'<<"balance:"<<balance<<'\n'<<"holderName:"<<holderName<<endl;
        }
};
int main()
{
    BankAccount b("123456789",66666,"abc");
    b.withdraw(10);
    b.deposit(20);
    b.showBalance();
    b.showDetails();
    return 0;
}