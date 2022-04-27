#include <stdio.h>
#include <stdlib.h>


union Data
{
    char x;
    unsigned short  y;
    unsigned int z;
    double arr[5];
};



int main()
{
    int i=0;
    puts("**************************************************");
    puts("--> union is a user defined datatype that allows user to store different datatypes\n"
    "in the same memory location.");

    union Data data;
    data.x = 'a';
    printf("data.x = %c\n", data.x);
    printf("size of data = %i\n", sizeof(data));
    puts("----  ----    ----    ----    ----    ----");
    data.y = 15000;
    printf("data.y = %hu\n", data.y);
    printf("size of data = %i\n", sizeof(data));
    puts("----  ----    ----    ----    ----    ----");
    data.z = 100000;
    printf("data.z = %i\n", data.z);
    printf("size of data = %i\n", sizeof(data));
    puts("----  ----    ----    ----    ----    ----");

    
    for(i=0; i<5; ++i)
    {
        data.arr[i] = 100 + i*0.578;
    }
    for(i=0; i<5; ++i)
    {
        printf("data.arr[%i] = %0.3lf\n", i, data.arr[i]);
    }
    printf("size of data = %i\n", sizeof(data));
    
    puts("------------------------------------------------");
    puts("--> size of union = size of largest member's datatype in it.\n");
    puts("--> In previous example, the union size = (size of double)*(number of array elements) = 8*5 = 40 bytes.\n");
    
    puts("------------------------------------------------");
    puts("--> You can create a variable from union datatype, and has the same name of the union name.");
    union Data Data;

    Data.x = 'D';
    printf("Data.x = %c\n", Data.x);
    Data.y = 5050;
    printf("Data.y = %hu\n", Data.y);
    Data.z = 100200300;
    printf("Data.z = %i\n", Data.z);
    for(i=0; i<5; ++i)
    {
        Data.arr[i] = 100*i*0.578;
    }
    for(i=0; i<5; ++i)
    {
        printf("Data.arr[%i] = %0.3lf\n", i, Data.arr[i]);
    }
    

    puts("");
    puts("**************************************************");
    return 0;
}