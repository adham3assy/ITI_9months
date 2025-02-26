#include <iostream>

using namespace std;


class Stack
{
    int *arr;
    int tos;
    int size;
public :
    Stack ()                 // default constructor
    {
        tos = -1;
        size = 5;
        arr=new int[size];  // allocate fixed memory for stack in heap
    }

    Stack(int _size)        //parametric constructor that takes the size of the stack
    {
        size = _size;
        tos=-1;
        arr=new int [_size];   // allocate dynamic memory for stack in heap
    }


     Stack(const Stack &s)      //copy constructor
    {
        size = s.size;
        tos = s.tos;
        arr = new int[size];
        for (int i = 0; i <= tos; i++) {
            arr[i] = s.arr[i];  // Copy elements from the other stack
        }
    }

    void Push (int d)         //push function
    {
        if(tos<size-1)
        {
            tos++;
            arr[tos]=d;
        }
        else
            cout<<"\nstack is full! \n";
    }

    int pop(int &x)           //pop function
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

    void print ()             //print function
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
        delete [] arr;    //delete memory from the heap
        cout<<"\ndestructor...";
    }
};



int main()
{
    Stack s1 ;          // with default const. fixed size =5
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
    cout<<endl<<"fixed size stack :Stack1"<<endl;
    s1.print();


    Stack s2(10);          //with parametric constr. dynamic size =10
    cout<<endl<<"dynamic size stack :Stack2"<<endl;
    s2.Push(100);
    s2.Push(200);
    s2.Push(300);;
    s2.print();

    Stack s3 = s1;          //with copy constr.
    cout<<endl<<"Stack3 copied from stack1"<<endl;
    s3.print();
    return 0;
}
