#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    unsigned int x:3;
    signed int y:3;
}CAR;



int main()
{
    puts("************************************************");
    /* when an overflow occures then first 3 bits only will be stored in 'x'. */
    /* in case of signed bit field variables, the MSB is used as a signe bit. */

    CAR c1;

    c1.x = 5;
    printf("c1.x = %i\n", c1.x);
    c1.y = 5;
    printf("c1.y = %i\n", c1.y);

    puts("----\t----\t----\t----");

    c1.x = 8;
    printf("c1.x = %i\n", c1.x);
    c1.y = 8;
    printf("c1.y = %i\n", c1.y);

    puts("----\t----\t----\t----");

    c1.x = 6;
    printf("c1.x = %i\n", c1.x);
    c1.y = 6;
    printf("c1.y = %i\n", c1.y);

    puts("----\t----\t----\t----");

    c1.x = 16;
    printf("c1.x = %i\n", c1.x);
    c1.y = 16;
    printf("c1.y = %i\n", c1.y);



    puts("************************************************");
    return 0;
}