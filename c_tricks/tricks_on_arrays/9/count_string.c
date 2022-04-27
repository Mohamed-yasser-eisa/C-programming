#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void count_string(char *ptr, int *count);

int main()
{
    puts("**************************************************");
    char name[30];
    int number_characters=0;
    printf("please enetr your name to count its characters: ");
    gets(name);
    count_string(name, &number_characters);
    printf("Your name is: %s\n", name);
    printf("Number of characters you enterer = %i (including spaces)\n\n", number_characters);

    puts("----  ----    ----");
    /*Or you can use built in function "strlen" in <string.h> */
    puts("Please enetr another string to count its caracters:");
    gets(name);
    number_characters = strlen(name);
    printf("Number of characters = %i\n", number_characters);
    puts("**************************************************");
    gets(name);
    return 0;
}

void count_string(char *ptr, int *count)
{
    *count=0;
    while(*ptr != '\0')
    {
        *count+=1;
        ptr++;
    }
}