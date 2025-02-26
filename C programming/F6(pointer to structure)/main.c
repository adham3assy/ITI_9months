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
    struct emp e1;
    struct emp *ptr =&e1;
    printf("Enter employee id here : ");
    scanf("%d" , &(ptr->id));
    printf("Enter employee name here : ");
    scanf("%s" , ptr->name);
    printf("Enter employee age here : ");
    scanf("%d" , &(ptr->age));
    printf("\n");

    printf(" employee id is %d\n employee name is %s\n employee age is %d\n" ,ptr->id , ptr->name , ptr->age );
    return 0;
}
