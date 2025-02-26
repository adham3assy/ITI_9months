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
};

int main()
{
    emp e1 ;
    emp* ptr = new emp;
    int x , y ;
    char n[30] ;
    cout<<"Enter the id : ";
    cin>>x;
    ptr->setid(x);
    cout<<"Enter the name :";
    cin>>n;
    ptr->setname(n);
    cout<<"Enter the age :";
    cin>>y;
    ptr->setage(y);
    cout<<ptr->getid()<<":"<<ptr->getname()<<":"<<ptr->getage();
    return 0;
}
