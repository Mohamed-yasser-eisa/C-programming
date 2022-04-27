#include <stdio.h>
#include <stdlib.h>

typedef signed long long int sint64;

sint64 add_number(int x, int y);
double div_number(float x, float y);


/*when you use typedef with pointer to function, then pointer name is a new datatype of type: "pointer to function" */

typedef sint64 (*ptr_add)(int, int);//now ptr_add is a datatype of type pointer to function takes two int, returns sint64.
typedef double (*ptr_div)(float, float);//now ptr_div is a datatype of type pointer to function takes two floats, rteurns double.


int main()
{
    puts("************************************************");
    printf("size of long long int = %i bytes\n", sizeof(long long int));
    
    puts("-----------------------------------------------------------");
    ptr_add add; /* "add" is pointer to function */
    add = &add_number;
    sint64 result;
    result = add(1054163, 6045480);
    printf("1054163 + 6045480 = %lld\n", result);

    puts("-----------------------------------------------------------");
    ptr_div div; /* "div" is pointer to function */
    div = &div_number;
    double output;
    output = div(5642.56, 145.36);
    printf("5642.56 + 145.36 = %f\n", output);

    puts("************************************************");
    return 0;
}


sint64 add_number(int x, int y)
{
    return ( (sint64) x + (sint64) y );
}

double div_number(float x, float y)
{
    return ( (double) x / (double) y );
}