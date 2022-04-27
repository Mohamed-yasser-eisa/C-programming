#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    
    /* Name of two dimention array, is a pointer to inner array */
    /* When you dereference (*) two_dimentional_array_name once it becomes pointer to element */
    /* When you dereference (*) two_dimentional_array_name twice it returns value of element */

    int array[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
    int i,j;

    for(i=0; i<3; ++i)
    {
        for(j=0; j<5; ++j)
        {
            printf("array [%i][%i] = %i\n", i,j, array[i][j]);
        }
    }

    puts("---------------------------------------------------------");
    printf("**array         = %i\n", **array );
    printf("**(array+1)     = %i\n", **(array+1) );
    printf("*(*(array+1)+1) = %i\n", *(*(array+1)+1) );
    printf("*(*array+2)+4   = %i\n", *(*(array+2)+4) );
    




    puts("**************************************************");
    gets((char*)array);
    return 0;
}
