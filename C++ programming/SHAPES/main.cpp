#include <iostream>

using namespace std;

class Shapes
{
protected:
  int dim1;
  int dim2;
public:
    Shapes(){dim1=dim2=1;}  // default constructor
    Shapes(int _dim1){dim1= _dim1 , dim2= _dim1 ; }   // constructor with one parameter
    Shapes(int _dim1 , int _dim2){dim1= _dim1 , dim2= _dim2 ;} // constructor with two parameters

    virtual int calc_area()=0;           // Pure virtual function

~Shapes()
{
    cout<<endl<<"Shapes destroyed.."<<endl;
}
};

class Rect: public Shapes
{
public:
    Rect(int _dim1 , int _dim2):Shapes(_dim1 , _dim2){}

    int calc_area(){return  dim1 * dim2;}  // rectangle area
~Rect()
{
    cout<<"Rectangle destroyed.."<<endl;
}
};

class Triangle: public Shapes
{
public:
    Triangle(int _dim1 , int _dim2):Shapes(_dim1 , _dim2){}

    int calc_area(){return  0.5 * dim1 * dim2;}  // Triangle area
~Triangle()
{
    cout<<"Triangle destroyed.."<<endl;
}
};

class Circle: public Shapes
{
public:
    Circle(int _dim1):Shapes(_dim1){}

    int calc_area(){return  22/7 * dim1 * dim2;}   // Circle area

    void setdim1(int _dim1){dim1 = dim2 = _dim1;}  // Setters to make dim1 = dim2
    void setdim2(int _dim1){dim1 = dim2 = _dim1;}

~Circle()
{
    cout<<"Circle destroyed.."<<endl;
}
};

class Square:public Rect    // inherit form rect class
{
public:
    Square(int _dim1):Rect(_dim1 , _dim1){}

    int calc_area(){return dim1 * dim1;}    // Square area

    void setdim1(int _dim1){dim1 = dim2 = _dim1;}  // Setters to make dim1 = dim2
    void setdim2(int _dim1){dim1 = dim2 = _dim1;}

~Square()
{
    cout<<"Square destroyed.."<<endl;
}
};


int area_sum(Shapes* arr[] , int Size)    // function to get the sum of all areas
{
    int sum = 0;
    for(int i=0;i<Size;i++)
        sum += arr[i] -> calc_area();    // Calculate the areas of all the shapes and put it in sum
    return sum;
}


int main()
{
    Rect r(10,20);       // initializing objects
    Triangle t(10,20);
    Circle c(10);
    Square s(10);

    Shapes* arr[] = { &r, &t, &c, &s };  // an array of pointers to shapes

    cout<<"Area of Rectangle = "<<r.calc_area()<<endl;    // printing Areas
    cout<<"Area of Triangle = "<<t.calc_area()<<endl;
    cout<<"Area of Circle = "<<c.calc_area()<<endl;
    cout<<"Area of Square = "<<s.calc_area()<<endl;

    int sum = area_sum(arr , 4);
    cout<<"Sum of all areas = "<<sum<<endl;  // printing the sum of all areas
    return 0;
}
