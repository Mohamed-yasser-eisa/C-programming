#include <stdio.h>
#include <stdlib.h>

// C function to print array elements using pointer.

void print_array(int* ptr, int size)
{
    int i = 0;
    for(i=0; i<size; ++i)
    {
        printf("%i ", ptr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};

    print_array(arr, sizeof(arr)/sizeof(int));
    return 0;
}