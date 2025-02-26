#include <stdio.h>
#include <stdlib.h>

int main()
{
   // printf("Hello world!\n");
    //return 0;
    int x ;
    int i ;
    int f =0 ;
    printf("Enter your number here : ");
    scanf("%d" , &x);
    if ( x < 2)
        printf("the number is not prime");
    for(i=2;i<x;i++)
       {  if (x%i==0){

            f = 1;
            break;
       }
       }
       if(f)
        printf("the number is not prime");
       else{
        printf("the number is prime");
       }
    return 0 ;

}
