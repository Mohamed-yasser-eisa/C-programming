#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stdTypedef.h"
#include "clinic.h"
#define ArraySize 2

typedef struct
{
    char name[22];
    uint8 row;
    uint32 age;
    uint64 phone;
    float32 paidFees;
}Patient;


/*
function reserve new patient.
return '1' if max number of patient's is reached.
return '0' if patient's data are reserved.
*/
uint8 patient_reserve(void);
/*
function view patient's details.
*/
void patient_view(void);
/*
function edit patient's details.
*/
void patient_edit(void);
/*
function delete patient's details.
*/
void patient_delete(void);
/*
function returns number of patients in the clinic:
*/
uint8 patient_get_number(void);
#endif // PATIENT_H_INCLUDED

