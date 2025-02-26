#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    //return 0;
    int x ;
    printf("Enter 1st number : ");
    scanf("%d" , &x);
    int y ;
    printf("Enter 2nd number : ");
    scanf("%d" , &y);
    int sum ;
    sum = x + y ;
    printf("sum = %d \n", sum);
    int sub ;
    sub = x - y ;
    printf("sub.= %d \n" , sub);
    int mult ;
    mult = x*y ;
     printf("mult.= %d \n" , mult);
    return 0 ;
}
