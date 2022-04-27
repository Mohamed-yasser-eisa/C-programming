#ifndef __DATABASE__
#define __DATABASE__

#include <stdio.h>
#include "stdTypedef.h"
#include "hospital_structs.h"

/*function saves doctor's data to "doctor.pdf" file*/
/*it returns '0' if file is found and data are written successfully*/
/*it returns '1' if it created new file to save data in it*/
uint8 database_save_doctor(DOCTOR *dr);




#endif // __DATABASE__

