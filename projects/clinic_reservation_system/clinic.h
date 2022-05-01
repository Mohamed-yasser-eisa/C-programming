#ifndef CLINIC_H_INCLUDED
#define CLINIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "stdTypedef.h"
#include "patient.h"

extern uint16 pass_word;
extern char clinic_Name[50];;


/*
function setup clinic informations
*/
void clinic_setup(void);

/*
function view clinic informations
*/
void clinic_view_info(void);


#endif // CLINIC_H_INCLUDED


