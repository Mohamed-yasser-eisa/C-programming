#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    unsigned int x:3;
}CAR;



int main()
{
    puts("************************************************");
    /* when an overflow occures then first 3 bits only will be stored in 'x'. */

    CAR c1;
    c1.x = 5;
    printf("c1.x = %i\n", c1.x);
    c1.x = 6;
    printf("c1.x = %i\n", c1.x);
    c1.x = 8;
    printf("c1.x = %i\n", c1.x);
    c1.x = 16;
    printf("c1.x = %i\n", c1.x);



    puts("************************************************");
    return 0;
}