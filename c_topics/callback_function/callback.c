#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int sub(int x, int y)
{
    return x-y;
}

int mul(int x, int y)
{
    return x*y;
}

void display(int (*ptr)(int,int))
{
    int result = 0;
    result = (*ptr)(5,1);
    printf("result = %i\n", result);
}


int main()
{
    puts("--------------------------------------------------------");
    display(sum);
    display(sub);
    display(mul);
    puts("--------------------------------------------------------");
    return 0;
}