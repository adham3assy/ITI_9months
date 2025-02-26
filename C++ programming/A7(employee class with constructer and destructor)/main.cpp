#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class emp
{

    int id ;
    char name[30];
    int age ;
public :
    int getid()
    {
        return id ;
    }
    void setid(int _id)
    {
        id = _id;
    }

    char *getname()
    {
        return name ;
    }
    void setname(char *_name)
    {
        strcpy(name,_name);
    }
    int getage()
    {
        return age ;
    }
    void setage(int _age)
    {
        age= _age;
    }
    emp()          //default constructor
    {
        id=1;
        strcpy(name, "no name");
        age=25;
    }

    emp(int _id)                       //1 parameter constr.
    {
        id=_id;
        strcpy(name,"no name");
        age=25;
    }

    emp(int _id ,char _name[])        //2 parameter constr.
    {
        id=_id;
        strcpy(name,_name);
        age=25;
    }

     emp(int _id ,char _name[],int _age)    //3 parameter constr.
    {
        id=_id;
        strcpy(name,_name);
        age=_age;
    }

    ~ emp()                     //destructor
    {
        cout<<"Object deleted.."<<endl;
    }
};

int main()
{
    emp e1 , e2(5) ,e3(10,"adham") ,e4(20,"assy",24) ;
    int x , y ;
    char n[30] ;
    cout<<"Enter the id : ";
    cin>>x;
    e1.setid(x);
    cout<<"Enter the name :";
    cin>>n;
    e1.setname(n);
    cout<<"Enter the age :";
    cin>>y;
    e1.setage(y);
    cout<<endl<<e1.getid()<<":"<<e1.getname()<<":"<<e1.getage()<<endl<<endl;
    cout<<e2.getid()<<":"<<e2.getname()<<":"<<e2.getage()<<endl<<endl;
    cout<<e3.getid()<<":"<<e3.getname()<<":"<<e3.getage()<<endl<<endl;
    cout<<e4.getid()<<":"<<e4.getname()<<":"<<e4.getage()<<endl<<endl;
    return 0;
}
