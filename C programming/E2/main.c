#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max ;
    int i ;
    int flag =0 ;
    printf("Enter your number here : ");
    scanf("%d" , &max);
    printf("the prime number < %d is : " , max);

    for(i=2;i<max;i++)

       {    flag = 1;
            for(int j =2;j<=i/2 ;j++)
                {
                    if(i%j==0){
                        flag=0;
                        break;}

                }

          if(flag)
            printf("%d " , i);
       }



    printf("\n");
    return 0;
}
