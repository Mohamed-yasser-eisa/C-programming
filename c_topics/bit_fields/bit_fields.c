#include <stdio.h>
#include <stdlib.h>



#pragma pack(1)


/************************************************************************************************
* 1- "bit field" means that you can determine number of bits that you want as a size of variable.
* 2- the variable MUST be a member of (struct or union) ONLY.
* 3- use (:) followed by number of bits that you want for this variable.
* 4- you can enter any number of bits as you want even 1-bit is allowed.
* 5- you can not determine (0) as a number of bits! EX: (int x:0;)--> not allowed and generate syntax error.
* 6- you can not use sizeof(); with bit field variable. EX: (sizeof(c1.x);)--> not allowed and generates syntax error.
* 7- you can not get address of bit field variables. You can only access it using (.) "member of operator".
* 8- overflow occures when you try to store number of size  > size of bit field variable.
* 9- bit field variable can not be of type float or double, it will generate syntax error.
* 10- sizeof(bit field) can not exceed sizeof(datatype). EX: (char x:9;)--> not allowed generate syntax error.
* 11- 
************************************************************************************************/

typedef struct
{
    int x:1;  //serve 1 bit for 'x'.
    int y:9;  //serve 9 bits for 'y'.
    int z:12; //serve 12 bits for 'z'.
}car;

typedef struct
{
    int r:10;  //serve 10 bits for 'r'.
    int t:19;  //serve 19 bits for 't'.
    int u:17;  //serve 17 bits for 'u'.
}bus;

typedef struct
{
    char m:1;
    char o:1;
    char h:1;
    char a:1;
    char e:1;
    char d:1;
    char s:1;
    char l:1;
}NAME;


int main()
{
    puts("*******************************************************************************************\n");
    puts("size of struct with bit fields = minumim number of bytes enough to store the number of bits of variables:\n");
    car c1;
    printf("size of c1   = %i bytes\n", sizeof(c1));  //number of bits in bit field = 32 bits, then store them in one int (4 bytes).
    bus b1;
    printf("size of b1   = %i bytes\n", sizeof(b1));  //number of bits in bit field = 46 bits, then store them in two ints (8 bytes).
    NAME n1;
    printf("size of n1   = %i bytes\n", sizeof(n1));  //number of bits in bit field = 8 bits, then store them in one char (1 bytes).
    puts("--------------------------------------------------------------------------------------------\n");
    puts("--> bit field overflow:");
    puts("--> if you tried to store (255) in bit field variable of size 3-bits, then");
    puts("\tfirst 3-bits only of 255 will be stored in bit field variable.");
    c1.x = 255;
    c1.y = 255;
    c1.z = 255;
    b1.r = 255;
    b1.t = 255;
    b1.u = 255;
    printf("c1.x = %i\n", c1.x);
    printf("c1.y = %i\n", c1.y);
    printf("c1.z = %i\n", c1.z);
    printf("b1.r = %i\n", b1.r);
    printf("b1.t = %i\n", b1.t);
    printf("b1.u = %i\n", b1.u);

    puts("--------------------------------------------------------------------------------------------\n");



    puts("--------------------------------------------------------------------------------------------\n");


    puts("--------------------------------------------------------------------------------------------\n");


    puts("--------------------------------------------------------------------------------------------\n");



    puts("--------------------------------------------------------------------------------------------\n");
    



    puts("*******************************************************************************************\n");
    return 0;
}