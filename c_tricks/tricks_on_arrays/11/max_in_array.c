#include <stdio.h>
#include <stdlib.h>

int array_max(int *ptr, int size);


int main()
{
    puts("**************************************************");
    int array[5];
    int i=0;
    puts("Please enter 5 array elements to find max number of them:\n");
    for(i=0; i<5; ++i)
    {
        scanf("%i", &array[i]);
    }
    printf("Array elements: ( ");
    for(i=0; i<5; ++i)
    {
        printf("%i, ", *(array + i) );
    }
    puts("\b\b )");
    
    printf("Maximum number = %i\n", array_max(array, (sizeof(array)/sizeof(int)) ) );



    puts("**************************************************");
    fflush(stdin);
    gets((char*)array);
    return 0;
}


int array_max(int *ptr, int size)
{
    int max = 0;
    int i = 0;
    
    for(i=0; i<size; ++i)
    {
        if(max < ptr[i] )
        {
            max = ptr[i];
        }
    }
    return max;
}
