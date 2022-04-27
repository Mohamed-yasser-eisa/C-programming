#include <stdio.h>
#include <stdlib.h>


/*when you use typedef with pointer to array, then pointer's name is a new datatype of type: "pointer to array" */

typedef char (*ptr_arr)[30];//now ptr_arr is a datatype of type pointer to array of 20 char.


int main()
{
    puts("************************************************");
    
    char array [30] = "Welcome, to my GitHub (^_^)!";
    ptr_arr welcome;// now "welcome" is a pointer to array of 30 int.
    welcome = &array;
    printf("%s\n", *welcome);

    puts("************************************************");
    return 0;
}
