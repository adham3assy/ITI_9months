#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] ;
    int *ptr = arr ;
    int i =0;
    printf("Enter your values here : \n");
    for(i=0;i<4;i++)
    {
        scanf("%d" , ptr + i);
        printf("number is : %d \n" , *(ptr + i));
    }
    return 0;
}
