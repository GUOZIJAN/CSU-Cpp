#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        std::string title_;
        std::string author_;
        std::string ISBN_;
        int year_;
    public:
        Book(const std::string& title,const std::string& author,int year,const std::string& ISBN);
        void DisplayBook();
        void UpdataYear(int year);
};
Book::Book(const std::string& title,const std::string& author,int year,const std::string& ISBN):title_(title), author_(author), year_(year), ISBN_(ISBN) {}
void Book::DisplayBook()
{
    cout<<"title:"<<title_<<'\n'<<"author:"<<author_<<'\n'<<"ISBN:"<<ISBN_<<'\n'<<"year:"<<year_<<endl;
}

void Book::UpdataYear(int year)
{
    year_ = year;
    cout<<"将时间修改为"<<year_<<endl;
}

int main()
{
    Book b("python","abc",1995,"123456");
    b.DisplayBook();
    b.UpdataYear(1996);
    return 0;
}