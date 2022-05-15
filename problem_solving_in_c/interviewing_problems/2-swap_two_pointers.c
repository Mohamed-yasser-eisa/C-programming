#include <stdio.h>
#include <stdlib.h>

//C function to SWAP two pointers, draw what happens in the Stack.

/************
* what happens in the stack?
* 1- a memory location is reserved for local variables of main(): (x-y-ptr1-ptr2).
* 2- when function is called, a new stack frame is pushed into stack for swap_pointer.
* 3- a memory location is reserved for local variables of swap_pointer(): (p1,p2,temp_ptr).
* 4- when program reaches the end of swap_pointer(), the frame of this function is poped from stack.
* 5- program control returns to main().
*/


void swap_pointer(int** p1,int** p2)
{
    int* temp_ptr = *p1;
    *p1 = *p2;
    *p2 = temp_ptr;
}



int main()
{
    int x = 50;
    int y = 60;
    int* ptr1 = &x;
    int* ptr2 = &y;

    printf("ptr1 = %i\nptr2 = %i\n", *ptr1, *ptr2);
    swap_pointer(&ptr1, &ptr2);
    printf("ptr1 = %i\nptr2 = %i\n", *ptr1, *ptr2);
    
    return 0;
}