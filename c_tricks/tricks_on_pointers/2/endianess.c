#include <stdio.h>
#include <stdlib.h>

/*this program returns 'B' if your compiler is Big-endian, and 'L' if your compiler is little-endian*/

int main()
{
    puts("************************************************************\n");
    int var = 0XF9F8F7F6;
    int *ptr = &var;

    if( (char)0xF9 == (char)*(char*)ptr)
    {
        printf("(char)*(char*)ptr = 0x%X\n", (char)*(char*)ptr);
        puts("Your compiler is Big-endian\n");
    }
    else if ( (char)0xF6 == (char)*(char*)ptr)
    {
        printf("(char)*(char*)ptr = 0x%X\n", (char)*(char*)ptr);
        puts("Your compiler is Little-endian\n");
    }

    
    puts("************************************************************");
    gets((char*)ptr);

    return 0;
}