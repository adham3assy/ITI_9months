#include <iostream>

using namespace std;


class Stack
{
    int arr[5];
    int tos;
    int size;
public :
    Stack ()
    {
        tos = -1;
        size = 5;
    }

    void Push (int d)
    {
        if(tos<size-1)
        {
            tos++;
            arr[tos]=d;
        }
        else
            cout<<"\nstack is full! \n";
    }

    int pop(int &x)
    {
        if(tos !=-1)
        {
            x=arr[tos];
            tos--;
            return 1;
        }
        else
        {
            cout<<"\n stack is empty\n";
            return 0;
        }
    }

    void print ()
    {
        if (tos == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        else{
        for(int i=0;i<=tos;i++)
            cout<<arr[i]<<endl;
        }
    }

    ~ Stack()
    {
        cout<<"\ndestructor...";
    }
};



int main()
{
    Stack s1 ;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);
    s1.Push(60);
    s1.print();
    int x=0;
    if(s1.pop(x)==1)
        cout<<endl<<x<<" is popped."<<endl;
    s1.print();
    if(s1.pop(x)==1)
        cout<<endl<<x<<" is popped."<<endl;
    s1.print();

    return 0;
}
