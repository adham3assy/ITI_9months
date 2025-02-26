#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    int id ;
    char name[30];
    int age ;
};

int main()
{
     struct emp e1 ;


    printf("Enter your id here : ");
    scanf("%d" ,&(e1.id));
    printf("Enter your name here : ");
    scanf("%s" ,&(e1.name));
    printf("Enter your age here : ");
    scanf("%d" ,&(e1.age));
    printf(" id is :%d\n name is : %s\n age is : %d\n " , e1.id , e1.name , e1.age);
    return 0;
}
