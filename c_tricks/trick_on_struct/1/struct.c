#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
    int x;
    int y;
    short z;
}f = {10,22,33};

struct student
{
    int Id;
    float GPA;
    char name[10];
    short int day[4];
}s={10,3.5,"Adel Mosa",{4,3,2,1}};

int i=0;

int main()
{
    puts("**************************************************");
    struct car w;
    printf("size of w = %i bytes\n", sizeof(w));
    printf("w    = %i\n", w);//Unlike array, name of struct = value of first member in it.
    printf("w.x  = %i\n", w.x);//value of first element.
    printf("&w   = %i\n", &w);//like array, address of struct = address of first member in it.
    printf("&w.x = %i\n", &w.x);//address of member 'x' in the struct.
    printf("&w.y = %i\n", &w.y);//address of member 'y' in the struct.
    printf("&w.z = %i\n", &w.z);//address of member 'z' in the struct.

    puts("----------------------------------------------------");
    printf("size of f = %i bytes\n", sizeof(f));
    printf("f     = %i\n", f);//value of first member
    printf("&f    = %i\n", &f);//address of first member
    printf("&f.Id = %i\n", &f.x);//address of first member
    printf("&f+1  = %i\n", &f+1);//step of struct size
    printf("&f.Id = %i\n", &f.x+1);//step of int size
    



    

    

    puts("**************************************************");
    return 0;
}

