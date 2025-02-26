#include <iostream>

using namespace std;

class Complex
{
private :
    int real;
    double imaginary;
public :
    int getreal()
    {
        return real;
    }

    void setreal(int _real)
    {
        real=_real;
    }
    int getimaginary()
    {
        return imaginary;
    }
    void setimaginary(double _imaginary)
    {
        imaginary=_imaginary;
    }
};


void complexprint (Complex comp)  //stand alone function that prints
{
    if(comp.getimaginary() == 0)
        cout<<"Complex no.= "<<comp.getreal();
    else if (comp.getimaginary() <0)
        cout<<"Complex no.= "<<comp.getreal()<<comp.getimaginary()<<"i";
    else
        cout<<"Complex no.= "<<comp.getreal()<<"+"<<comp.getimaginary()<<"i";
}
int main()
{
    Complex comp ;
    int r;
    double i;
    cout<<"Enter real number :";
    cin>>r;
    comp.setreal(r);
    cout<<"Enter imaginary number :";
    cin>>i;
    comp.setimaginary(i);
    complexprint(comp);
    return 0;
}
