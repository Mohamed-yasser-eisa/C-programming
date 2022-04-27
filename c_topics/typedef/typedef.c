#include <stdio.h>
#include <stdlib.h>


typedef unsigned char Byte;
typedef unsigned short Uint16;

/*Also we can give a name to pointer datatype as follow:*/
typedef char* pointer_char;
typedef int*  pointer_int;


/*typedef with struct:*/
/*we can use typedef to give a name to the struct as follow:*/
typedef struct car
{
    int x;
    short y;
}car_t;

/*Or you can give a name to struct after struct declaration as follow:*/
struct bus
{
    char a;
    int b;
};

typedef struct bus bus; /*now you can use "bus" to create a new variable from struct bus.*/


/*Also you can use typedef with struct without tag_name, as follow:*/
typedef struct
{
    int id;
    char name[10];
    short number;
}client;  /*now client is a datatype keyword, and you can use it to create variable from struct datatype.*/



/*****************tricks************************************/


/*Also you can use typedef with pointer to function to create a new datatype from type: "pointer to function" as follow:*/
typedef int (*ptr_fun)(int, int); /*now ptr_fun is a datatype of type pointer to function that takes two ints and returns int*/

/*Also you can use typedef with pointer to array to create a new datatype from type: "pointer to array" as follow:*/
typedef int (*ptr_arr)[4]; /*now ptr_arr is a datatype of type pointer to array of 4 ints.*/

/*Also you can use typedef with array to create a new datatype from type: "array" as follow:*/
typedef int arr[4]; /*now arr is a datatype of type array of 4 ints. Which means that array name is a datatype.*/

/***********************************************************/




int main()
{
    puts("************************************************");
    puts("typedef is a keyword which is used to give a new name to datatype.\n");
    puts("--> Syntax is as follow:");
    puts("\ttypedef\told_datatype\tnew_name;\n");

    Byte x = 255;
    printf("X = %i\n", x);

    car_t c1;
    c1.x = 50;
    c1.y = 1000;
    printf("c1.x = %i\n", c1.x);
    printf("c1.y = %i\n", c1.y); 



    puts("************************************************");
    return 0;
}