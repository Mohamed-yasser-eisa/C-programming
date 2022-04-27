#include "database.h"

/*array of characters to store file's name in it*/
const char* file_doctor = "doctors.pdf";

/*array of char to store JSON serialization format in it, to use in data writing*/
const char* dr_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tSpecialization: \"%s\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: %llu,\n\tSalary: %0.3f\n}\n";

uint8 database_save_doctor(DOCTOR *dr)
{
    uint8 flag = 0;
    FILE* file_dr;
    file_dr = fopen(file_doctor, "a");
    if(NULL == file_dr)
    {
        file_dr = fopen(file_doctor, "w");
        flag = 1;
    }
    fprintf(file_dr, dr_w_format, dr->nam, dr->gen, dr->spe, dr->n_id, dr->h_id, dr->pho, dr->sal);
    fclose(file_dr);
    /*(flag==1) function could n't find file.pdf, or it is protected to write,
    so it created new file.pdf */

    return flag;
}
