#include <stdio.h>
#include <stdlib.h>

int main()
{
   // printf("Hello world!\n");
    //return 0;
    int x ;
    int i ;
    int factorial=1 ;
    printf("Enter your number here : ");
    scanf("%d" , &x);
    for(i=1;i<=x;++i)
        {
          factorial *= i;
        }

    printf("factorial of %d = %d" , x , factorial);

    return 0 ;

}

