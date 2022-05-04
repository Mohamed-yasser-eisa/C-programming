#ifndef __LOCALSYSTEM__
#define __LOCALSYSTEM__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "stdTypedef.h"
#include "hospital_structs.h"
#include "database.h"
#include "local_system.h"



/*function returns '1' if the doctor works in the hospital, and '2' if new doctor.*/
uint8 doctor_login_screen(void);

/*function gets doctor's data from user.*/
void doctor_enter_data(DOCTOR* Rdata);

/*
function checks doctor's id is in database or not.
if returned '0' doctor not founded
if returned '1' doctor is founded
if returned '0xff' doctor.pdf not founded
*/
uint8 doctor_check_id(void);

/*
function prints doctor's data from database.
*/
void doctor_view_data(DOCTOR* Vdata);

/*
function reads input data from screen and add it to database
*/
void doctor_add_new(void);

/*
function welcome doctor and prints options on screen for him.
it returns number of selected option
*/
void doctor_welcome_screen(uint8* option);


/*
function prints patient's data, and writes: (appointment - medicine - write a report);
*/
void doctor_follow_up(void);



#endif // __LOCALSYSTEM__

