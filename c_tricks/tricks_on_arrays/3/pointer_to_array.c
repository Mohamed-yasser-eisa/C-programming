#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    int arr[4] = {10,20,30,40};
    int (*ptr)[4] = &arr;

    printf("ptr         = %i\n", ptr);//address of array, and ptr is a pointer to array
    printf("*ptr        = %i\n", *ptr);//address of array, and ptr is a pointer to int
    printf("**ptr       = %i\n", **ptr);//first element in the array
    printf("ptr+1       = %i\n", ptr+1);//step = array size
    printf("*ptr+1      = %i\n", *ptr+1);//step = int size
    printf("*(ptr+1)    = %i\n", *(ptr+1));//address location next the end of the array
    printf("*((*ptr)+1) = %i\n", *((*ptr)+1));//second element in the array
    puts("**************************************************");


    return 0;
}