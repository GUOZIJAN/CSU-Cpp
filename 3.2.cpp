#include <iostream>
#include <string>
using namespace std;

class Publication
{
    public:
        Publication(std::string t,std::string n,float p,std::string d)
        {
            title = t;
            name = n;
            price = p;
            date = d;
        }
        ~Publication(){}

        void inputData()
        {
            cin>>title>>name>>price>>date;
        }

        void display()
        {
            cout<<"title:"<<title<<'\n'<<"name:"<<name<<'\n'<<"price:"<<price<<'\n'<<"date"<<date<<endl;
        }
        protected:
            std::string title;
            std::string name;
            float price;
            std::string date;
};

class Book:public Publication
{
    public:
        Book(std::string t,std::string n,float p,std::string d,int pa):Publication(t,n,p,d),page(pa){};
        ~Book(){};
        void inputData()
        {
            cin>>title>>name>>price>>date>>page;
        }
        void display()
        {
            Publication::display();
            cout<<"page:"<<page<<endl;
        }
        private:
            int page;
};

class Tape:public Publication
{
    public:
        Tape(std::string t,std::string n,float p,std::string d,int pa):Publication(t,n,p,d),playtime(pa){};
        ~Tape(){};
        void inputData()
        {
            cin>>title>>name>>price>>date>>playtime;
        }
        void display()
        {
            Publication::display();
            cout<<"playtime:"<<playtime<<endl;
        }
        private:
            int playtime;
};

int main()
{
    Book B("aa","bb",1.2,"cc",3);
    B.display();
    B.inputData();
    B.display();
}