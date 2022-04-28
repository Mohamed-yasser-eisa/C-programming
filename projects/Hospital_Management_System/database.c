#include "database.h"

/*array of characters to store file's name in it*/
const char* file_doctor = "doctors.pdf";

/*array of char to store JSON serialization format in it, to use in data writing*/
const char* dr_w_format = "{\n\tName: \"%s\",\n\tGender:"
            " \"%s\",\n\tSpecialization: \"%s\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: %llu,\n\tSalary: %0.3f\n\t"
            "consultancy fees: %0.3f\n}\n";
/*array of char to store JSON deserialization format in it, to use in data reading*/
const char* dr_r_format = "\n\tName: \"%[^\"]\",\n\tGender:"
            " \"%[^\"]\",\n\tSpecialization: \"%[^\"]\",\n\tNational id: "
            "%llu,\n\tHospital id: %llu,\n\tPhone: %llu,\n\tSalary: %lf\n\t"
            "consultancy fees: %lf";


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

    file_open = fopen(file_doctor, "r");
    if(NULL == file_open) //doctor.pdf not found
    {
        flag = 0xff;
    }//end of if(NULL == file_open);
    else //doctor.pdf is found and ready for reading from it:
    {
        fseek(file_open, 0, SEEK_SET); //set cursor to the beginning of text file.
        char c = 't';
        while(stop)//while stop ==1 then continue looping;
        {
            /*for debugging: printf("I'm searching for %llu\n", hospital_id);*/
            c = 'n';
            while ( ((char)c != (char)'{') )
            {
                c = getc(file_open);
                if(c==EOF)//end of file is reached
                {
                    break;
                }
            }//end of while ( (char)c != (char)'{' );
            /*read this doctor's data*/
            /*for debugging:puts("I'm inside while(stop)");*/
            //read data from txt file in format_read.
            fscanf(file_open, dr_r_format, &dr_id->nam, &dr_id->gen, &dr_id->spe, &dr_id->n_id, &dr_id->h_id, &dr_id->pho, &dr_id->sal, &dr_id->cons_fees);

            if( hospital_id == (dr_id->h_id) )
            {
                //printf("doctor is founded");
                /*
                printf("Doctor's name          : %s\n", dr_id->nam);
                printf("Doctor's gender        : %s\n", dr_id->gen);
                printf("Doctor's specialization: %s\n", dr_id->spe);
                printf("Doctor's national_id   : %llu\n", dr_id->n_id);
                printf("Doctor's phone         : %llu\n", dr_id->pho);
                printf("Doctor's salary        : %0.3f\n", dr_id->sal);
                printf("Doctor's hospital_id   : %llu\n", dr_id->h_id);
                */
                //fflush(stdin);
                //getch();
                stop = 0;
                flag = 1;
            }//end of if;
            if( c == EOF) //end of file is reached
            {
                printf("Doctor is not founded");
                fflush(stdin);
                getch();
                stop = 0;
                flag = 0;
            }
        }//end of while(stop);
    }//end of else;
    return flag;
}// end of database_check_dr_id();
