#include <stdio.h>
#include <stdlib.h>
void swap(int*x , int*y);

int main()
{
    int a,b ;
    printf("Enter the number of a here : " , a);
    scanf("%d" ,&a);
    printf("Enter the number of b here : " , b);
    scanf("%d" ,&b);
    swap(&a,&b);
    printf("a=%d\nb=%d\n" , a,b);
    /*int a =100;
    int b =50;
    swap(&a,&b);
    printf("a=%d\nb=%d\n" , a,b);*/
    return 0;
}

void swap(int* x , int *y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}
