#ifndef __STRUCTS__
#define __STRUCTS__

#include "stdTypedef.h"


typedef struct
{
    uint32 offset_bytes; //if you removed this variable, your data will not be saved correctly in database.
    char nam[22]; //name
    char gen[11]; //gender
    char spe[21]; //specialization
    uint64 n_id; //national_id
    uint64 h_id; //hospital_id
    uint64 pho; //phone
    float64 sal; //salary
}DOCTOR;




#endif // __STRUCTS__


