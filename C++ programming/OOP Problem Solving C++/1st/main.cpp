#include <iostream>

using namespace std;


class Int{

    int num1 ;
    int num2 ;
public:
    Int()
    {
        num1 = 1;
        num2 = 2;
    }
    Int(int _num1)
    {
        num1 = _num1;
        num2 = 2;
    }
    Int(int _num1 ,int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }

    void set(int _num1, int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }
    void print()
    {
        cout<<"num1 = "<< num1<<endl ;
        cout<<"num2 = "<< num2<<endl ;
    }

    int Sum()
    {
        int Result = num1 + num2 ;
        return Result;
    }
};



int main()
{
    Int n , n2(10) , n3(10,20) ;
    n.print();
    n2.print();
    n3.print();

    cout<<"Sum of the two numbers = "<<n.Sum()<<endl;
    cout<<"Sum of the two numbers = "<<n2.Sum()<<endl;
    cout<<"Sum of the two numbers = "<<n3.Sum()<<endl;
    return 0;
}
