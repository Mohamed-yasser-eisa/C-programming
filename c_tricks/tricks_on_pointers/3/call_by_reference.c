#include <stdio.h>
#include <stdlib.h>

int fun(int x, int *py, int **pyy)
{
    int y,z;
    **pyy += 5;
    z = **pyy;
    *py += 3;
    y = *py;
    x += 7;
    return x + y + z;
}

int main()
{   
    puts("**********************************************");
    int c, *b, **a;
    c = 6, b = &c, a = &b;
    printf("%d\n", fun(c,b,a));
    puts("**********************************************");
    gets((char*)b);

    return 0;
}