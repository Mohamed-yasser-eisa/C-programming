#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    unsigned short malloc_bytes;
    unsigned short realloc_bytes;
    unsigned short i;
    puts("************************************************\n");
    puts("--> Creating dynamic space during run-time using malloc() :\n");
    puts("Please enter number of bytes:");
    scanf("%hu", &malloc_bytes);
    char *ptr;
    ptr = (char*) malloc( malloc_bytes*sizeof(char) );
    if( 0 == ptr)
    {
        puts("Sorry! NO sufficient memory.");
    }
    else
    {
        /************************************************************/
        /* Default values in locations created by malloc are garbage values. */
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        puts("--> Printing default values in each memory location created by malloc:\n");
        for(i=0; i<malloc_bytes; ++i)
        {
            printf("\tByte[%i] = %i\n", i, *(ptr+i));
        }
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        /************************************************************/
        printf("&ptr[0] = %i\n", ptr);
    }

    puts("-------------------------------------------------------------------------------------");

    puts("--> Resizing dynamic space during run-time using realloc() :");
    puts("--> realloc() is used to resize memory location during run-time.\n");
    puts("Please enter new size of in bytes:");
    scanf("%u", &realloc_bytes);
    char *ptr2;
    ptr2 = (char*) realloc(ptr, realloc_bytes*sizeof(char) );

    if( 0 == ptr2)
    {
        puts("Sorry! NO sufficient memory.");
    }
    else
    {
        /************************************************************/
        /* Default values in locations created by malloc are garbage values. */
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        puts("--> Printing values in each memory location created by realloc:\n");
        for(i=0; i<(malloc_bytes+15); ++i)
        {
            printf("\tByte[%i] = %i\n", i, *(ptr+i));
        }
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        /************************************************************/
        ptr = ptr2;
        printf("&ptr[0] = %i\n", ptr);
        
    }

    

    puts("************************************************");
    return 0;
}