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


    Stack operator+ (Stack &s)   // operator overloading for "+" to add two stacks
    {
        Stack result(size + s.size);   //new stack with sum of the sizes
        int i=0;
        while(i<=tos)
        {
            result.Push(this -> arr[i]);       //copy elements of first stack
            i++;
        }
        int j=0;
        while(j<=tos)
        {
            result.Push(s.arr[j]);      //copy elements of second stack
            j++;
        }
        return result;     // result = stack1 + stack2
    }


    int operator==(const Stack &s)     // bool equal operator
    {
        if(tos != s.tos)              //checking the size
            return false;
        else
        {
            for(int i=0;i<=tos;i++)
            {
                if(arr[i] != s.arr[i])       // Comparing the elements of the two Stacks
                {
                    return false;            //if there are two elements not equal exit loop and return false
                }

            }
            return true ;
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
    Stack s1 ;          // with default const. size =5
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
    cout<<endl<<"Stack1: "<<endl;
    s1.print();


    Stack s2(10);          //with parametric constr. dynamic size =10
    cout<<endl<<"Stack2: "<<endl;
    s2.Push(100);
    s2.Push(200);
    s2.Push(300);;
    s2.print();

    Stack s3 = s1;          //with copy constr.
    cout<<endl<<"Stack3 copied from stack1 : "<<endl;
    s3.print();

    Stack s4 = s2 + s1 ;
    cout<<endl<<"Stack4 = Stack2 + Stack1 : "<<endl;
    s4.print();

    if(s1 == s2 )
        cout<<endl<<"Stack1 and Stack2 are equal!"<<endl;
    else
        cout<<endl<<"Stack1 and Stack2 are not equal!"<<endl;

    if(s1 == s3 )
        cout<<endl<<"Stack1 and Stack3 are equal!"<<endl;
    else
        cout<<endl<<"Stack1 and Stack3 are not equal!"<<endl;
    return 0;
}
