#include <iostream>

using namespace std;

class SerialNumber {
    int serialNumber;
    static int Count;
public:

    SerialNumber()
    {
        serialNumber = ++Count;
    }


    void display() const
    {
        cout << "Serial Number: " << serialNumber << endl;
    }
};


int SerialNumber::Count = 0;

int main() {
    SerialNumber s1;
    s1.display();

    SerialNumber s2;
    s2.display();

    SerialNumber s3;
    s3.display();

    return 0;
}
