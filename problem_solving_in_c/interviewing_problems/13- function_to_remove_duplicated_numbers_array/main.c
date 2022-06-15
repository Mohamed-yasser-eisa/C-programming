#include <stdio.h>
#include <stdlib.h>

//C function to remove the duplicated numbers in an array
//assume the array is sorted (if not sorted use bubble sorting to sort it first)

void remove_duplicated(int* ptr, int size)
{
    int i=0,j=0;
    int temp[10] = {0};
    temp[j] = ptr[i];
    for(i=0; i<size; ++i)
    {
        if(ptr[i] != temp[j])
        {
            temp[j+1] = ptr[i];
            ++j;
        }
    }
    for(i=0; i<size; ++i)
    {
        ptr[i] = temp[i];
    }
}


int main()
{
    int i=0;
    int arr[10] = {1,2,3,3,3,4,4,4,5,6};
    remove_duplicated(arr, sizeof(arr)/sizeof(int) );
    for(i=0; arr[i]!=0; ++i)
    {
        printf("%i, ", arr[i]);
    }
    puts("");
	return 0;
}
