#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************************
* Steps to write a txt file:
*   1- make sure that you have a txt file in your directory to write on it.
*   2- inclide <stdio.h> to use functions that help you interface with txt file.
*   3- create a pointer of type (FILE) to point to your txt file.
*   4- write on the txt file using (fprintf();) function.
*
*****************************************************************************************/

/****************************************************************************************
*   Modes of fopen();
*   1--> "r" (read only mode) open file for reading, the file MUST exist.
*   2--> "w" (write mode) open file for writting, if file not exist create it, if file exist delete its content and write.
*   3--> "a" (append mode) write at the end of txt file, if file not exist create it.
*   4--> "r+" (read/write mode) open file for reading/writting, the file MUST exist.
*   5--> "w+" (read/write mode) open file for reading/writting, if file not exist create it, if file exist delete its content and write.
*   6--> "a+" (append mode) open txt file for reading or updating at the end, if file not exist create it.
*   7--> "rb" (read mode) open a binary file for reading, file MUST exist.
*   8--> "wb" (write mode) open binary file for writting, if file not exist create it, if file exist delete its content and write.
*   9--> "ab" (append mode) open binary file for writting at the end, if file not exist create it.
*   10--> "rt" (read txt) open txt file for reading, txt file MUST exist.
*   11--> "wt" (write txt) open file for writting, if file not exist create it, if file exist delete its content and write.
*   12--> "at" (append mode) open txt file for writting at the end, if file not exist create it.
*   13--> "r+b" or "rb+" open binary file for read/write, binary file MUST exist.
*   14-->....
*   15--> "r+t" or "rt+" open txt file for both read/write, the txt file MUST exist.
*   16--> "w+t" or "wt+" open txt file for both read/write, if txt file not exist create it. If it exist delete its data.
*
******************************************************************************************/


int main()
{
    puts("************************************************");
    char* fileName = "data.txt";
    char data[10];
    /* first you need to create a pointer of type FILE, to hold location of your txt file: */
    FILE* filePointer = fopen(fileName, "wt"); //file pointer which is set to write only.
    

    /*check if you can not open file: */
    if(NULL == filePointer)
    {
        printf("Can not open/find %s file!!\n", fileName);
        return 1;
    }

    int i=0;
    for(i=0; i<2;++i)
    {
        printf("(%i)Please enter your name: ", i);
        fflush(stdin);
        //gets(data);
        fgets(data, 10, stdin);//read string from input buffer of size 10 only
        fprintf(filePointer, "%s\n",data);
        //fwrite(data, sizeof(char), strlen(data), filePointer);
        //sprintf(data, "%s\n", "Hello! I'm your computer");
        //fprintf(filePointer, "%s\n",data);
        /* Or use fputs(); to write string without paces: */
        //fputs(data, filePointer);
    }
       
    
    /*now let's close our text file: */
    fclose(filePointer);

    puts("************************************************");
    return 0;
}