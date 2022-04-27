#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_copy(char *ptr1, char *ptr2);


int main()
{
    puts("**************************************************");
    char name[30];
    char copy_name[30];

    printf("Please enter your name: ");
    fflush(stdin);
    gets(name);//gets() can read white spaces.
    string_copy(name, copy_name);
    printf("Your name is: %s\n\n", copy_name);

    /* Or you can use built in function "strcpy" it takes two strings and copy second one in the first one.*/
    strcpy(copy_name, "Hi My name is Mohamed!");
    printf("Array copy using strcpy() function: %s\n", copy_name);

    puts("**************************************************");
    gets(name);
    return 0;
}


void string_copy(char *ptr1, char *ptr2)
{
    while(*ptr1 != '\0')
    {
        *ptr2 = *ptr1;
        ++ptr1;
        ++ptr2;
    }
    *ptr2='\0';
}