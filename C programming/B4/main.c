#include <stdio.h>
#include <stdlib.h>

int main()
{
  //  printf("Hello world!\n");
    //return 0;
    int x ;
    int sum ;
    int i ;
    sum = 0;
    for(i=0;i<5;i++)
       {
        printf("Enter the number here : ");
        scanf("%d" , &x);
        sum+=x ;
       }
    printf("their sum = %d", sum);

}
