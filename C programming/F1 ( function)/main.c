#include <stdio.h>
#include <stdlib.h>
void myfactorial(int x);
int main()
{
    int x ;
    printf("Enter your number here : ");
    scanf("%d" , &x);
    myfactorial(x);

    return 0;
}

void myfactorial(int x)
{
    int i ;
    int factorial=1 ;

    for(i=1;i<=x;++i)
        {
          factorial *= i;
        }

    printf("factorial of %d = %d" , x , factorial);
}
