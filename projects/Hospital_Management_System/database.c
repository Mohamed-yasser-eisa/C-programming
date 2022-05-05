#include "database.h"

/*array of characters to store file's name in it*/
const char* file_doctor = "database_data\\doctors.pdf";
const char* file_patient = "database_data\\patients.pdf";
const char* file_temp = "database_data\\temp.pdf";

/*array of char to store JSON serialization format in it, to use in data writing*/
const char* dr_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tSpecialization: \"%s\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: 0%llu,\n\tSalary: %0.3f\n\t"
            "Consultancy fees: %0.3f\n}\n";


const char* pa_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tWanted specialization: \"%s\",\n\tNational id: "
            "%llu,\n\tPaid fees: %0.3f,\n\tPhone: 0%llu,"
            "\n\tInsurance: %c\n\tAge: %i\n\tSymptoms: \"%s\",\n\t"
            "Report: \"%s\",\n\tMedicine: \"%s\",\n\tFollow up visit: \"%s\"\n}\n";


/*array of char to store JSON de-serialization format in it, to use in data reading*/
const char* dr_r_format = "{\n\tName: \"%[^\"]\",\n\tGender:"
            " \"%[^\"]\",\n\tSpecialization: \"%[^\"]\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: 0%llu,\n\tSalary: %lf\n\t"
            "Consultancy fees: %lf\n";

const char* pa_r_format = "{\n\tName: \"%[^\"]\",\n\tGender:"
            " \"%[^\"]\",\n\tWanted specialization: \"%[^\"]\",\n\tNational id: "
            "%llu,\n\tPaid fees: %f,\n\tPhone: 0%llu,"
            "\n\tInsurance: %c\n\tAge: %i\n\tSymptoms: \"%[^\"]\",\n\t"
            "Report: \"%[^\"]\",\n\tMedicine: \"%[^\"]\",\n\tFollow up visit: "
            "\"%[^\"]\"\n";


/****************** static functions to this file: ***********************************/

static void database_edit_patient(PATIENT* p);

/*************************************************************************************/



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

uint8 database_check_dr_id(uint64 hospital_id, DOCTOR *dr)
{
    uint8 flag = 0;
    FILE* file_open;

    file_open = fopen(file_doctor, "r");//open database for reading operation
    if(NULL == file_open)
    {
        //database is deleted or cannot be opened!
        //return database is not founded
        flag = 104;
    }//end of if(NULL == file_open);
    else
    {
        //database is founded and ready for reading operations:
        fseek(file_open, 0, SEEK_SET); //set cursor to the beginning of database file.
        while( (fgetc(file_open) != EOF) && (1 != flag) )
        {
            fseek(file_open, -1L, SEEK_CUR);
            fscanf(file_open, dr_r_format, &dr->nam, &dr->gen, &dr->spe, &dr->n_id, &dr->h_id, &dr->pho, &dr->sal, &dr->cons_fees);
            if(hospital_id == dr->h_id)
            {
                flag = 1; //doctor is founded. Stop looping
            }
            fseek(file_open, 3L, SEEK_CUR);
        }//end of while
    }//end of else;
    return flag; //return search result.
}// end of database_check_dr_id();


uint8 database_save_patient(PATIENT *pa)
{
    uint8 flag = 0;
    FILE* fpo; //file patient open
    PATIENT temp;
    uint8 old_patient = 0;


    old_patient = database_check_pa_n_id(pa->n_id, &temp);
    if(1 == old_patient)
    {
        //patient is already exist.
        database_edit_patient(pa);
    }
    else //new patient to database
    {
        fpo = fopen(file_patient, "a");
        if(NULL == fpo) //file not found, create new database file for patients
        {
            fpo = fopen(file_patient, "w");
            flag = 1;
        }
        fprintf(fpo, pa_w_format, pa->nam, pa->gen, pa->spe, pa->n_id, pa->fees, pa->pho, pa->insurance, pa->age, pa->sym, pa->rep, pa->med, pa->fUP);
        fclose(fpo);
    }

    /*(flag==1) function could n't find file.pdf, or it is protected to write,
    so it created new file.pdf */

    return flag;
}


uint8 database_check_pa_n_id(uint64 n_id, PATIENT* pa)
{
    uint8 flag = 0;
    FILE* fo; //file open pointer variable

    fo = fopen(file_patient, "r");//open database for reading operation
    if(NULL == fo)
    {
        //database is deleted or cannot be opened!
        //return database is not founded
        flag = 104;
    }//end of if(NULL == fo);
    else
    {
        //database is founded and ready for reading operations:
        fseek(fo, 0, SEEK_SET);
        while( (getc(fo) != EOF) && (1 != flag))//loop until end of file is reached or found patient.
        {
            fseek(fo, -1L, SEEK_CUR);
            /*read this doctor's data*/
            fscanf(fo, pa_r_format, &pa->nam, &pa->gen, &pa->spe, &pa->n_id, &pa->fees, &pa->pho, &pa->insurance, &pa->age, &pa->sym, &pa->rep, &pa->med, &pa->fUP);
            /*check if this is the wanted patient's data or not*/
            if( n_id == (pa->n_id) )
            {
                //patient is founded;
               flag = 1;
            }//end of if;
            fseek(fo, 3L, SEEK_CUR); //stop cursor in front of '}'
        }//end of while();
        if( (1 != flag) &&(104 != flag))
        {
            flag = 0;//patient is not founded
        }
    }//end of else;
    return flag; //return search result.
}

/*
function writes follow up visit for the patient
*/
void database_patient_follow_up(uint64 national_id)
{
    FILE* open_file;
    open_file = fopen(file_patient, "a");
    //file will be opened,because it is previously opened for patient id check.
}


/*function takes new patient's data*/
static void database_edit_patient(PATIENT *p)
{
    FILE* tfile; //temp file
    FILE* pfile; //patient file
    PATIENT tp; //temp patient
    tfile = fopen(file_temp, "w");
    pfile = fopen(file_patient, "r");
    while( (getc(pfile) != EOF) )//loop until end of file is reached or found patient.
        {
            fseek(pfile, -1L, SEEK_CUR);
            fscanf(pfile, pa_r_format, &tp.nam, &tp.gen, &tp.spe, &tp.n_id, &tp.fees, &tp.pho, &tp.insurance, &tp.age, &tp.sym, &tp.rep, &tp.med, &tp.fUP);
            fseek(pfile, 3L, SEEK_CUR); //stop cursor in front of '{'
            /*check if this is the wanted patient's data or not*/
            if( (p->n_id) == (tp.n_id) )
            {
                //don't copy this patient;
                fprintf(tfile, pa_w_format, p->nam, p->gen, p->spe, p->n_id, p->fees, p->pho, p->insurance, p->age, p->sym, p->rep, p->med, p->fUP);
                continue;
            }//end of if;
            fprintf(tfile, pa_w_format, tp.nam, tp.gen, tp.spe, tp.n_id, tp.fees, tp.pho, tp.insurance, tp.age, tp.sym, tp.rep, tp.med, tp.fUP);
        }//end of while();
        fclose(tfile);
        fclose(pfile);
        /*now copy data from temp.pdf to patients.pdf*/
        tfile = fopen(file_temp, "r");
        pfile = fopen(file_patient, "w");
        while ( getc(tfile) != EOF)
        {
            fseek(tfile, -1, SEEK_CUR);
            fputc(getc(tfile), pfile);
        }
        fclose(tfile);
        fclose(pfile);
}//end of database_edit_patient();


/*function takes new patient's data*/
static void database_delete_patient(PATIENT *p)
{
    FILE* tfile; //temp file
    FILE* pfile; //patient file
    PATIENT tp; //temp patient

    tfile = fopen(file_temp, "w");
    pfile = fopen(file_patient, "r");


    while( (getc(pfile) != EOF) )//loop until end of file is reached or found patient.
        {
            fseek(pfile, -1L, SEEK_CUR);
            fscanf(pfile, pa_r_format, &tp.nam, &tp.gen, &tp.spe, &tp.n_id, &tp.fees, &tp.pho, &tp.insurance, &tp.age, &tp.sym, &tp.rep, &tp.med, &tp.fUP);
            fseek(pfile, 3L, SEEK_CUR); //stop cursor in front of '{'
            /*check if this is the wanted patient's data or not*/
            if( (p->n_id) == (tp.n_id) )
            {
                //don't copy this patient; (delete);
               continue;
            }//end of if;
            fprintf(tfile, pa_w_format, tp.nam, tp.gen, tp.spe, tp.n_id, tp.fees, tp.pho, tp.insurance, tp.age, tp.sym, tp.rep, tp.med, tp.fUP);
        }//end of while();
        fclose(tfile);
        fclose(pfile);

        /*now copy data from temp.pdf to patients.pdf*/
        tfile = fopen(file_temp, "r");
        pfile = fopen(file_patient, "w");
        while ( getc(tfile) != EOF)
        {
            fseek(tfile, -1, SEEK_CUR);
            fputc(getc(tfile), pfile);
        }
        fclose(tfile);
        fclose(pfile);
}//end of database_delete_patient();

void database_view_patients(void)
{
    PATIENT tp; //temp variable holds the read data.
    FILE* pf; //pointer to patients' file.
    uint8 counter = 0;

    pf = fopen(file_patient, "r");

    while( getc(pf) != EOF )
    {
        ++counter;
        fseek(pf, -1L, SEEK_CUR);
        fscanf(pf, pa_r_format, &tp.nam, &tp.gen, &tp.spe, &tp.n_id, &tp.fees, &tp.pho, &tp.insurance, &tp.age, &tp.sym, &tp.rep, &tp.med, &tp.fUP);
        puts("-------------------------------------\n");
        printf("Patient number (%u):\n", counter);
        patient_print_data(&tp);
        puts("-------------------------------------\n");
        fseek(pf, 3L, SEEK_CUR);
    }//end of while
    fclose(pf);
}//end of database_view_patients();

void database_view_doctors(void)
{
    DOCTOR tp; //temp variable holds the read data.
    FILE* df; //pointer to doctors' file.
    uint8 counter = 0;

    df = fopen(file_doctor, "r");

    while( getc(df) != EOF )
    {
        ++counter;
        fseek(df, -1L, SEEK_CUR);
        fscanf(df, dr_r_format, &tp.nam, &tp.gen, &tp.spe, &tp.n_id, &tp.h_id, &tp.pho, &tp.sal, &tp.cons_fees);
        puts("-------------------------------------\n");
        printf("Doctor number (%u):\n", counter);
        doctor_print_data(&tp);
        puts("-------------------------------------\n");
        fseek(df, 3L, SEEK_CUR);
    }//end of while
    fclose(df);
}// end of database_view_doctors();











