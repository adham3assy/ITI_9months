#include <iostream>

using namespace std;



class Emp{
    int id;
    float comp;
public:
    void setId(int _id)
    {
        id=_id;

    }

    void setComp(float _comp)
    {
        comp = _comp;

    }

    int getId()
    {
        return id;
    }
    float getComp()
    {
        return comp;
    }

    void display()
    {
        cout<<"The id is : "<< id<<" , The compensation is : "<<comp<<endl;
    }
};

int main()
{
    Emp e[3];

    int id;
    float comp;

    for (int i = 0; i < 3; i++) {
        cout << "Enter details for employee " << (i + 1) << endl;


        cout << "Enter ID: ";
        cin >> id;
        e[i].setId(id);

        cout << "Enter compensation: ";
        cin >> comp;
        e[i].setComp(comp);

        cout << endl;
    }


    cout << "Employees details:" << endl;
    for (int i = 0; i < 3; i++) {
        e[i].display();
    }
    return 0;
}
