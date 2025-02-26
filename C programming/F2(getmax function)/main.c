#include <stdio.h>
#include <stdlib.h>
int getmax(int x , int y);

int main()
{
    int a;
    int b;
    printf("Enter the 2 numbers here : \n" , a , b);
    scanf("%d %d" , &a ,&b);
    int z = getmax(a,b);
    printf("max = %d" , z);
    return 0;
}

int getmax(int x , int y)
{
    return
        x>y?x:y;
}
