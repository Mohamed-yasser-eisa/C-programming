#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
    int x;
    int y;
}f = {10,22};

struct bus
{
    short num;
    struct car c;
};



int i=0;





int main()
{
    puts("**************************************************");
    puts("It's allowed to create nested struct, but NOT of the same struct type\n");

    struct bus bs;
    bs.num = 1010;
    bs.c.x = 12;
    bs.c.y = 1341;
    printf("bs.num = %hu\n", bs.num);
    printf("bs.c.x = %i\n", bs.c.x);
    printf("bs.c.y = %i\n", bs.c.y);

    puts("Using pointers with nested struct");
    struct bus *ptr = &bs;
    printf("ptr -> num = %hu\n", ptr -> num);
    printf("ptr -> c.x = %hu\n", ptr -> c.x);
    printf("ptr -> c.y = %hu\n", ptr -> c.y);



    puts("**************************************************");
    return 0;
}

