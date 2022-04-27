#include <stdio.h>
#include <stdlib.h>

/*(#define) perform text replacement not defining a new datatype. */
#define ptr int*
/*(typedef) creates a new datatype, not a text replacement*/
typedef int* def_ptr;

int main()
{
    puts("************************************************");
    int x = 50, y = 10;
    ptr z = &x, w = &y; // this line is equivelant to: (int* z = &x; int w = &y;), it means that 'z' is pointer to int, and 'w' is int.
    def_ptr f = &x, r = &y; // this line is equivelant to: (int* f = &x, int* r = &y;), it means that 'f' and 'r' both are pointer to int.
    printf("*z = %i\n", *z);
    //printf("*w = %i\n", *w);// error, because 'w' is an integer NOT a pointer to int.
    printf("w = %i\n", w);//prints address of 'y'
    printf("*f = %i\n", *f);
    printf("*r = %i\n", *r);
    puts("************************************************");
}