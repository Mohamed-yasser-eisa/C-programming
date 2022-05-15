#include <stdio.h>
#include <stdlib.h>


//C function to SWAP two variables.


void swap_var(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    printf("x = %i\ny = %i\n", x, y);
    swap_var(&x, &y);
    printf("x = %i\ny = %i\n", x, y);

    return 0;
}