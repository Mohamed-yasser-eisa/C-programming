#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i,j,k,number;
    printf("Enter number of rows: ");
    scanf("%u",&number);

    for(i=number; i>=1; --i)
    {
        for(j=1; j<i; ++j)
        {
            printf(" ");
        }
        k=number-i;
        for(j=0; j<(number-i+1+k); ++j)
        {
            printf("*");
        }
        puts("");
    }


    return 0;
}
