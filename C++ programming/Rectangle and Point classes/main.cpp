#include <iostream>

using namespace std;

class Point {

    int x, y;

public:

    Point() { x=0, y=0 ; }                      // Default constructor
    Point(int _x, int _y) { x= _x , y= _y ; }   // Parametric constructor


    void setX(int _x)       // Setters
    {
        x = _x;
    }
    void setY(int _y)
    {
        y = _y;
    }
    int getX() const        // Getters
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
~Point() {cout<<endl<<"Point destroyed..";}        // Destructor

};


class Rect
{
    Point UL , LR ;
public:
    Rect()               // default constructor
    {
        cout<<endl<<"default rect constructor";
    }

    Rect(int x1 , int y1 , int x2 , int y2) : UL  (x1 , y1) , LR (x2 , y2){}   // parametric constructor inherited

    //Rect(Point* _UL , Point* _LR) : UL(_UL) , LR(_LR){}   // chain constructor

   // Point *getUL(){return UL;}
    //Point *getLR(){return LR;}

    void print()
    {
        cout <<endl<< "Upper left point: "<<"("<<UL->getX()<<" , "<<UL->getY()<<")"<<endl;

        cout <<endl<< "Lower right point: "<<"("<<LR->getX()<<" , "<<LR->getY()<<")"<<endl;
    }

    ~Rect() {cout<<endl<<"Rectangle destroyed..";}
};

class Circle
{
    Point center;
    int radius;
public:
    Circle()   // default constructor
    {
        cout<<endl<<"default circle constructor";
    }
    /*Circle(Point _center , int _radius)  // parametric constructor
    {
        center = _center;
        radius = _radius;
    }*/

   Circle(int x  , int y , int _radius) : center(x , y) // parametric constructor
    {
        radius = _radius;
    }

  //  Circle(Point* _center, int _radius) : center(_center), radius(_radius) {} // chain constructor


   /* void setCenter(Point* _center)        // setters
    {
        center = _center;
    }
    void setRadius(int _radius)
    {
        radius = _radius;
    }*/

    Point *getCenter() {return center;}  // getters
    int getRadius() {return radius;}

    void print()
    {
        cout<<endl<<"Center point : "<<"("<<center->getX()<<" , "<<center->getY()<<")"<<endl;
        cout<<"Radius = "<<radius<<endl;
    }

    ~Circle()
    {
        cout<<endl<<"Circle is destroyed..";
    }
};

int main()
{
    Rect r1(10,20,30,10);        // Rectangle initialization
    /*Point p1(10,20);
    Point p2(30,10);
    Rect r1(&p1,&p2);*/
    r1.print();

    /*Point p1(30,40);
    Circle c1(p1,10);            // Circle initialization
    c1.print();*/

    Circle c2(30,40,10);         // inheritance
   // Point p3(30,40);
    /*Circle c1(&p1,10);*/
    c2.print();
    return 0;
}
