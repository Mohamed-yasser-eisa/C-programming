#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
* Steps to read from a txt file:
*   1- make sure that you have a txt file in your directory to be read.
*   2- inclide <stdio.h> to use functions that help you interface with txt file.
*   3- create a pointer of type (FILE) to point to your txt file.
*   4- create an array of chars to hold the string you read in it.
*   5- use (fgets();) function to read txt file and store in your array.
*   6- print you array of char as a string.
*
*****************************************************************************************/



int main()
{
    puts("************************************************");
    /* first you need to create a pointer of type FILE, to hold location of your txt file: */
    FILE* filePointer = fopen("file.txt", "r"); //file pointer which is set to read only.

    /*check if you can not open file: */
    if(NULL == filePointer)
    {
        puts("Can not open/find your text file!!\n");
        return 1;
    }

    /*now let's print text from txt file: */
    char output[255];//array of char to hold string.
    unsigned char i = 0;
    for(i=0; fgets(output, sizeof(output), filePointer) != NULL; ++i)
    {
        printf("%02d: %s", i, output);
    }
    puts(""); //new line
    
    /*now let's close our text file: */
    fclose(filePointer);

    puts("************************************************");
    return 0;
}