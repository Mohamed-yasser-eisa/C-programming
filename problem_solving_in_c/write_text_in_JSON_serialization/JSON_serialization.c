#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/************************************************************************
* what do I want to do?
* 1- I want to write a pdf file, contains some data written in JSON format.
* 2- create struct of data that you want to store.
* 3- read client's data and store it in struct variable.
* 2- write these data in data.pdf.
* 3- read these data from data.pdf to print it for the user.
************************************************************************/

const char* file_name    = "data.pdf"; // if your txt file is in other directory dereference it by this way: ("C:\\program.txt")
const char* format_write = "{\n\tName: \"%s\",\n\tAge\t: %i,\n\tId\t: %llu\n}\n";
const char* format_read  = "\n\tName: \"%[^\"]\",\n\tAge\t: %i,\n\tId\t: %llu\n}\n";

typedef struct
{
    char name[21];
    unsigned char age;
    unsigned long long int id;
}client;


int main()
{
    /* local variables section: */
    client c1;
    client c2;
    FILE* file_pointer; //file pointer that holds the memory address of the txt file.

    puts("***************************************************************************");
    /* 1- read data from user: */
    
    puts("Please enter you data");
    puts("---------------------\n");

    printf("Your name is.......: ");
    fflush(stdin);
    fgets(c1.name, sizeof(c1.name), stdin);
    c1.name[strlen(c1.name)-1] = '\0';

    printf("Your age is........: ");
    fflush(stdin);
    scanf("%i", &c1.age);

    printf("Your national id is: ");
    fflush(stdin);
    scanf("%llu", &c1.id);
    
    /*-----------------------------------------------------------------------------------------------*/
    /* 2- write data in a text file: */

    file_pointer = fopen(file_name, "a");//before (reading/writting) from txt file, you need to open it first.
    
    if(NULL == file_pointer)//if file pointer == NULL; then your txt file does not exist or can not be opened.
    {
        printf("I can not create a txt file for you!!\n");
    }
    else // txt file is opened successfully
    {
       fprintf(file_pointer, format_write, c1.name, c1.age, c1.id); //write data to txt file in format_write.
       fseek(file_pointer, 0, SEEK_SET);   //set cursor to the begining of txt file.
    }
    fclose(file_pointer); //close the txt file.


    /* check that the cursor is at the end of the txt file: */
    //while ( !feof(file_pointer) ) // feof() returns (1 or 0), '1' if cursor at the end of txt file, of '0' if not so.
   // {
   //   do something...
   // }
    



    /*-----------------------------------------------------------------------------------------------*/
    /* 3- read data from txt file: */

    file_pointer = fopen(file_name, "r");
    if(NULL == file_pointer) //check if you can not open file:
    {
        puts("Can not open/find your text file!!\n");
        return 1;
    }
    else
    {
        fseek(file_pointer, 0, SEEK_SET);   //set cursor to the begining of txt file.
        char c = '\0';
        while ( (char)c != (char)'{' )
        {
            c = getc(file_pointer);
        }
        fscanf(file_pointer, format_read, &c2.name,&c2.age, &c2.id);//read data from txt file in format_read.  
    }
    
    

    /*-----------------------------------------------------------------------------------------------*/
    puts("----------------------------------------------------------------------------");
    puts("Your data are:");
    puts("----------------\n");
    printf("Your name is: %s\n", c2.name);
    printf("Your age is : %i\n", c2.age);
    printf("Your id is  : %llu\n", c2.id);
    

    puts("***************************************************************************");
    return 0;
}