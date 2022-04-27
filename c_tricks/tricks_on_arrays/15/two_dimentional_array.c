#include <stdio.h>
#include <stdlib.h>



int main()
{
    puts("**************************************************");
    int x[2][3];
    printf("x    = %i\n", x);//address in pointer to array of 3 int
    printf("&x   = %i\n", &x);//address in pointer to two dimentional array[2][3] /*&x = int (*ptr)[2][3]*/
    printf("x+1  = %i\n", x+1);//step of pointer to array of 3 int = 12 bytes
    printf("&x+1 = %i\n", &x+1);//step of pointer to two dimentional array [2][3] = 24 bytes
   

    

    puts("**************************************************");
    return 0;
}

