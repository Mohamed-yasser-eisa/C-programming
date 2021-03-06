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
    float64 cons_fees; //consultancy fees
}DOCTOR;

typedef struct
{
    uint32 offset_bytes; //if you removed this variable, your data will not be saved correctly in database.
    char nam[22]; //name
    char gen[11]; //gender
    char spe[21]; //specialization to appoint a doctor
    char sym[256]; //symptoms of the pain

    char rep[256]; //report from doctor
    char med[256]; //medicine from doctor
    char fUP[256]; //follow up visit

    char insurance; //does the patient has insurance or not (Y/N);
    uint8 age;
    uint64 n_id; //national_id
    uint64 pho; //phone
    float32 fees;

}PATIENT;



#endif // __STRUCTS__


