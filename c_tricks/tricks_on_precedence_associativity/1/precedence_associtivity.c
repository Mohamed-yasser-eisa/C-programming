#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************
*   --> "precednece": it tells us which operator in an expression MUST be evaluated first.
*   --> "associtivity": it tells us how to evaluate an expression that contains operators from the same precedence.
*
*NOTES:
*   --> we only use associtivity when two or more operators of the same precedence are in one expression.
*   --> the associativity and precedence of prefix ++ and postfix ++ are very different from each other. 
*       Here, the precedence of prefix ++ is less as compared to the postfix ++. Thus, their associativity 
*       also turns out to be different. Here, the associativity of prefix ++ is from right to left, while the 
*       associativity of postfix ++ is from left to right.
*   --> 
*
**********************************************************************************/


int main()
{
    puts("************************************************");
    int x = 10;
    int y = 5;
    int z = 0;
   //int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    z = x / 2 + 10;
    printf("z = %i\n", z);  //15

    z = x * 2 / y;
    printf("z = %i\n", z);  //4

    z = x / 2 * y;
    printf("z = %i\n", z);  //25
    /*
    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    z = ;
    printf("z = %i\n", z);

    */

    puts("************************************************");
    return 0;
}