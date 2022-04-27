#include <stdio.h>
#include <stdlib.h>



int main()
{
    puts("**************************************************");
    int x[2][3][5];
    printf("x    = %i\n", x);//address in pointer to two dimention array [3][4] int
    printf("&x   = %i\n", &x);//address in pointer to two dimentional array[3][4] /*&x = int (*ptr)[2][3]*/
    printf("x+1  = %i\n", x+1);//step of pointer to two dimention array [3][4] int = 48 bytes
    printf("&x+1 = %i\n", &x+1);//step of pointer to three dimentional array [2][3][4] = 96 bytes /*&x = int (*ptr)[2][3][4]*/
    
    
    /*You have base address of three dimentions array, get address of: x[1][2][3]*/
    /*address of x[1][2][3] = (1*step)+(2*step)+(3*step)*/
    /*address of x[1][2][3] = (1*60)+(2*20)+(3*4)=112*/
    printf("address = %i\n", &x);//base address
    printf("address = %i\n", &x[1][2][3]);//calculate this address

    

    puts("**************************************************");
    return 0;
}

