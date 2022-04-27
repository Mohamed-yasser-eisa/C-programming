#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("****************************************************************");
    puts("The ampersand operator is a pointer with no memory space:\n");

    /* the ampersand (&) operator works as a pointer to a memory location */
    /* the ampersand operator works as a pointer, but it does not ocipy memory space like pointers */
    
    int var1 = 10;
    short var2 = 20;
    char var3 = 50;

    //the (&) works as a pointer to var1, so it can return the address of var1 as follow:
    printf("Address of var1 = %i (&var1)\n", &var1);
    printf("Address of var2 = %i (&var2)\n", &var2);
    printf("Address of var3 = %i (&var3)\n", &var3);
    //As (&) works as a pointer, so we can use dereference operator with
    //it to return value stored in var1 as follow:
    printf("Value in var1   = %i (*&var1)\n", *&var1);
    printf("Value in var2   = %i (*&var2)\n", *&var2);
    printf("Value in var3   = %i (*&var3)\n", *&var3);

    puts("-----------------------------------------------------------------");
    puts("The step of ampersand operator like pointers:\n");
    /* as pointers the step of the '&' operator will depend on the data type of the variable that it 
        points to as follow: */
    printf("Address of var1         = %i\n", &var1);
    printf("Next address after var1 = %i\n", &var1+1);
    printf("Address of var2         = %i\n", &var2);
    printf("Next address after var2 = %i\n", &var2+1);
    printf("Address of var3         = %i\n", &var3);
    printf("Next address after var2 = %i\n", &var3+1);

    puts("-----------------------------------------------------------------");
    puts("The ampersand with pointers:\n");

    /* when we use '&' with pointer, it acts as a (pointer to pointer) */

    /* if we want to return the value that the pointer pointes to using '&', then we
        should use '**' */

    /* the step of '&' here will be fixed of size of address size, because it
        points to pointer not a variable, and all pointers have the same size. */

    /* when we dereference(*) "pointer to pointer" once it becomes a pointer to variable.*/

    /* when we dereference(*) "pointer to pointer" twice it returns the value in the variable.*/

    int *ptr1 = &var1;
    short *ptr2 = &var2;
    char *ptr3 = &var3;
    // (&ptr1) is a pointer to pointer.
    printf("Address of ptr1 (&ptr1)      = %i (pointer to pointer)\n", &ptr1);
    //step will be of size = size of memeory address
    printf("Next step of (&ptr1+1)       = %i (step of pointer to pointer)\n", &ptr1+1);
    //(*& ptr1) is a pointer to var1, same as "ptr1".
    printf("The address in ptr1 (*&ptr1) = %i (pointer to int, smae as ptr1)\n", *&ptr1);
    //step will be of size = size of (int)
    printf("Next step of (*&ptr1+1)      = %i (step of pointer to int)\n", *&ptr1+1);
    //(**& ptr1) is var1.
    printf("Value in var1 (**&ptr1)      = %i (dereference pointer to int = var1)\n", **&ptr1); 
    
    puts("-------   --------    -------");

    // (&ptr2) is a pointer to pointer.
    printf("Address of ptr2 (&ptr2)      = %i (pointer to pointer)\n", &ptr2); 
    //step will be of size = size of memeory address
    printf("Next step of (&ptr2+1)       = %i (step of pointer to pointer)\n", &ptr2+1);
    //(*& ptr2) is a pointer to var2, same as "ptr2".
    printf("The address in ptr2 (*&ptr2) = %i (pointer to short, smae as ptr2)\n", *&ptr2); 
    //step will be of size = size of (short)
    printf("Next step of (*&ptr2+1)      = %i (step of pointer to short)\n", *&ptr2+1);
    //(**& ptr2) is var2.
    printf("Value in var2 (**&ptr2)      = %i (dereference pointer to short = var2)\n", **&ptr2); 
    
    puts("-------   --------    -------");

    // (&ptr3) is a pointer to pointer.
    printf("Address of ptr3 (&ptr3)      = %i (pointer to pointer)\n", &ptr3); 
    //step will be of size = size of memeory address
    printf("Next step of (&ptr3+1)       = %i (step of pointer to pointer)\n", &ptr3+1);
    //(*& ptr3) is a pointer to var3, same as "ptr3".
    printf("The address in ptr3 (*&ptr3) = %i (pointer to short, smae as ptr3)\n", *&ptr3); 
    //step will be of size = size of (char)
    printf("Next step of (*&ptr3+1)      = %i (step of pointer to char)\n", *&ptr3+1);
    //(**& ptr3) is var3.
    printf("Value in var2 (**&ptr3)      = %i (dereference pointer to char = var3)\n", **&ptr3); 



    puts("****************************************************************");
    gets(ptr3);//wait user enter any char the exit
    return 0;
}