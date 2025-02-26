#include <iostream>

using namespace std;

void swap(int& x ,int& y )
{
    int temp = x;
    x=y;
    y=temp;
}
int main()
{
    int x ,y ;
    cout<<"Enter the value of X : ";
    cin>>x;
    cout<<"Enter the value of Y : ";
    cin>>y;
    swap(x,y);
    cout<<"X= "<<x<<"  :  "<<"Y= "<<y;
    return 0;
}
