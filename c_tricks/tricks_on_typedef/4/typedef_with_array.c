#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*when you use typedef with array, then array's name is a new datatype of type: "array" */

typedef char char_arr[30];//now char_arr is a datatype of type array of 30 char.


int main()
{
    puts("************************************************");
    
    char array [30] = "Welcome, to my GitHub (^_^)!";
    char_arr welcome;// now "welcome" is an array of 30 char.
    strcpy(welcome, array);
    printf("%s\n", welcome);

    puts("************************************************");
    return 0;
}
