#include <stdio.h>
#include <stdlib.h>


// C function to get the most repeated element in an array.

int most_re[2];

void most_repeated(int* arr, int size)
{
    int num = 0, counter = 1, most_num = 0, most_repeated = 0, i = 0; 
    for(i=0; i<size; ++i)
    {
        if(arr[i] == arr[i+1])
        {
            counter++;
            num = arr[i];
        }
        else
        {
            if(most_repeated < counter)
            {
                most_repeated = counter;
                most_num = num;
                counter = 1;
                num = 0;
                most_re[0] = most_repeated;
                most_re[1] = most_num;
            }
        }
    }
}

int main()
{
    int array[] = {1,1,2,3,4,5,5,5,5,5,5,6,6,7,8,9,10};
    most_repeated(array, sizeof(array)/sizeof(int));
    printf("Most repeated number is: %i\n", most_re[1]);
    printf("Number is repeated number of times: %i\n", most_re[0]);
    return 0;
}

