#include <stdio.h>
#include <stdlib.h>

int unrepeated_number(unsigned int *ptr, int size);

int i;

int main()
{
    puts("**************************************************");
    unsigned int number[] = {1,2,3,3,2,5,7,1,5};
    int unrepeated=0;
    printf("Array = { ");
    for(i=0; i<9; ++i)
    {
        printf("%i, ", number[i]);
    }
    puts("\b\b }\n");

    puts("Unrepeated elemet is:");
    unrepeated = unrepeated_number(number, (sizeof(number)/sizeof(int)) );
    printf("%i\n",  unrepeated);


    

    puts("**************************************************");
    return 0;
}


int unrepeated_number(unsigned int *ptr, int size)
{
    int j=0;
    int num=0;
    int flag=0;
    
    for(i=0; i<size; ++i)//check for unrepeated digits
    {
        num = ptr[i];//take digit and compare
        for(j=0; j<size; ++j)//compare digit with rest of the array
        {
            if((num == ptr[j]) && (i != j) )
            {
                flag=1;
                break;
            }
            flag=0;
        }
        if(0 == flag)
        {
            break;
        }
    }
    return num;
}
