#include <stdio.h>
#include <stdlib.h>

//C function to remove the duplicated numbers in an unsorted array


void remove_duplicated(int* ptr)
{
    int i=0,j=0,k=0;
    int temp[10] = {0};
    temp[k] = ptr[i];
    /*sort array using bubble sort*/
    for(i=0; i<9; ++i)
    {
        for(j=0; j<10-1-i; ++j)
        {
            if(ptr[j])
        }
    }

    for(i=0; i<10; ++i)
    {
        for(j=i+1; j<10; ++j)
        {
            if(ptr[i] != temp[k])
            {
                temp[k] = ptr[i];
                ++j;
            }
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
