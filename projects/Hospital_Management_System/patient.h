#ifndef __PATIENT__
#define __PATIENT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "stdTypedef.h"
#include "hospital_structs.h"
#include "database.h"

/*
function prints options for patient and takes the selection.
*/
void patient_welcome_screen(uint8* option);
/*
function takes selection and call the proper function for that selection
returns '0' in case of wrong choice
*/
uint8 patient_selection(uint8* selection);
/*
function takes patient's data
*/
void patient_first_visit(PATIENT* p);
/*
function gets patient's data
*/
void patient_get_data(PATIENT* d);
/*
function prints patient's data
*/
void patient_print_data(PATIENT* d);


#endif // __PATIENT__

