#include <stdio.h>
#include <stdlib.h>

// C function returns the average of an array.

float avarage_array(int* ptr, int size)
{
    int sum = 0, i = 0;
    float avrage = 0.0;
    for(i=0; i<size; ++i)
    {
        sum += ptr[i];
    }
    avrage = (float)sum/size;
    return avrage;

}


int main()
{
    float av = 0.0;
    int array[] = {1,2,3,4,5,6,7,8};
    av = avarage_array(array, sizeof(array)/sizeof(int));

    printf("avrage = %0.1f\n", av);

    return 0;
}