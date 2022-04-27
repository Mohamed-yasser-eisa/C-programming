#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum Days
{
    saturday,
    sunday,
    monday = 5,
    tuseday,
    wednesday,
    thursday = 5,
    friday
}day;

int main()
{
    puts("***************************************************");
    /*size of enum = size of largest integer member in it*/

    printf("size of day = %i\n", sizeof(day));

    /*enum gives a number to a string*/
    /*two or more enum elements can has the same integer number*/
    /*default integer value for first enum element = 0*/
    /*default integer value for next enum element = value of previous element + 1*/
    /*the value assigned to enum name must be integer value NOT float*/

    day = saturday;
    printf("day   = %i\n", day);
    day = sunday;
    printf("day   = %i\n", day);
    day = monday;
    printf("day   = %i\n", day);
    day = tuseday;
    printf("day   = %i\n", day);
    day = wednesday;
    printf("day   = %i\n", day);
    day = thursday;
    printf("day   = %i\n", day);
    day = friday;
    printf("day   = %i\n", day);
    
    
    puts("***************************************************");
    return 0;
}