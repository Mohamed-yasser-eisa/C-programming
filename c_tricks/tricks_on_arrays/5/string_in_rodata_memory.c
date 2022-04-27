#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    printf("%i\n", 'a');//ASCI of 'a'.
    printf("%i\n", "a");//address of first byte of "string" in .rodata.
    printf("sizeof(\"a\") = %i\n", sizeof("a"));//size = string + NULL
    printf("%i\n", "Hello");
    printf("%i\n", "Hello"+1);//add one to pointer to char
    printf("%i\n", "Hello"+2);//add two to pointer to char
    printf("%c\n", *("Hello"));//dereference first address = character in that address
    printf("%c\n", *("Hello"+4));//dereference first address = character in that address

    /*dereference operator with "string": */
    puts("-->Dereference operator with \"string\":");
    printf("%s\n", "Ali");
    printf("%c\n", *("Ali"));
    printf("%i\n", *("Ali"));
    printf("%c\n", *("Ali"+2));
    printf("%i\n", *("Ali"+2));

    
    puts("**************************************************");
    return 0;
}