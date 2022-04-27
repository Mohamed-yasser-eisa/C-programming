#include <stdio.h>
#include <stdlib.h>

void array_sort(int *ptr, int size);


int main()
{
    puts("**************************************************");
    int array[5];
    int i=0;
    puts("Please enter 5 array elements to sort them in ascending order:\n");

    /*scan array elements:*/
    for(i=0; i<5; ++i)
    {
        scanf("%i", &array[i]);
    }

    /*print array elements*/
    printf("Array elements: ( ");
    for(i=0; i<5; ++i)
    {
        printf("%i, ", *(array + i) );
    }
    puts("\b\b )\n\n");

    /*sort array elements*/
    array_sort(array, (sizeof(array)/sizeof(int)) );

    /*print sorted array*/
    printf("Sorted array: ( ");
    for(i=0; i<5; ++i)
    {
        printf("%i, ", *(array + i) );
    }
    puts("\b\b )");

    puts("**************************************************");
    fflush(stdin);
    gets((char*)array);
    return 0;
}


void array_sort(int *ptr, int size)
{
    int min = 0;
    int i = 0;
    int j=0;
    int index=0;
    
    
    for(i=0; i<size-1; ++i)
    {
        min = ptr[i];//assume current element is the minumum
        j = i+1;
        for(j; j<size; ++j) //compare min with other elements for a smaller element
        {
            if(ptr[j] < min)
            {
                min = ptr[j];
                index = j;
            }
        }
        if(ptr[i] != min)//if min didn't change, then don't swap.
        {
            ptr[i] = ptr[i] ^ ptr[index];
            ptr[index] = ptr[i] ^ ptr[index];
            ptr[i] = ptr[i] ^ ptr[index];
        }
    }
}
