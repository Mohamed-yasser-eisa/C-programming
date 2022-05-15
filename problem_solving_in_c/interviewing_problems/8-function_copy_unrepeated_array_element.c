#include <stdio.h>
#include <stdlib.h>



// C function to copy an array of char (contains repeated numbers) to a new 
// array excluding the repeated numbers using only one loop O(n). (array is sorted)


void print_array(int* ptr, int size)
{
    int i = 0;
    for(i=0; i<size; ++i)
    {
        printf("%i ", ptr[i]);
    }
    printf("\n");
}


void copy_unrepeated(int* p1, int* p2, int size)
{
    int i = 0, j = 0;
    for(i=0,j=0; i<size; ++i)
    {
        if(p1[i] != p1[i+1])
        {
            p2[j] = p1[i];
            ++j;
        }
    }
    print_array(p2, j);
}



int main()
{
    int arr1[10] = {1,1,1,2,3,3,4,5,6,6};
    int arr2[10] = {'\0'};
    print_array(arr1, 10);
    copy_unrepeated(arr1, arr2, 10);
    
    return 0;
}