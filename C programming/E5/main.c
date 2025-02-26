#include <stdio.h>
#include <stdlib.h>

struct numbers
{
    int rare ;
    int complex ;
};


int main()
{
    struct numbers num ;
    printf("Enter the 1st value :");
    scanf("%d" , &(num.rare));
    printf("Enter the 2nd value :");
    scanf("%d" , &(num.complex));
    printf("the number  is : %d + %di\n" , num.rare , num.complex);
    return 0;
}
