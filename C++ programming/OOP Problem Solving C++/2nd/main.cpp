#include <iostream>

using namespace std;


class tollBooth{
    unsigned int car;
    double money;
public:
    tollBooth()
    {
        money = 0;
        car = 0;
    }
    void  payingCar(){
        car++;
        money = money+50;
        }
    void nopayCar(){
        car++;
    }
    void display(){
    cout<< "The Total number of cars : "<<car<<endl;
    cout<< "The Total amount of money : "<<money;

    }
};

int main()
{
    tollBooth car;

    car.payingCar();
    car.payingCar();
    car.payingCar();

    car.nopayCar();
    car.nopayCar();

    car.display();

    return 0;
}
