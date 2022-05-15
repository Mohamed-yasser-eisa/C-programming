#include <stdio.h>
#include <stdlib.h>

//C function to toggle a specific bit in 8-bits variable.
void toggle_bit(char* num, int bit)
{
    *num ^= (1 << bit);
}


int main()
{
    unsigned char number = 5;
    toggle_bit(&number, 1);
    printf("%i\n", number);
    return 0;
}