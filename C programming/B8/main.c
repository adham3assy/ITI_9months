#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    //return 0;
    int x  ;
    int rev = 0 ;
    printf("Enter the number here : ");
    scanf("%d" , &x);
    while(x != 0)
    {
        rev = x % 10;
        printf("%d" , rev );
        x = x/10;
    }
    return 0 ;
}
