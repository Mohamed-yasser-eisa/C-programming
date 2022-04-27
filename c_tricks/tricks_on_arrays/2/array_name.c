#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    int arr[4];
    printf("arr    = %i\n", arr);//array name is a pointer to first element in the array, arr is pointer to int.
    printf("&arr   = %i\n", &arr);//&arr is a pointer to whole array.
    printf("arr+1  = %i\n", arr+1);//step of pointer to int = 4 bytes.
    printf("&arr+1 = %i\n", &arr+1);//step of pointer to array = (array size) bytes.
    puts("**************************************************");


    return 0;
}