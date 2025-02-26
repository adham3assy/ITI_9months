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
     struct emp e1[3] ;
     for(int i=0;i<3;i++)
     {
        printf("Enter employee %d id : " ,i+1 );
        scanf("%d" ,&e1[i].id);
        printf("Enter employee %d name : " ,i+1);
        scanf("%s" ,e1[i].name);
        printf("Enter employee %d age : " ,i+1);
        scanf("%d" ,&e1[i].age);
     }
    for(int i=0;i<3;i++)
    {
        printf("employee %d id = %d\n" , i+1,e1[i].id);
        printf("employee %d name = %s\n" , i+1,e1[i].name);
        printf("employee %d age = %d\n" , i+1,e1[i].age);


    }
    return 0;
}
