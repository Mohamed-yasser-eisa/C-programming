#include <stdio.h>
#include <stdlib.h>

int repeated_digits(unsigned int *ptr);


int main()
{
    puts("**************************************************");
    unsigned int number = 0;
    puts("Please enter a number to check for repeated digits:\n");
    fflush(stdin);
    scanf("%i", &number);

    if(1 == repeated_digits(&number))
    {
        puts("Number contains repeated digits.");
    }
    else
    {
        puts("Number does not contain any repeated digits.");
    }

    puts("**************************************************");
    return 0;
}


int repeated_digits(unsigned int *ptr)
{
    unsigned int temp[30];
    unsigned long long int factor = 10;
    int i=0;
    int j=0;
    int digits=1;
    int num=0;
    while( (*ptr/factor) != 0 )//count number of digits in number
    {
        factor *= 10;
        digits++;
    }
    for(i=0; i<digits; ++i)//store each digit in array of char
    {
        factor /=10;
        if(0 == factor)//to avoid run-time error, due to division on zero;
        {
            factor = 1;
        }
        temp[i] = (*ptr)/factor;
        *ptr -= temp[i] * factor;
        
    }
    for(i=0; i<digits; ++i)//check for repeated digits
    {
        num = temp[i];//take digit and compare
        for(j=i+1; j<digits; ++j)//compare digit with rest of the array
        {
            if(num == temp[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
