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
function takes patient's data
*/
void patient_reserve_appointment(void);
/*
function gets patient's data
*/
void patient_get_data(PATIENT* d);
/*
function prints patient's data
*/
void patient_print_data(PATIENT* d);
/*

*/
uint8 patient_check_n_id(void);


#endif // __PATIENT__

