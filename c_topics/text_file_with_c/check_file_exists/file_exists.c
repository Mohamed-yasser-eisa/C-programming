#include <stdio.h>
#include <stdlib.h>

/*You can use any og these three functions to check the exists of txt file:*/

/* (1) using (fopen();) function: */
unsigned char is_txtFile_exist(const char* file_name);

/*https://www.learnc.net/c-tutorial/c-file-exists/  */

int main()
{
    puts("************************************************");
    char* txt_name = "data.txt";
    if( is_txtFile_exist(txt_name) )
    {
        printf("Your %s is founded!!\n", txt_name);
    }
    else
    {
        printf("Your %s is not founded!!\n", txt_name);
    }



    puts("************************************************");
    return 0;
}


unsigned char is_txtFile_exist(const char* file_name)
{
    FILE* file_pointer; //pointer to file.
    file_pointer = fopen(file_name, "r"); //try to read from txt file, if succeded then file exist, if not then file not exist.
    unsigned char file_exist = 0;
    if(NULL == file_pointer)
    {
        file_exist = 0; // 0 = file is not exist.
    }
    else
    {
        file_exist = 1; // 1 = file is exist.
    }
    fclose(file_pointer);
    return file_exist;
}