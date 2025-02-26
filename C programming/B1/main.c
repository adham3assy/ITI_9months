#include <stdio.h>
#include <stdlib.h>

int main()
{
  //  printf("Hello world!\n");
    //return 0;
    int degree ;

    printf("Enter your degree :");
    scanf("%d" , &degree);
    if ( degree > 85 )
    {
        printf("excellent");
    }
    else if(degree >= 75)
    {
        printf("very good");
    }
    else if(degree >= 65)
    {
        printf("good");
    }
    else if(degree >= 60)
    {
        printf("acceptable");
    }
    else
    {
        printf("fail");
    }
return 0 ;

}
