#include <stdio.h>
#include <stdlib.h>

/* this function creates a random number in range of (1 : 6) */
unsigned char die_rol(void);

int main ()
{
    unsigned long int frequencyArray[6]={0};
    unsigned long int loopIterator = 0;
    unsigned char die_face = 0;

    for(loopIterator=1; loopIterator<=6000000; ++loopIterator)
    {
        die_face = die_rol();
        switch(die_face)
        {
            case 1:
                ++frequencyArray[0];
                break;
            case 2:
                ++frequencyArray[1];
                break;
            case 3:
                ++frequencyArray[2];
                break;
            case 4:
                ++frequencyArray[3];
                break;
            case 5:
                ++frequencyArray[4];
                break;
            case 6:
                ++frequencyArray[5];
                break;
        } // end of switch statement.
    }//end of for loop statement.

    for(loopIterator=0; loopIterator<6; ++loopIterator)
    {
        printf("Die face '%lu' = %lu\n",(loopIterator+1),frequencyArray[loopIterator]);
    }

    return 0;
}

unsigned char die_rol(void)
{
    /* rand(); is a function in stdlib.h generated random integer numbers */
    /* ( rand() % 6 ) this is a scaling statements, to scale integer numbers in range of (0 : 5) */
    /* 6 is called the scaling factor. */
    /* (+1) to shift values from (0:5) to be (1:6). */

    return (unsigned char)( 1 + (rand() % 6) );
}