#include <stdio.h>
#include <stdlib.h>

int i;

//we recive array in pointer to int, because name of the array is pointer to int;
void sum_arrays(int *ptr1, int *ptr2, int *ptr3, int size);


int main()
{
    puts("**************************************************");
    int arr1[5] = {10,20,30,40,50};
    int arr2[5] = {10,20,30,40,50};
    int arr3[5];
    sum_arrays(arr1, arr2, arr3, (sizeof(arr1)/sizeof(int)));
    puts("arr1\tarr2\tsum of row");
    for(i=0; i<(sizeof(arr1)/sizeof(int)); ++i)
    {
        printf("%i\t%i\t%i\t\n", arr1[i], arr2[i], arr3[i]);
    }
 
    puts("**************************************************");


    return 0;
}

void sum_arrays(int *ptr1, int *ptr2, int *ptr3, int size)
{
    for(i=0; i<size; ++i)
    {
        ptr3[i] = ptr1[i] + ptr2[i];
    }
}