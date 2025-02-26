#include <iostream>
#include <string.h>

using namespace std;

class String
{
    int size;
    char *arr;

public:

    String()                   // default constructor with size 10
    {
        int size = 10;
        arr = new char[size];
        arr[0] = '\0';         // initializes array as empty string
    }


    String(int _size)          // parametric constructor that takes size
    {
        int size = _size;
        arr = new char[size];
        arr[0] = '\0';
    }


    String(const char *name)         // parametric constructor that takes size of string and 10 on it , and takes string
    {
        size = strlen(name) + 10;
        arr = new char[size];
        strcpy(arr , name);
    }


    String (const String &c)   // Copy constructor
    {
        size = c.size;
        arr = new char[size];
        strcpy(arr , c.arr);
    }


    void setString(const char *s)     // Setter
    {
       int len = strlen(s);
       if(len < size)
        strcpy(arr , s);
       else
       {
           delete[] arr;
           size = len + 10;
           arr=new char[size];
           strcpy(arr , s);
       }
    }
    const char* getString()const{     // Getter
        return arr;
    }


    String &operator=(const String &s)      // = Assignment operator
    {
        if(this == &s)
           {
                return *this;
           }
        delete[] arr;
        size = s.size;
        arr = new char[size];
        strcpy(arr , s.arr);
        return *this;
    }


    String operator+(const String &s)       // + operator
    {
        int newsize = strlen(arr) + strlen(s.arr) + 1;    //combining the sizes of the 2 strings +1 for the /0
        String result(newsize);                           // putting the new size in the new array
        strcpy(result.arr , arr);                         // putting the 1st string in the new array
        strcat(result.arr , s.arr);                       // putting the 2nd string in the new array
        return result;
    }

    void print()              //print function
    {
        cout<<endl<<arr<<endl;
    }

    ~String()
    {                  // Destructor
        delete [] arr;
        cout<<endl<<"destructor is called.."<<endl;
    }
};

int main()
{
    String s , s1(30) , s2("Ahmed");

    cout<<endl<<"default S : ";
    s.print();             // default constr.

    cout<<endl<<"S1 : ";
    s1.print();            // parametric constr. takes size = 30

    cout<<endl<<"S2 : ";
    s2.print();            // parametric constr. that takes string and increase size of string by 10

    String s3 = s2;        // copy constr.
    cout<<endl<<"S3 copy of S2 : ";
    s3.print();

    s.setString("Adham");      // Using setter
    s1.setString("Assy");
    cout<<endl<<"Using my setters S: ";
    s.print();
    cout<<endl<<"Using my setters S1: ";
    s1.print();

    s1 = s2;
    cout<<endl<<"Assigning S2 to S1 : ";    // = operator
    s1.print();

    String s4("Hello ") , s5("World !");
    String s6 = s4 + s5;                    // + operator , adding 2 strings
    cout<<endl<<"Concatenating two strings : ";
    s6.print();

    return 0;
}
