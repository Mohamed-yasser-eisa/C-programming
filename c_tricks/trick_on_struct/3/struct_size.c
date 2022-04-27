#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*run the program without removing "//" from next pragmas and notice the size of struct*/
/*remove first "//" from next pragmas and notice the size of struct*/



// #pragma pack(4)  /*reduce struct padding*/
// #pragma pack(2)  /*reduce struct padding more*/
// #pragma pack(1)  /*remove/prevent struct padding*/



struct car
{
    char x;
    double y;
    short z;
    long int r;
}cr;


int main()
{
    puts("************************************************");
    puts("*Notice the address of each member and the size of struct.\n");
    puts("--> Without #pragma, the compiler will make structure padding to check that:");
    puts("\t(1) Compiler will understand that word-line = microprocessor bit rate (8 bit, 16 bit, 32 bit, 64 bit, ...).");
    puts("\t(2) Each struct member is stored in one word-line is possible.");
    puts("\t(3) Each struct member is stored in address that is divisable by its size.");
    puts("\t(4) Address of next structure will be divisable by first member's size.\n");
    puts("----\t----\t----\t----\t----");
    puts("--> By writing #pragma pack(4), the compiler will reduce structure padding to check that:");
    puts("\t(1) Compiler will understand that word-line = 4 bytes.");
    puts("\t(2) Each struct member is stored in one word-line is possible.");
    puts("----\t----\t----\t----\t----");
    puts("--> By writing #pragma pack(2), the compiler will reduce more the structure padding to check that:");
    puts("\t(1) Compiler will understand that word-line = 2 bytes.");
    puts("\t(2) Each struct member is stored in one word-line is possible.");
    puts("----\t----\t----\t----\t----");
    puts("--> By writing #pragma pack(1), the compiler will remove structure padding:");
    puts("\t(1) Compiler will understand that word-line = 1 byte.");
    puts("\t(2) Each struct member is stored in one word-line is possible.");
    puts("----\t----\t----\t----\t----");


    printf("&cr.x = %i\n", &cr.x);
    printf("&cr.y = %i\n", &cr.y);
    printf("&cr.z = %i\n", &cr.z);
    printf("&cr.r = %i\n\n", &cr.r);

    printf("size of struct = %i\n", sizeof(cr));




    puts("************************************************");
    return 0;
}