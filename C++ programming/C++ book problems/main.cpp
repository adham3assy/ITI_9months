#include <iostream>

using namespace std;

int add(int a, int b = 0, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int add(int a = 0, int b , int c = 0, int d = 0){//error default arguments must be at the end
    return a + b + c + d;

}

/*int add(int a)//error ambiguous
{
    return a;
} */

int main(){
    add(5,5);
    return 0 ;
}
