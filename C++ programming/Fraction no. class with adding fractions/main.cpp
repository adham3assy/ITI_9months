#include <iostream>

using namespace std;

class fraction
{
    int num ;
    int den ;
public :
    void setnum(int _num)    //setters
    {
        num = _num;
    }
    void setden(int _den)
    {
        den = _den;
    }
    int getnum()           // getters
    {
        return num;
    }
    int getden()
    {
        return den;
    }

    fraction ()       // default constructor
    {
        num = 0;
        den = 1;
    }
    fraction (int _num)   //one parametric constructor
    {
        num = _num;
        den = 1;
    }
    fraction(int _num , int _den)  //two parametric constructor
    {
        num = _num;
        den = _den;
    }

    fraction(const fraction &f)   // Copy constructor
    {
        num = f.num;
        den = f.den;
    }

   fraction operator+(fraction &f)                  // sum of two fractions
   {
       int resultnum = num * f.den  +  f.num * den; // numerator = ( num1 * den2 )+( num2 * den1 )
       int resultden = den * f.den;                 // denominator = den1 * den2
       return fraction(resultnum , resultden);
   }

   fraction operator-(fraction &f)                  // subtraction of two fractions
   {
       int resultnum = num * f.den  -  f.num * den; // numerator = ( num1 * den2 )-( num2 * den1 )
       int resultden = den * f.den;                 // denominator = den1 * den2
       return fraction(resultnum , resultden);
   }

   fraction operator*(fraction &f)                  // Multiplication of two fractions
   {
       int resultnum = num * f.num;                 // numerator = num1 * num2
       int resultden = den * f.den;                 // denominator = den1 * den2
       return fraction(resultnum, resultden);
   }

    fraction operator/(fraction &f)                  // division of two fractions
   {
       int resultnum = num * f.den;                 // numerator = num1 * den2
       int resultden = den * f.num;                 // denominator = den1 * num2
       return fraction(resultnum, resultden);
   }

   fraction &operator++ ()                // increment numerator by 1
   {
       num++;
       return *this;
   }

     fraction &operator-- ()                // decrement numerator by 1
   {
       num--;
       return *this;
   }

   explicit operator float()               // Casting to float
   {
       return (float)(num)/den;
   }

   int gcd(int a, int b) {       // find the common divisor
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {           // simplification function
        int divisor  = gcd(num, den);
        num /= divisor ;
        den /= divisor ;
    }

    void print()
    {
        if (num % den == 0)
        {
            int fraction = num / den;
            cout << "Fraction = " << fraction << endl;
        }
        else {

                if (den == 1)
                        cout << "Fraction = " << num << endl;
                else
                        cout << "Fraction = " << num << "/" << den << endl;
             }
    }

~fraction()
{
    cout<<"destructor";
}
};



int main()
{
    fraction f , f1(10) , f2(2,2) , f3(3,4);       //initializing objects from class
    cout<<"F0 ";
    f.print();      // defualt print
    cout<<"F1 ";
    f1.print();     // one parametric print
    cout<<"F2 ";
    f2.print();     // two parametric print
    cout<<"F3 ";
    f3.print();

    fraction f4 = f2 + f3;                 // sum of 2 fractions
    cout<<endl<<"Sum of F2 and F3 :";
    f4.print();

    fraction f6 = f3 - f2;                 // subtraction of 2 fractions
    cout<<endl<<"Subtraction of F3 and F2 :";
    f6.print();

    fraction f7 = f3 * f2;                 // Multiplication of 2 fractions
    cout<<endl<<"Multiplication of F2 and F3 :";
    f7.print();

    fraction f8 = f3 / f2;                 // Division of 2 fractions
    cout<<endl<<"Division of F2 and F3 :";
    f8.print();

    float _float = (float)f3;              // casting to float
    cout<<endl<<"Casting F3 to float : "<<_float<<endl;

    cout<<endl<<"Incrementing F2 :";        // increment ++
    ++f2;
    f2.print();

    cout<<endl<<"Decrementing F3 :";       // decrement --
    --f3;
    f3.print();

    fraction f5 = f2 ;                     // f5 copy from f2
    cout<<endl<<"F5 copied from F2 : ";
    f5.print();

    cout<<endl<<"simplification of F3 :";   //simplification
    f3.simplify();
    f3.print();


    return 0;
}
