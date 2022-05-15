#include <stdio.h>
#include <stdlib.h>

//C function to SWAP two arrays.


void swap_array(int* a1, int s1, int* a2, int s2)
{
    int temp = 0;
    int i = 0, s=0;
    if(s1 < s2)
    {
        s = s1;
    }
    else
    {
        s = s2;
    }
    for(i=0; i<s; ++i)
    {
        temp = a1[i];
        a1[i] = a2[i];
        a2[i] = temp;
    }
}

void print_array(int* a, int size)
{
    int i=0;
    for(i=0; i<size; ++i)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}


int main()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[6] =  {10,20,30,40,50,60};
    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);

    print_array(arr1, size1);
    print_array(arr2, size2);
    swap_array(arr1,size1, arr2, size2);
    print_array(arr1, size1);
    print_array(arr2, size2);

    return 0;
}