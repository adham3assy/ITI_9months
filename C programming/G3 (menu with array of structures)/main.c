#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#define null -32

void textattr(int i)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

  struct emp                                          //employee structure
  {
      int id ;
      char name[30] ;
      int age ;
  };


  void addemployee (struct emp e1[] , int *count)     // this function is to add new employee
  {
      system("cls");
      printf("Enter employee id : ");
      scanf("%d" , &e1[*count].id);
      printf("Enter employee name : ");
      scanf("%s" , e1[*count].name);
      printf("Enter employee age : ");
      scanf("%d" , &e1[*count].age);
      (*count)++;
      printf("Employee added successfully! \n");
      _getch();
  }


  void displayall (struct emp e1[] , int count)        //function that display all employees
  {
      system("cls");
      for(int i=0;i<count;i++)
      {
          printf("Employee ID  : %d\n" , e1[i].id);
          printf("Employee Name: %s\n" , e1[i].name);
          printf("Employee Age : %d\n\n\n" , e1[i].age);
      }
      _getch();
  }


  void displaybyid (struct emp e1[] , int count)        //function to display employee by ID
  {
      int id ;
      system("cls");
      printf("Enter the employee ID : ");
      scanf("%d" , &id);
      for(int i=0;i<count;i++)
      {
            if(e1[i].id == id)
            {
                printf("Employee ID  : %d\n" , e1[i].id);
                printf("Employee Name: %s\n" , e1[i].name);
                printf("Employee Age : %d\n" , e1[i].age);
                _getch();
                return ;
            }
      }
      printf("Employee not found!");
      _getch();
  }


  void displaybyname (struct emp e1[] , int count)      //function to display employee by name
  {
      char name[30];
      system("cls");
      printf("Enter the employee name : ");
      scanf("%s" , name);
      for(int i=0;i<count;i++)
      {
          if(strcmp(e1[i].name , name ) == 0)
          {
              printf("Employee ID  : %d\n" , e1[i].id);
              printf("Employee Name: %s\n" , e1[i].name);
              printf("Employee Age : %d\n" , e1[i].age);
              _getch();
              return ;
          }
      }
      printf("Employee not found!");
      _getch();
  }

int main()
{
    struct emp e1[50] ;    //array of employees structure
    int empcount=0 ;       //index of the employees
    char menu [5][20]= {"new", "display all" , "display by id" ,"display by name" ,"exit"};
    char ch;               //key pressed by the user
    int n=0;               // curenttly selected menu item
    int i;
    int flag = 0;          // the loop continues while flag=0 , breaks while flag=1

    do{
        system("cls");
        for (i=0;i<5;i++){
            gotoxy(10,10+i);
            if (i==n)                // --> the loop that prints the menu
                textattr(0x74);
            printf("%s",menu[i]);
           textattr(0x07);}


       ch = _getch(); // get the user key press

        switch (ch) {
            case -32:
                ch = _getch();
                switch (ch) {
                    case 72: // up arrow key
                        n--;
                        if (n < 0)
                            n = 4;
                        break;
                    case 80: // down arrow key
                        n++;
                        if (n > 4)
                            n = 0;
                        break;
                }
                break;
            case 13:         // Enter key
                system("cls");
                if (n == 0)
                    addemployee(e1 , &empcount);
                else if (n == 1)
                    displayall(e1 , empcount);
                else if (n == 2)
                    displaybyid(e1 , empcount);
                else if (n == 3)
                    displaybyname(e1 , empcount);
                else if (n == 4)
                    {
                        printf("exitting..\n");
                        flag = 1;
                    }
                break;

            case 27: // escape key
                flag = 1;
                break;
        }
    } while (flag == 0);

    return 0;
}

