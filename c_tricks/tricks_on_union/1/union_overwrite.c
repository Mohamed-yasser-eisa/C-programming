#include <stdio.h>
#include <stdlib.h>
#include <string.h>


union var
{
    char x;
    unsigned short y;
    char arr[20];
}vr;

int main()
{
    puts("***************************************************");
    /*size of union = size of largest datatype member in it*/

    printf("size of vr = %i\n", sizeof(vr));

    /*union allocat sequentiall memory location of size = size of largest datatype member.*/
    /*each time you write in union, you are overwritting on the old data.*/

    vr.x = 'V';     /*write ASCI of 'V' in first byte of union */
    vr.y = 60100;   /*overwrite "60100" in first two bytes of union, here you corrupted data in first byte*/
    strcpy(vr.arr, "C Programming");    /*overwrite a string in union memory locations, here you corrupted all prevoius data in union*/
    
    printf("vr.x   = %c\n", vr.x);/*prints first char in string "C Programming".*/
    printf("vr.y   = %hu\n", vr.y);/*prints ASCI number = first two bytes in string "C Programming".*/
    printf("vr.arr = %s\n", vr.arr);/*prints the string stored in union.*/
    
    puts("***************************************************");
    return 0;
}