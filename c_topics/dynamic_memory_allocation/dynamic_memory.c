#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short int uint16;
typedef unsigned long  int uint32;

/*there are 4 functions which are used in dynamic memory allocation: ( malloc(), calloc(), realloc(), free() ). */
/*these functions definition is located in <stdlib.h> */



int main()
{
    uint32 malloc_bytes;
    uint32 calloc_bytes;
    uint32 realloc_bytes;
    uint32 i;
    puts("************************************************\n");
    puts("--> Creating dynamic space during run-time using malloc() :\n");
    puts("Please enter number of characters in your name including spaces:");
    scanf("%u", &malloc_bytes);

        /***************************************************************************
        * malloc --> memory allocation.
        * malloc creates a single block of memory of the given size, and returns the address of first byte of it.
        * { void* malloc(int #ofBytes); } takes number of bytes, and returns address of first reserved byte. 
        * It returns (NULL or Zero) if there is now sufficient memory space.
        * you need to cast the address that malloc returned to use it as you want.
        ****************************************************************************/

    char *ptr;
    ptr = (char*) malloc( malloc_bytes*sizeof(char) );
    if( 0 == ptr)
    {
        puts("Sorry! NO sufficient memory to store your name.");
    }
    else
    {
        /************************************************************/
        /* Default values in locations created by malloc are garbage values. */
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        puts("Default values in locations created by malloc are garbage values.");
        puts("--> Printing default values in each memory location created by malloc:\n");
        for(i=0; i<malloc_bytes; ++i)
        {
            printf("\tByte[%i] = %i\n", i, *(ptr+i));
        }
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        /************************************************************/
        puts("Please enter your name:");
        fflush(stdin);
        gets(ptr);
        printf("\nYour name is: %s\n", ptr);
    }

    puts("----------------------------------------------------------");


    puts("--> Creating dynamic space during run-time using calloc() :");
    puts("--> calloc() is used to create array of given size during run-time.\n");
    puts("Please enter number of elements for an array of short elements (each element is 2 bytes size):");
    scanf("%u", &calloc_bytes);
        /***************************************************************************
        * calloc --> contiguous allocation.
        * calloc creates multiple block of memory of the same size "like array", and then sets all locations to zero.
        * { void* calloc(int #ofElements, int sizeOfElement) takes number of elements, and size of one element, then returns address of first reserved byte. 
        * It returns (NULL or Zero) if there is now sufficient memory space.
        * you need to cast the address that calloc returned to use it as you want.
        *
        ****************************************************************************/
    uint16 *arr;
    arr = (uint16*) calloc(calloc_bytes, sizeof(uint16));
    if( 0 == arr)
    {
        puts("Sorry! NO sufficient memory.");
    }
    else
    {
        /************************************************************/
        /* Default values in locations created by calloc are zeros values. */
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        puts("Default values in locations created by calloc are zeros values.");
        puts("--> Printing default values in each memory location created by calloc:\n");
        for(i=0; i<calloc_bytes; ++i)
        {
            printf("\tByte[%i] = %i\n", i, *(arr+i));
        }
        puts("----\t----\t----\t----\t----\t----\t----\t----\t----\t----");
        /************************************************************/
        puts("Please enter array elements:");
        for(i=0; i<calloc_bytes; ++i)
        {
            scanf("%hu", (arr+i));
        }
        printf("Array is: {");
        for(i=0; i<calloc_bytes; ++i)
        {
            printf(" %hu,", *(arr+i) );
        }
        puts("\b }");
    }

    puts("----------------------------------------------------------");

    puts("--> Resizing dynamic space during run-time using realloc() :");
    puts("--> realloc() is used to resize memory location during run-time.\n");
    puts("Please enter new size of your name in bytes:");
    scanf("%u", &realloc_bytes);
        /***************************************************************************
        * realloc() resizes memory space to the new given size, and returns the address of first byte of it.
        * { void* realloc(void* ptr, int newSize); } takes pointer to memory space, and new number of bytes, then returns address of first reserved byte. 
        * It returns (NULL or Zero) if there is now sufficient memory space.
        * you need to cast the address that realloc returned to use it as you want.
        ****************************************************************************/
    char *ptr2;
    ptr2 = (char*) realloc(ptr, realloc_bytes*sizeof(char) );

    if( 0 == ptr2)
    {
        puts("Sorry! NO sufficient memory to store your name.");
    }
    else
    {
        ptr = ptr2;
        puts("Please enter your new name:");
        fflush(stdin);
        gets(ptr);
        printf("\nYour name is: %s\n", ptr);
    }

    

    puts("************************************************");
    return 0;
}
