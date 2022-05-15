#include <stdio.h>
#include <stdlib.h>


// Fibonacci series without recursion.


int main()
{
    int first=0, second = 1, next=0, number=0,i=0;
    scanf("%i", &number);

    for(i=0; i<number; ++i)
    {
        if(i <= 1 )
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%i ", next);
    }
    printf("\n");
    return 0;
}