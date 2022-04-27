#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("****************************************************************");
    int *ptr;
    int x = 255;
    int y;
    ptr = &x;

    printf("ptr = %p\n", ptr);
    printf("&x  = %p\n", &x);
    printf("&y  = %p\n", &y);
    printf("x   = %i\n", x);
    printf("y   = %i\n", y);
    puts("-----------------------------------------------------------------");
    y = *ptr++;

    printf("ptr = %p\n", ptr);
    printf("&x  = %p\n", &x);
    printf("x   = %i\n", x);
    printf("y   = %i\n", y);
    printf("*ptr= %i\n", *ptr);
    puts("-----------------------------------------------------------------");
    ptr = &x;
    y = *++ptr;

    printf("ptr = %p\n", ptr);
    printf("x   = %i\n", x);
    printf("y   = %i\n", y);
    printf("*ptr= %i\n", *ptr);
    puts("-----------------------------------------------------------------");
    ptr = &x;
    (*ptr)++;

    printf("The value in ptr = %p\n", ptr);
    printf("&x               = %p\n", &x);
    printf("x                = %i\n", x);
    puts("****************************************************************");
    gets((char*)ptr);//wait user enter any char the exit
    return 0;
}