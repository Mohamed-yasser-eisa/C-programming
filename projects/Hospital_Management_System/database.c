#include "database.h"

/*array of characters to store file's name in it*/
const char* file_doctor = "database_data\\doctors.pdf";
const char* file_patient = "database_data\\patients.pdf";

/*array of char to store JSON serialization format in it, to use in data writing*/
const char* dr_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tSpecialization: \"%s\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: 0%llu,\n\tSalary: %0.3f\n\t"
            "consultancy fees: %0.3f\n}\n";


const char* pa_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tWanted specialization: \"%s\",\n\tNational id: "
            "%llu,\n\tDate: %s\n\tTime: %s\n\tPhone: 0%llu,"
            "\n\tInsurance: %c\n\tAge: %i\n\tSymptoms: \"%s\",\n\t"
            "Report: \"%s\",\n\tMedicine: \"%s\",\n\tNext follow up date: %s,\n\t"
            "Next follow up time: %s\n}\n";


/*array of char to store JSON de-serialization format in it, to use in data reading*/
const char* dr_r_format = "\n\tName: \"%[^\"]\",\n\tGender:"
            " \"%[^\"]\",\n\tSpecialization: \"%[^\"]\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: 0%llu,\n\tSalary: %lf\n\t"
            "consultancy fees: %lf";

const char* pa_r_format = "\n\tName: \"%[^\"]\",\n\tGender:"
            " \"%[^\"]\",\n\tWanted specialization: \"%[^\"]\",\n\tNational id: "
            "%llu,\n\tDate: %[^\n]\n\tTime: %[^\n]\n\tPhone: 0%llu,"
            "\n\tInsurance: %c\n\tAge: %i\n\tSymptoms: \"%[^\"]\",\n\t"
            "Report: \"%[^\n]\",\n\tMedicine: \"%[^\n]\",\n\tNext follow up"
            " date: %[^\n],\n\tNext follow up time: %[^\n]";

uint8 database_save_doctor(DOCTOR *dr)
{
    uint8 flag = 0;
    FILE* file_dr;
    file_dr = fopen(file_doctor, "a");
    if(NULL == file_dr)
    {
        //file not found, create new database
        file_dr = fopen(file_doctor, "w");
        flag = 1;
    }
    fprintf(file_dr, dr_w_format, dr->nam, dr->gen, dr->spe, dr->n_id, dr->h_id, dr->pho, dr->sal, dr->cons_fees);
    fclose(file_dr);
    /*(flag==1) function could n't find file.pdf, or it is protected to write,
    so it created new file.pdf */

    return flag;
}

uint8 database_check_dr_id(uint64 hospital_id, DOCTOR *dr_id)
{
    uint8 flag = 0xff;
    uint8 stop = 1;
    FILE* file_open;

    file_open = fopen(file_doctor, "r");//open database for reading operation
    if(NULL == file_open)
    {
        //database is deleted or cannot be opened!
        //return database is not founded
        flag = 0xff;
    }//end of if(NULL == file_open);
    else
    {
        //database is founded and ready for reading operations:
        fseek(file_open, 0, SEEK_SET); //set cursor to the beginning of database file.
        char cursor_at = 't';
        while(stop)//while stop ==1 then continue looping;
        {
            cursor_at = 'n';
            while ( ((char)cursor_at != (char)'{') )
            {
                cursor_at = getc(file_open);
                if(EOF == cursor_at)//end of file is reached
                {
                    break;
                }
            }//end of while ( (char)cursor_at != (char)'{' );

            /*read this doctor's data*/
            fscanf(file_open, dr_r_format, &dr_id->nam, &dr_id->gen, &dr_id->spe, &dr_id->n_id, &dr_id->h_id, &dr_id->pho, &dr_id->sal, &dr_id->cons_fees);
            /*check if this is the wanted doctor's data or not*/
            if( hospital_id == (dr_id->h_id) )
            {
                //doctor is founded;
                stop = 0; //stop searching and exit while(stop) loop;
                flag = 1; //return '1' to the calling function.
            }//end of if;

            if(EOF == cursor_at)//end of file is reached?
            {
                //end of file is reached and doctor is not founded!
                stop = 0; //stop searching and exit while(stop) loop;
                flag = 0; //return '0' to the calling function.
            }
        }//end of while(stop);
    }//end of else;
    return flag; //return search result.
}// end of database_check_dr_id();


uint8 database_save_patient(PATIENT *pa)
{
    uint8 flag = 0;
    FILE* file_pa;
    file_pa = fopen(file_patient, "a");
    if(NULL == file_pa)
    {
        //file not found, create new database file for patients
        file_pa = fopen(file_patient, "w");
        flag = 1;
    }
    fprintf(file_pa, pa_w_format, pa->nam, pa->gen, pa->spe, pa->n_id, pa->dat, pa->tim, pa->pho, pa->insurance, pa->age, pa->sym);
    fclose(file_pa);
    /*(flag==1) function could n't find file.pdf, or it is protected to write,
    so it created new file.pdf */

    return flag;
}


uint8 database_check_pa_n_id(uint64 n_id, PATIENT* pa)
{
    uint8 flag = 0xff;
    uint8 stop = 1;
    FILE* file_open;
    file_open = fopen(file_patient, "r");//open database for reading operation
    if(NULL == file_open)
    {
        //database is deleted or cannot be opened!
        //return database is not founded
        flag = 0xff;
    }//end of if(NULL == file_open);
    else
    {
        //database is founded and ready for reading operations:
        fseek(file_open, 0, SEEK_SET); //set cursor to the beginning of database file.
        char cursor_at = 't';
        while(stop)//while stop == 1 then continue looping;
        {
            cursor_at = 'n';
            while ( ((char)cursor_at != (char)'{') )
            {
                cursor_at = getc(file_open);
                if(EOF == cursor_at)//end of file is reached
                {
                    break;
                }
            }//end of while ( (char)cursor_at != (char)'{' );
            /*read this doctor's data*/
            fscanf(file_open, pa_r_format, &pa->nam, &pa->gen, &pa->spe, &pa->n_id, &pa->dat, &pa->tim, &pa->pho, &pa->insurance, &pa->age, &pa->sym,&pa->rep,&pa->med,&pa->fdat,&pa->ftim);
            /*check if this is the wanted doctor's data or not*/
            if( n_id == (pa->n_id) )
            {
                //patient is founded;
                stop = 0; //stop searching and exit while(stop) loop;
                flag = 1; //return '1' to the calling function.
            }//end of if;

            if(EOF == cursor_at)//end of file is reached?
            {
                //end of file is reached and patient is not founded!
                stop = 0; //stop searching and exit while(stop) loop;
                flag = 0; //return '0' to the calling function.
            }
        }//end of while(stop);
    }//end of else;
    return flag; //return search result.
}

/*
function writes follow up visit for the patient
*/
void database_patient_follow_up(uint64 national_id)
{
    FIEL* open_file;
    open_file = fopen(file_patient, "a");
    //file will be opened,because it is previously opened for patient id check.

}





