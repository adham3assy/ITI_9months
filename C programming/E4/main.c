#include <stdio.h>
#include <stdlib.h>

struct  points
{
    int x ;
    int y ;

};

int main()
{
    struct points pts ;
    printf("Enter x value: ");
    scanf("%d" , &(pts.x));
    printf("Enter y value : ");
    scanf("%d" , &(pts.y));
    printf("x is : %d\ny is : %d\n " ,pts.x , pts.y );
    return 0;
}
