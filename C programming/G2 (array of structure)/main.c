#include <stdio.h>
#include <stdlib.h>


struct emp
{
    int id ;
    char name[30];
    int age ;
};


int main()
{
    struct emp e1 ;
     int size , i ;
    printf("Enter the no. of employees here : ");
    scanf("%d" , &size);
    struct emp* ptr = (struct emp*)malloc(size * sizeof(struct emp));
    if(ptr != NULL)
    {
        for(i=0;i<size;i++)
           {
                printf("Enter id value of employee %d here : " , i+1);
                scanf("%d" , &ptr[i].id);
                printf("Enter name of employee %d here : " , i+1);
                scanf("%s" , ptr[i].name);
                printf("Enter age of employee %d here : " , i+1);
                scanf("%d" , &ptr[i].age);
           }
        for(i=0;i<size;i++)
            printf("\nEmployee %d -> id is %d : name is %s : age is %d" , i+1 , (ptr+i)->id ,(ptr+i)->name , (ptr+i)->age);
        free(ptr);
    }
    return 0;
}
