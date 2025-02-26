#include <stdio.h>
#include <stdlib.h>
void scanarray(int arr[] ,int s );
int getsum(int arr[], int n);
void printarray(int arr[] , int j);


int main()
{

    int arr[5];
    scanarray(arr,5);
    printf("my array = \n");
    for(int i =0;i<5;i++)
    printf("%d\n" , arr[i]);
    int r =getsum(arr , 5);
    printf("sum = %d\n" , r);
    printarray(arr , 5);
    return 0;
}

void scanarray(int arr[] ,int s )
{
    printf("Enter your numbers here: \n");
    for(int i=0;i<s;i++)
        scanf("%d" , &arr[i]);
}

int getsum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}

void printarray(int arr[] , int j)
{
    printf("my array = \n");
    for(int i=0;i<j;i++)
        printf("%d\n" , arr[i]);
}



