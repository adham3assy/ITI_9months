#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size , i ;
    printf("Enter the size of the array here : ");
    scanf("%d" , &size);
    int* ptr = (int*)malloc(size * sizeof(int));
    if(ptr != NULL)
    {
        for(i=0;i<size;i++)
           {
                printf("Enter value no.%d here : " , i+1);
                scanf("%d" , &ptr[i]);
           }
        for(i=0;i<size;i++)
            printf("\nptr[%d]=%d" , i ,ptr[i]);
        free(ptr);
    }

    return 0;
}
