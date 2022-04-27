#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    int x,y;
    int arr[4];
    printf("Address of arr[0] = %i\n", arr+0);
    printf("Address of arr[1] = %i\n", arr+1);
    printf("Address of arr[2] = %i\n", arr+2);
    printf("Address of arr[3] = %i\n", arr+3);
    puts("-------------------------------------");
    printf("Address of x = %i\n", &x);
    printf("Address of y = %i\n", &y);
    puts("-------------------------------------");
    printf("Address of arr[0] = %i\n", &arr[0]);
    printf("Address of arr[1] = %i\n", &arr[1]);
    printf("Address of arr[2] = %i\n", &arr[2]);
    printf("Address of arr[3] = %i\n", &arr[3]);
    puts("**************************************************");


    return 0;
}