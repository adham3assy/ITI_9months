#include <iostream>
#include <string.h>

using namespace std;

class Person
{
protected:
    int id;
    char name[30];
    int age;
public:
    Person(){ id=0 , strcpy(name , "no name") , age=0 ;}            // default constructor
    Person(int _id , char* _name , int _age){id= _id , strcpy(name , _name) , age= _age ; }// Parametric constructor

    void printperson()      // function to print the parent
    {
        cout<<endl<<"Person data =  "<<id<<" : "<<name<<" : "<<age;
    }
};

class Employee: public Person      // child class
{
    int salary;
public:
    Employee(int _id , char* _name , int _age):Person(_id , _name , _age) {salary = 5000 ; }
    Employee(int _id , char* _name , int _age , int _salary):Person(_id , _name , _age) {salary = _salary ; }
    void setsalary(int _salary){salary = _salary;}
    int getsalary(){return salary;}
    void print()
    {
        printperson();
        cout<<endl<<"Employee Salary =  "<<salary<<"$"<<endl;
    }
};

class Student: public Person    // child class
{
    int grade;
public :
    Student(int _id , char* _name , int _age):Person(_id , _name , _age) {grade = 1 ; }
    Student(int _id ,  char* _name , int _age , int _grade):Person(_id , _name , _age) {grade = _grade ; }
    void setgrade(int _grade){grade = _grade;}
    int getgrade(){return grade;}
    void print()
    {
        printperson();
        cout<<endl<<"Student Grade =  "<<grade<<endl;
    }
};

int main()
{
    Person p;       // default constructor
    p.printperson();
    cout<<endl;
    Employee e(8829,"Adham",25,3000);   // employee
    e.print();
    Student s(1233,"Aly",18,12);        // student
    s.print();
    return 0;
}
