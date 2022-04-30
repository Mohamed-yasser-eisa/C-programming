#ifndef __DATABASE__
#define __DATABASE__

#include <stdio.h>
#include "stdTypedef.h"
#include "hospital_structs.h"

/*
function saves doctor's data to "doctor.pdf" file
it returns '0' if file is found and data are written successfully
it returns '1' if it created new file to save data in it
*/
uint8 database_save_doctor(DOCTOR *dr);

/*
function check doctor's id:
returns '1' if doctor is found, and returns data of this doctor to be ready.
returns '0' if doctor is not found.
returns '0xff' if doctors.pdf file is not found.
*/
uint8 database_check_dr_id(uint64 hospital_id, DOCTOR *dr_id);

/*
function saves patient's data to "patient.pdf" file
it returns '0' if file is found and data are written successfully
it returns '1' if it created new file to save data in it
*/
uint8 database_save_patient(PATIENT *pa);
/*
function returns if patient's national id is in our database or not.
returns '1' if patient is founded, and returns data of this patient to be ready.
returns '0' if patient is not found.
returns '0xff' if patients.pdf file is not found.
*/
uint8 database_check_pa_n_id(uint64 n_id, PATIENT* pa);

#endif // __DATABASE__

