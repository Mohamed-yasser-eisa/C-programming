#ifndef __LOCALSYSTEM__
#define __LOCALSYSTEM__

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stdTypedef.h"


/*
function displays hospital welcome screen.
it takes pointer to select variable and return nothing
*/
void hospital_welcome_screen(uint8* selection);


/*
function changes layout of the console
*/
void change_theme(void);
/*function returns a random number generated to be the hospital's id*/
uint64 random_hospital_id(void);




#endif // __LOCALSYSTEM__
