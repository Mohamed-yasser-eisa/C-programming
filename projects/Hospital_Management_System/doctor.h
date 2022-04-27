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



/*function returns '1' if the doctor works in the hospital, and '2' if new doctor*/
uint8 doctor_login_screen(void);
/*function edit doctor's data*/
void doctor_edit_data(DOCTOR* Edata);
/*function gets doctor's data from user*/
void doctor_enter_data(DOCTOR* Rdata);


void doctor_view_data(DOCTOR* Vdata);

void doctor_check_id(void);
void doctor_add_new(void);





#endif // __LOCALSYSTEM__

