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
function checks the password is correct or not, and return the selected option:
'1' view doctors' data.
'2' view patients' data.
'3' return main menu.
*/
uint8 system_check_pass(void);

/*
function changes layout of the console
*/
void change_theme(void);
/*function returns a random number generated to be the hospital's id*/
uint64 random_hospital_id(void);




#endif // __LOCALSYSTEM__
