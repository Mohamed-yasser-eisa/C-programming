#include <stdio.h>
#include <stdlib.h>

void print_string(char *ptr);

int main()
{
    puts("**************************************************");
    char name[30];

    printf("Please enter your name: ");
    fflush(stdin);
    gets(name);//gets() can read white spaces.
    print_string(name);

    puts("**************************************************");
    gets(name);
    return 0;
}

void print_string(char *ptr)
{
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ++ptr;
    }
    printf("\n");
}