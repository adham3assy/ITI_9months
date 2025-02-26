#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    //return 0;

    char ch ;
    do{
        printf("\nnew\ndisplay\nexit");
        _flushall();
        scanf("%c" , &ch);
        system("cls");
        switch(ch)
        {
        case 'n':
            printf("\nnew item selected");
            break;
        case 'd':
            printf("\ndisplay item selected");
            break;
        case 'e':
            printf("\nexit item selected");
            break;
        default :
            printf("\n wrong charachter");
            break;
         }
    }while(ch != 'e');

    return 0;
}
