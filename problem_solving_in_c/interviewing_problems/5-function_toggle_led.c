#include <stdio.h>
#include <stdlib.h>

// C function to toggle a LED.

#define PORTA (*(char*)0b00000101)

void LED_toggle(char* port, int pin_number)
{
    *port ^= (1<<pin_number);
}

int main()
{
    char port = 5; //0b000...101
    LED_toggle(&port, 1);
    printf("%i\n", port); //0b000...111
    return 0;
}