#include <stdio.h>
#include <stdlib.h>


int main()
{
    puts("**************************************************");
    char name[30];
    printf("Please enter your name: ");
    scanf("%s", &name);//scanf("%s") can not read white spaces.
    printf("Your name is: %s\n\n", name);

    puts("Please enter your name:");
    fflush(stdin);
    gets(name);//gets() can read white spaces.
    printf("Your name is: %s\n\n", name);

    puts("Please enter your name:");
    fflush(stdin);
    gets(name);//gets() can read white spaces.
    printf("Your name is: %s\n\n", name);

    puts("**************************************************");
    gets(name);
    return 0;
}