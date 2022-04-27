#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    unsigned char x:3;
    unsigned char y:6;
    unsigned char z:3;
}CAR;


int main()
{
    puts("************************************************************************************************");
    /*when you create bit field variable with size > size of datatype, then compiler will use another location of
    size = datatype size to store the variable. */

    /*the compiler may store part from the variable in the current free bits and store rest in next location.
    Or it may store the whole variable in the next location.*/

    /*this pehavior is compiler dependent. */

    CAR c1;
    char* ptr;
    c1.x = 5;
    c1.y = 9;
    c1.z = 7;

    printf("size of c1 = %i bytes\n", sizeof(c1));
    ptr = (char*)&c1; //pointer points to first byte.
    printf("ptr[0] = %i\n", ptr[0]);
    ptr += 1; //pointer points to second byte.
    printf("ptr[1] = %i\n", ptr[1]);
    ptr += 1; //pointer points to third byte.
    printf("ptr[2] = %i\n", ptr[2]);




    puts("************************************************************************************************");
    return 0;
}