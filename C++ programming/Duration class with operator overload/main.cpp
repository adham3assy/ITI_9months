#include <iostream>

using namespace std;

class Duration
{
    int hours ;
    int minutes ;
    int seconds ;
public:
    Duration()         // default constructor
    {
        hours = 0;
        minutes =0;
        seconds=0;
    }
    Duration(int _seconds)         // one parametric constructor , enter the seconds
    {
        seconds = _seconds %60;
        minutes = (_seconds /60) %60;
        hours = _seconds/3600;
    }
    Duration(int _hours , int _minutes , int _seconds)//three parametric constructor , enter hours,minutes,seconds
    {
        seconds = _seconds % 60;
        minutes = (_minutes + _seconds /60) % 60;
        hours = _hours + (_minutes + _seconds /60) /60;
    }

    Duration operator=(const Duration &d)                //= assignment
    {
        hours = d.hours;
        minutes = d.minutes;
        seconds = d.seconds;
        return *this ;
    }

    Duration operator+(const Duration &d)                 // adding two durations
     const{
            int totalseconds = toseconds() + d.toseconds();
            return Duration(totalseconds);
    }

    Duration operator+(int n)                       // add duration by Seconds
     const{
           int totalseconds = toseconds() + n ;
           return Duration(totalseconds);
    }

    Duration &operator++()                          //increasing 1 minute
    {
        *this = Duration(toseconds()+60);
        return *this;
    }
     Duration &operator--()                         // decreasing 1 minute
    {
        *this = Duration(toseconds()-60);
        return *this;
    }


    bool operator<=(const Duration &d)
    {
        return toseconds() <= d.toseconds();
    }

    bool operator>=(const Duration &d)
    {
        return toseconds() >= d.toseconds();
    }


    int toseconds() const{                                //function to convert durations to seconds
        return hours*3600 + minutes*60 + seconds;
    }

    void print()                        // print Function
    {
        cout<<endl<<"Hours: "<<hours<<" , "<<"Minutes: "<<minutes<<" , "<<"Seconds: "<<seconds<<" ."<<endl;
    }

~Duration()
{

}
};

int main()
{
    Duration d , d1(1,10,122) , d2(3600) , d3(7800) , d4(666);   // initializing parametric constructors
    cout<<endl<<"Duration0 : ";
    d.print();
    cout<<endl<<"Duration1 : ";
    d1.print();
    cout<<endl<<"Duration2 : ";
    d2.print();
    cout<<endl<<"Duration3 : ";
    d3.print();
    cout<<endl<<"Duration4 : ";
    d4.print();

    cout<<endl<<"Duration1 + Duration2 = ";
    Duration d5 = d1 + d2 ;           // adding and assigning two durations
    d5.print();

    cout<<endl<<"Duration1 + 3600seconds = ";
    Duration d6 = d1 + 3600;          // adding duration by hour in (Seconds)
    d6.print();

    ++d1;                             // Pre increment
    cout<<endl<<"Duration1++ :";
    d1.print();
    --d2;                             // Pre decrement
    cout<<endl<<"Duration2-- :";
    d2.print();

    if (d1<= d2)
        cout<<endl<<"Duration1 is less than Duration2";
    else
        cout<<endl<<"Duration1 is bigger than Duration2";

    if (d3 >= d4)
        cout<<endl<<"Duration3 is bigger than Duration4"<<endl;
    else
        cout<<endl<<"Duration3 is less than Duration4"<<endl;
    return 0;
}
