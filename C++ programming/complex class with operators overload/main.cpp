#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;
    static int counter;
public:
    static int getcounter(){return counter;}

    Complex()      //default constr.
    {
        real =1;
        img =1;
        counter++;
    }
    Complex(int _real , int _img)     //parametric constr.
    {
        real = _real;
        img = _img;
        counter++;
    }

    Complex operator+(Complex &c)     //sum of two complex no. together
    {
        Complex result ;
        result.real = c.real + real ;
        result.img = c.img + img ;
        return result;
    }

    Complex operator+(int n)        // add an integer to a complex no.
    {
        Complex result ;
        result.real = real + n;
        result.img = img + n;
        return result;
    }


    int operator== (Complex &c)      // compare if two complex numbers are equal
    {
        return
            real == c.real  &&  img == c.img ;
    }


    int operator!= (Complex &c)      // compare if two complex numbers are not equal
    {
        return
            real != c.real && img != c.img ;
    }


    Complex& operator+= (Complex &c)  // += by complex number
    {
        real = real + c.real;
        img = img + c.img;
        return *this ;
    }

    Complex& operator+= (int n)     // += by an integer
    {
        real = real + n;
        img = img + n;
        return *this ;
    }

    Complex& operator++ ()         //prefix
    {
        ++real ;
    }

    Complex& operator++ (int )        //postfix
    {

        real++;

    }

    explicit operator int()
    {
        return real;
    }


    void print ()                          //member print function
{
    if(img == 0)
        cout<<"Complex no.= "<<real<<endl;
    else if (img <0)
        cout<<"Complex no.= "<<real<<img<<"i"<<endl;
    else
        cout<<"Complex no.= "<<real<<"+"<<img<<"i"<<endl;
}

~ Complex()
{
   counter--;
    cout<<"destructor.."<<endl;
}

friend ostream &operator<<(ostream &os, const Complex &c);  //prototype Friend function to overload << operator


};
int Complex::counter=0;


ostream &operator<<(ostream &os, const Complex &c)   // stand alone function to overload << operator
{
    if (c.img == 0)
        os << c.real;
    else if (c.img < 0)
        os << c.real << c.img << "i";
    else
        os << c.real << "+" << c.img << "i";
    return os;
}
int main()
{
    Complex c (20,20), c1(10,10);
    c.print();              // default constr.
    c1.print();             // parametric constr.

    Complex c3 = c + c1;    //adding two Complex numbers
    c3.print();

    Complex c4 = c + 5;     //adding complex number by integer
    c4.print();
    // cout<<endl<<"Number of objects created : "<<Complex::getcounter();

   if (c == c1)              // to check if the two complex no. are equal or not
   {
       cout<<endl<<"Two complex no. are equal!"<<endl<<endl;
   }else if(c != c1)
   {
        cout<<endl<<"Two complex no. are not equal!"<<endl<<endl;
   }

    c4 = c4 + c1;               // += two complex numbers
    c4.print();

    c4 =c4 + 10;               // += by integer
    c4.print();

    c++;
    c.print();              // postfix ++
    ++c;
    c.print();              // prefix ++

    int x = (int)c;         //casting complex to integer
    cout<<endl<<"Casting complex to integer : "<<x<<endl;

    cout << endl << "Printing complex using << operator:" << endl;
    cout << "c : " << c << endl;
    cout << "c1: " << c1 << endl;
    cout << "c3: " << c3 << endl;
    cout << "c4: " << c4 << endl;

    cout<<endl<<"Number of objects created : "<<Complex::getcounter()<<endl;

    return 0;
}
