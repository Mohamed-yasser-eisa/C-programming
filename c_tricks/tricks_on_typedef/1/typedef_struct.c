#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* first way: */
typedef struct car
{
    int number;
    char color[10];
}CAR;

/* second way: */
typedef struct
{
    long long int id;
    char name[20];
    float sallary;
}CLIENT;

/*third way:*/
struct bus
{
    int num;
    double price;
    char time[15];
};

typedef struct bus BUS;

/*---------------------------------------------------------------------*/


int main()
{
    puts("************************************************");
    CAR cr;/* "cr" is an object of type: struct car*/
    cr.number = 94563;
    strcpy(cr.color, "Blue");
    printf("Car number is : %i\n", cr.number);
    printf("Car color is  : %s\n", cr.color);
    puts("-------------------------------------------------");

    CLIENT cl; /* "cl" is an object of type: struct client*/
    cl.id = 6587013345;
    cl.sallary = 10500.50;
    strcpy(cl.name, "Mohamed Yasser");
    printf("Client name is    : %s\n", cl.name);
    printf("Client ID is      : %lli\n", cl.id);
    printf("Client sallary is : %f\n", cl.sallary);
    puts("-------------------------------------------------");

    BUS bs = {53641, 27000.890, "10h:15m:49s"};
    printf("Bus number is : %i\n", bs.num);
    printf("Bus price is  : %0.4lf\n", bs.price);
    printf("Bus time is   : %s\n", bs.time);
    
    puts("");
    



    puts("************************************************");
    return 0;
}