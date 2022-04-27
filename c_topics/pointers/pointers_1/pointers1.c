#include <stdio.h>
#include <stdlib.h>

void swap_variables(int *ptr1, int *ptr2); //void swap(int ptr1[], int ptr2[])
void swap_pointers(int **ptr1, int **ptr2); 

int main()
{
    puts("****************************************************************");
    puts("Pointer to int, and use of operators: '&', '*' :\n");
    int x1 = 50;
    int *ptr1 = &x1;
    printf("x1      = %i\n", x1);
    printf("&x1     = %i\n", &x1);
    puts("-------   --------    -------");
    printf("ptr1    = %i\n", ptr1);//pointer to int
    printf("*ptr1   = %i\n", *ptr1);//dereference pointer to int = x1
    printf("&*ptr1  = %i\n", &*ptr1);//pointer to int x1, returns address of x1;
    puts("-------   --------    -------");
    printf("&ptr1   = %i\n", &ptr1);//pointer to pointer to int
    printf("*&ptr1  = %i\n", *&ptr1); //dereference pointer to pointer to int = pointer to int
    printf("**&ptr1 = %i\n", **&ptr1);//dereference pointer to pointer to int = value in int x1

    puts("-----------------------------------------------------------------");
    puts("Wild pointer:\n");

    /* wild pointer is any uninitialized pointer*/
    /* never apply dereference operator to wild pointer, it causes run-time error (segmentation fault)*/
    
    int *ptr2; //uninitialized pointer = wild pointer.

    printf("Address in ptr2 = %i\n", ptr2);//garbage value is stored in ptr2.

    puts("-----------------------------------------------------------------");
    puts("Access and step of pointers:\n");
    
    /* access and step of pointer depend on sizeof(data type) that the pointer points to */

    int x2 = 10;
    short x3 = 210;
    char x4 = 100;

    int *ptr3 = &x2;
    short *ptr4 = &x3;
    char *ptr5 = &x4;

    printf("ptr3   = %i\n", ptr3);//base address in ptr3
    printf("*ptr3  = %i\n", *ptr3);//access of ptr3 is 4 bytes
    printf("++ptr3 = %i\n", ++ptr3);//step of ptr3 is 4 bytes
    puts("-------   --------    -------");
    printf("ptr4   = %i\n", ptr4);//base address in ptr4
    printf("*ptr4  = %i\n", *ptr4);//access of ptr4 is 2 bytes
    printf("++ptr4 = %i\n", ++ptr4);//step of ptr4 is 2 bytes
    puts("-------   --------    -------");
    printf("ptr5   = %i\n", ptr5);//base address in ptr5
    printf("*ptr5  = %i\n", *ptr5);//access of ptr5 is 1 bytes
    printf("++ptr5 = %i\n", ++ptr5);//step of ptr5 is 1 bytes
    
    puts("-----------------------------------------------------------------");
    puts("Operations on pointers:\n");

    /* increment or decrement pointer = increment or decrement one step from its base address */

    int *ptr6 = 1500;//assume that '1500' is a memory location
    int *ptr7 = 2500;//assume that '2000' is a memory location

    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("++ptr6 = %i\n", ++ptr6);//increment sizeof(int) to base address of ptr6
    ptr6 = 1500;
    printf("--ptr6 = %i\n", --ptr6);//decrement sizeof(int) from base address of ptr6
    ptr6 = 1500;
    puts("-------   --------    -------");
    /* subtract value from pointer means: "subtract number of steps from base address": */
    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("ptr6-4 = %i\n", ptr6-4);
    puts("-------   --------    -------");

    /* Subtract pointer from another pointer returns number of steps between them */
    /* If we know steps between poinrters then we can get to any of them from address of the other one*/
    /* The two pointers must be of the same type */

    printf("ptr7-ptr6 = %i bytes\n", ptr7-ptr6);
    ptr6 = 1500;
    ptr7 = 2500;
    puts("-------   --------    -------");

    /* Adding value to pointer is allowed, and it means: "add to base adress number of steps" */
    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("ptr6+4 = %i\n", ptr6+4);
    ptr6 = 1500;
    ptr7 = 2500;
    puts("-------   --------    -------");

    /* Adding pointer to pointer is not allowed, because it has no meanning or useful use. */

    puts("-----------------------------------------------------------------");
    puts("Casting with pointers:\n");

    /* Type casting with pointers will affect access and step of pointer only. */
    /* Type casting with pointers never affect the address stored in it. */

    int x5 = 0xf5f4f6f3; // size of int = 4 bytes
    int *ptr8 = &x5;
    printf("(int) x5      = %X\n", x5);
    printf("*(int*)ptr8   = %X\n", *(int*)ptr8);
    printf("*(short*)ptr8 = %X\n", *(short*)ptr8);
    printf("*(char*)ptr8  = %X\n", *(char*)ptr8);

    puts("-----------------------------------------------------------------");
    puts("NULL pointers:\n");

    /* (NULL = '\0' = 0)*/
    /* It's a good practice to always assign (NULL) to any pointer that you will not assign it to variable now */
    /* Never dereference a (NULL) pointer, it will give you run-time error. */

    int *ptr9 = NULL;
    printf("ptr9 = 0X%p\n", ptr9);

    puts("-----------------------------------------------------------------");
    puts("Subscriptor operator [] with pointers:\n");

    /* ptr[0] = *(ptr+0) */
    /* ptr[1] = *(ptr+1) */
    /* ptr[2] = *(ptr+2) */
    
    /* You can not type cast pointer with subscriptor operator. */

    x5 = 0xf5f4f6f3; // size of int = 4 bytes
    ptr9 = &x5;

    printf("x5             = 0X%X\n", x5);
    printf("*ptr9          = 0X%X\n", *ptr9);
    printf("ptr9[0]        = 0X%X\n", ptr9[0]); // ptr9[0] = *(ptr9 + 0)
    printf("ptr9[1]        = 0X%X\n", ptr9[1]); //garbage value // ptr9[1] = *(ptr9 + 1)

    puts("\nYou can not type cast pointers with subscriptor operator as follow: ");
    printf("(char*)ptr9[0] = 0X%X\n", (char*)ptr9[0]); //you can not cast pointers with subscriptor operator
    
    puts("-----------------------------------------------------------------");
    puts("Arithmatic operators (++) with (*) in pointers:\n");

    /* (++) and (*) are unary operators of the same precedence, but they will be executed from right to left. */
    x5 = 0xf5f4f6f3; // size of int = 4 bytes
    ptr9 = &x5;
    printf("*ptr9++ = 0X%p\n", *ptr9++); // (++) will be executed first, but will increment in the next line.
    printf("*++ptr9 = 0X%p\n", *++ptr9); // (++) will be executed first, and will increment ptr by one step.

    puts("-----------------------------------------------------------------");
    puts("Pointers with const local and const global:\n");

    /*You can change value in const local variables using pointers during run time, because 
        const local variables are stored in (stack segement in RAM) */

    /*You can not change value stored in const global variables because it is stored in 
        (.rodata) in ROM "read only memory". if you tried to do that, it will cause;
        run-time erorr.  */

    puts("value of const global avriables can not be changed even with pointers,\n"
    "because it is stored in (.rodata) in ROM \"read only memory\" \n"
    "It will cause run-time error\n");

    const int x6 = 5;
    int *ptr10 = &x6;
    *ptr10 = 60;
    printf("x6 = %i\n", x6);

    puts("-----------------------------------------------------------------");
    puts("Call by reference using pointers:\n");

    /*Call by reference means to pass address of variables to function as function arguments,
        and recieve these addresses in pointers of the same type, and using pointers we can 
        change values of these variables. */

    int x7 = 100;
    int x8 = 200;
    puts("Numbers before swaping:");
    printf("X = %i\nY = %i\n", x7, x8);
    swap_variables(&x7, &x8);
    puts("Numbers after swaping:");
    printf("X = %i\nY = %i\n", x7, x8);

    puts("-----------------------------------------------------------------");
    puts("Dangling pointer:\n");

    puts("--> Dangling pointer is a pointer that points to a de-allocated object.");
    puts("--> Dangling pointer causes run-time error or segmentation fault.");
    puts("-->You can use static keyword with local variable to make their life time = program life time\n"
    "\tand you can use pointers to store and dereferene them.\n");

    puts("-----------------------------------------------------------------");
    puts("Pointer to pointer:\n");

    /* step of (pointer to pointer) is fixed size, it's depending on address size of memory location
        in you machine */
    

    int x9 = 10;
    int *ptr11 = &x9; // ptr11 is pointer to int;
    int **ptr12 = &ptr11;// ptr12 is pointer to pointer to int;
    int ***ptr13 = &ptr12;// ptr13 is pointer to pointer to pointer to int;

    printf("x9      = %i\n", x9);
    printf("ptr11   =%i\n", ptr11);
    printf("ptr12   =%i\n", ptr12);
    printf("ptr13   =%i\n", ptr13);

    puts("-------   --------    -------");

    printf("&x9      = %i\n", &x9);
    printf("&ptr11   =%i\n", &ptr11);
    printf("&ptr12   =%i\n", &ptr12);
    printf("&ptr13   =%i\n", &ptr13);

    puts("-------   --------    -------");

    printf("&x9 + 1   =%i\n", &x9 + 1);
    printf("ptr11 +1  =%i\n", ptr11 + 1);
    printf("&ptr11 +1 =%i\n", &ptr11 +1);
    printf("++ptr12   =%i\n", ++ptr12);
    printf("++ptr13   =%i\n", ++ptr13);


    puts("-----------------------------------------------------------------");
    puts("Swap addresses in pointers using pointer to pointer:\n");
    
    x7 = 100;
    x8 = 200;
    ptr10 = &x7;
    ptr11 = &x8;


    printf("Before swaping:\n");
    printf("*ptr10 = %i\n", *ptr10);
    printf("*ptr11 = %i\n", *ptr11);
    swap_pointers(&ptr10, &ptr11);
    printf("After swaping:\n");
    printf("*ptr10 = %i\n", *ptr10);
    printf("*ptr11 = %i\n", *ptr11);

    puts("-----------------------------------------------------------------");
    puts("Const pointers & pointers to const:\n");

    puts("--> Const pointer can not change the address in it.");
    puts("--> Pointer to const can not change the value in that variable.");
    puts("--> (int *const ptr) ptr is const pointer, which means you can not change its initialized address.");
    puts("--> (const int *ptr) ptr is pointer to const int, which means you can not change value of int variable.");
    puts("--> (const int *const ptr) ptr is const pointer to const int, which means you can not change its\n"
    "\tinitialized address, and you can not change value of int variable.");
    puts("--> (const int *ptr = &x;) :: doing ++(*ptr) NOT allowed, but *(++ptr) allowed.");
    puts("--> (int *const ptr = &x;) :: doing *(++ptr) NOT allowed, but ++(*ptr) allowed.");
    puts("--> (const int *const ptr = &x;) :: doing *(++ptr) or ++(*ptr) NOT allowed.\n");

    puts("-----------------------------------------------------------------");
    puts("Void pointer:\n");

    puts("Void pointer is a general purpose pointer, it can point to any variable of any\n"
    "\tdata type, or store address of any variable or another pointer.\n");
    puts("The step of void pointer = 1 byte.\n");
    puts("You can not dereference void pointer without casting, to determine access and step of it first.\n");

    int xy = 0xF4F6F2F3;
    void *pxy = &xy;
    printf("pxy = %i\n", pxy);
    ++pxy;
    printf("pxy = %i\n", pxy);//step = 1 byte
    --pxy;
    printf("xy = 0X%p\n", xy);
    printf("*(char*)pxy = 0X%X\n", *(char*)pxy); // cast pointer first before derefernceing it
    printf("*(short*)pxy = 0X%X\n", *(short*)pxy);
    printf("*(int*)pxy = 0X%X\n", *(int*)pxy);


    puts("-----------------------------------------------------------------");
    puts("Pointer to function:\n");

    puts("void(*ptr)(int ptr1[], int ptr2[]); --> ptr is a pointer to function takes two pointers and returns void\n");

    // "pfun" is pointer to function takes two pointers as arguments and returns void.
    void (*pfun)(int ptr1[], int ptr2[]) = swap_variables;
    int pfx = 10;
    int pfy = 50;

    puts("Before swaping:");
    printf("X = %i\n", pfx);
    printf("Y = %i\n", pfy);

    pfun(&pfx, &pfy); //or: (*pfun)(&pfx, &pfy);
    
    puts("After swaping:");
    printf("X = %i\n", pfx);
    printf("Y = %i\n", pfy);



    puts("****************************************************************");
    gets((char*)ptr1);//wait user enter any char the exit
    return 0;
}


void swap_variables(int *ptr1, int *ptr2) //void swap(int ptr1[], int ptr2[])
{
    *ptr1 = *ptr1 ^ *ptr2;
    *ptr2 = *ptr1 ^ *ptr2;
    *ptr1 = *ptr1 ^ *ptr2;
}

void swap_pointers(int **ptr1, int **ptr2)
{
    /* the following code is not allowed, because bitwise (^) operator
        does not work in addresses, it works only with int values.

    (*ptr1) = (*ptr1) ^ (*ptr2);
    (*ptr2) = (*ptr1) ^ (*ptr2);
    (*ptr1) = (*ptr1) ^ (*ptr2);
    */
   
   int *temp_ptr = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp_ptr;
}