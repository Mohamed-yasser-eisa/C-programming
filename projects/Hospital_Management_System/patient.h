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
function takes patient's details and save it in database
*/
void patient_reserve_appointment(void);


/*
function scans patient's national id and search for it in database
returns '0' if patient is founded
returns '1' if patient is not founded
returns '0xFF' if patients' database is not founded
*/
uint8 patient_check_n_id(void);

/*
function prints patients follow up visit details and adds fees to patient's data.
*/
void patient_follow_up(void);

/*
function display all patients' data from database.
*/
void patient_view_data(void);

/*
function prints patient's data
*/
void patient_print_data(PATIENT* d);

void patient_edit_data(void);


#endif // __PATIENT__

