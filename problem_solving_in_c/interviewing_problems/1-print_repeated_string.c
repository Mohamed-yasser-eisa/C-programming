#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* you have two arrays of string, pass them to a function that returns the 
*  repeated strings in new array of strings */



//name of two dimentional array is a pointer to array of type ...

void repeated_string(char (*s1)[10], char (*s2)[10], char (*s3)[10])
{
    int i=0;
    for(i=0; i<4; ++i)
    {
        if( 0 == strcmp(*(s1+i), *(s2+i)) )
        {
            strcpy(*(s3+i), *(s1+i));
        }
    }
}

int main()
{
    int i=0;
    //array of strings means: two dimentional array of char.
    char str1[4][10] = {"ahmed", "mohamed", "Ali", "adel"};
    char str2[4][10] = {"ahmed", "mahmoud", "mona", "omar"};
    char str3[4][10] = {'\0'};

    printf("please enter first 4 strings:\n");
    for(i=0; i<4; ++i)
    {
        scanf("%s", str1+i);
    }
    printf("please enter second 4 strings:\n");
    for(i=0; i<4; ++i)
    {
        scanf("%s", str2+i);
    }

    repeated_string(str1, str2, str3);
    
    if(0 == str3[0][0])
    {
        printf("No repeated strings!\n");
    }
    else
    {
        printf("Repeated strings are:\n");
        for(i=0; i<4; ++i)
        {
            if( **(str3+i) != 0 )
            {
                printf("%s\n", str3[i]);
            }
            
        }
    }
    
    
    return 0;
}