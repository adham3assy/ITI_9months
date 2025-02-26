#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    //return 0;
    int x ;
    int y ;
    char op ;

    scanf("%d \n" , &x); //take the 1st number
    scanf(" %c \n" , &op); //take the operator
    scanf("%d" , &y);  //take the 2nd number

switch(op)
{


    case'+':
    {
        printf("%d + %d = %d" , x , y , x+y);
    }
         break;
    case '-' :
    {
        printf("%d - %d = %d" , x , y , x-y);

    }
         break;
    case '*':
    {
        printf("%d * %d = %d" , x , y , x*y);

    }
         break;
    case '/':
    {
        printf("%d / %d = %d" , x , y , x/y);

    }
         break;
}
    return 0 ;
}
