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
Complex()               //parameterless constr(default)
{
    real=10;
    imaginary=10;
}

Complex(int _real)      //one parameter constr.
{
    real= _real;
    imaginary=0;
}

Complex(int _real , double _imaginary)   //two parameter constr.
{
    real= _real;
    imaginary= _imaginary;
}

Complex add(int _real , double _imaginary)    //member add function
{
    Complex res ;
    res.real=real + _real;
    res.imaginary=imaginary + _imaginary;
    return res;
}
void complexprint ()                          //member print function
{
    if(imaginary == 0)
        cout<<"Complex no.= "<<real<<endl;
    else if (imaginary <0)
        cout<<"Complex no.= "<<real<<imaginary<<"i"<<endl;
    else
        cout<<"Complex no.= "<<real<<"+"<<imaginary<<"i"<<endl;
}
};

Complex add(Complex comp , Complex comp1 )    //stand alone add function
{
    Complex res ;
    res.setreal(comp.getreal() + comp1.getreal()) ;
    res.setimaginary(comp.getimaginary() + comp1.getimaginary());
    return res;
}


int main()
{
    Complex comp , comp1(2) , comp2(5,15) ;   //object from the class that initialize the constructors

    int r;
    double i;
    cout<<"Enter real number :";
    cin>>r;
    comp.setreal(r);
    cout<<"Enter imaginary number :";
    cin>>i;
    comp.setimaginary(i);
    comp.complexprint();
    comp1.complexprint();
    comp2.complexprint();
    Complex z = add(comp,comp2);
    cout<<"Sum of ";
    z.complexprint();
    return 0;
}
