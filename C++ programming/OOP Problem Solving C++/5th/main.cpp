#include <iostream>

using namespace std;


class Date{
    int year;
    int month;
    int day;
public:
    Date(int _day=1,int _month =1,int _year=2000)
    {
        day = _day;
        month =_month;
        year = _year;
    }

    void setDate(int _day=1,int _month =1,int _year=1)
    {
        day = _day;
        month =_month;
        year = _year;

    }
    int getDate ()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void display()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;

    }

};

int main()
{

    Date d1;
    Date d2(5, 6, 2024);
    Date d3;
    d1.display();
    d2.display();
    d3.setDate(8,8,2000);
    d3.display();
    d3.getDate();
    d3.display();

    return 0;
}
