#include <stdio.h>
#include <stdlib.h>

/* this program takes 'n' numbers from user and prints sum of them. */

/****************************** logic of thinking: ************************************
* 1- I want to know 'n' number of elements to be summed.
* 2- I will create memory space of size = ( n*sizeof(each element) ).
* 3- Check if memory space is successufully created or not.
* 4- Create a loop to scan numbers from user and add each number to sum in the same loop.
* 5- Print sum.
* 6- free memory location.
******************************************************************/

int main()
{
    unsigned short int numbers;
    unsigned short int i;
    signed short int *ptr;
    signed long long int sum = 0;

    puts("************************************************\n");
    puts("Please enter number of elements that you want to add:");
    scanf("%hu", &numbers);
    ptr = (signed short int*) malloc(numbers*sizeof(signed short int));
    if( 0 == ptr)
    {
        puts("Sorry! NO sufficient memory for your variables.");
    }
    else
    {
        printf("please enter %hu numbers to find sum of them:\n", numbers);
        for(i=0; i<numbers; ++i)
        {
            scanf("%hd", (ptr+i) );  //scan numbers from user.
            sum += *(ptr+i);  //add each number to sum.
        }

        printf("You entered numbers: {");
        for(i=0; i<numbers; ++i)
        {
            printf(" %hd,", *(ptr+i) );
        }
        puts("\b }");

        printf("sum = %lld\n", sum);

        /*now free memory*/
        free(ptr);
        puts("Momory is freed, thank you. ByeBye!!\n");

    }
    



    puts("************************************************");
    return 0;
}