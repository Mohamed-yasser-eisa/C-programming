#include "patient.h"


PATIENT p1;


/************** local functions to this file: ********************************/

/*
function gets patient's data
*/
static void patient_get_data(PATIENT* d);




/******************************************************************************/


/*function takes option, and return it to main*/
void patient_welcome_screen(uint8* option)
{
    system("cls");
    puts("\nPatient welcome screen");
    puts("________________________\n");

    puts("Please select from the following options:");
    puts("-----------------------------------------\n");
    puts("(1) Reserve an appointment.\n");
    puts("(2) Follow up.\n");
    puts("-----------------------------------------");
    fflush(stdin);
    scanf("%i", option); // or: &(*option)
}


void patient_reserve_appointment(void)
{
    uint8 option = 1;
    uint8 select = 1;

    system("cls");
    puts("\nPatient reserve an appointment screen:");
    puts("_______________________________________\n");

    puts("Please enter patient's data:");
    puts("-----------------------------------------\n");
    patient_get_data(&p1);  //get data from patient
    sprintf(p1.rep, "Not determined");
    sprintf(p1.med, "Not determined");
    sprintf(p1.fUP, "Not determined");
    puts("-----------------------------------------\n");
    puts("Your data are:\n");
    patient_print_data(&p1);

    while(0 != option)
    {
        puts("\n-----------------------------------------\n");
        puts("Please chose an option:");
        puts("------------------------------------");
        puts("(1) Save data to database.");
        puts("(2) Don't save and re-enter data.");
        puts("(3) Return main menu and don't save.");
        puts("------------------------------------");
        printf("Option: ");
        fflush(stdin);
        scanf("%i", &select);

        if(1 == select) //Save data to database
        {
            if(0 == database_save_patient(p1.n_id ,&p1))
            {
                puts("Patient's data are saved successfully in patient.pdf database file.");
            }
            else //new database is created
            {
                puts("No database file is founded!");
                puts("New database file is created successfully!");
                puts("Your data are stored in the new database file.");
            }
        } //end of if(1 == select);
        else if(2 == option) //Re-enter data
        {
            puts("-----------------------------------------\n");
            patient_get_data(&p1);  //get data from patient
            puts("-----------------------------------------\n");
            puts("Your new data are:\n");
            patient_print_data(&p1);
            option = 1; //don't return main menu, wait until data are saved
        } //end of else if(2 == select);
        else //return main menu.
        {
            printf("Please press any key to return main menu...");
            fflush(stdin);
            getch();
            option = 0; //stop while and exit function to main.
        }
    }//end of while(0 != option);

}//end of patient_reserve_appointment();

static void patient_get_data(PATIENT* d)
{
    printf("Patient's name...................: ");
    fflush(stdin);
    fgets((d->nam), sizeof(d->nam), stdin);
    (d->nam)[strlen(d->nam)-1] = '\0'; //replace new line or last character by NULL

    printf("Patient's gender.................: ");
    fflush(stdin);
    fgets((d->gen), sizeof(d->gen), stdin);
    (d->gen)[strlen(d->gen)-1] = '\0'; //replace new line or last character by NULL

    printf("Wanted specialization............: ");
    fflush(stdin);
    fgets((d->spe), sizeof(d->spe), stdin);
    (d->spe)[strlen(d->spe)-1] = '\0'; //replace new line or last character by NULL

    printf("Does patient has insurance? (Y/N): ");
    fflush(stdin);
    scanf("%c", &(d->insurance));

    printf("Paid fees........................: ");
    fflush(stdin);
    scanf("%f", &(d->fees));

    printf("Patient's age....................: ");
    fflush(stdin);
    scanf("%i", &(d->age));

    printf("Patient's national id............: ");
    fflush(stdin);
    scanf("%llu", &(d->n_id));

    printf("Patient's phone number...........: ");
    fflush(stdin);
    scanf("%llu", &(d->pho));

    printf("Patient's symptoms...............: ");
    fflush(stdin);
    fgets((d->sym), sizeof(d->sym), stdin);
    (d->sym)[strlen(d->sym)-1] = '\0'; //replace new line or last character by NULL

}

void patient_print_data(PATIENT* d)
{
    printf("Patient's name.......: %s\n", d->nam);
    printf("Patient's gender.....: %s\n", d->gen);
    printf("Wanted specialization: %s\n", d->spe);
    printf("Patient's age........: %i\n", d->age);
    printf("Patient's national id: %i\n", d->n_id);
    printf("Patient's phone......: 0%i\n", d->pho);
    printf("Paid fees............: %0.3f\n", d->fees);
    printf("Patient's symptoms...: %s\n", d->sym);
    printf("Patient's report.....: %s\n", d->rep);
    printf("Patient's medicine...: %s\n", d->med);
    printf("Follow up visit......: %s\n", d->fUP);
}

uint8 patient_check_n_id(void)
{
    uint64 n_id;
    uint8 result = 0;
    uint8 flag = 0xff;

    system("cls");
    puts("\nPatient check \"National id\" screen:");
    puts("_____________________________________\n");

    printf("Please enter your \"National id\": ");
    fflush(stdin);
    scanf("%llu", &n_id);
    puts("------------------------------------\n");
    printf("Search result for: (%llu) is:\n\n", n_id);
    /*now we want to open patient.pdf file and read patients' id to check if
    this patient is in our hospital or not; */
    result = database_check_pa_n_id(n_id, &p1);
    return result;
}

void patient_follow_up(void)
{
    float32 fees = 0.0;

    system("cls");
    puts("\nPatient follow up screen:");
    puts("____________________________\n");
    printf("Patient's follow up details: \"%s\"\n\n", p1.fUP);
    printf("Patient's total paid fees = (%0.3f)\n\n", p1.fees);
    puts("Please pay the \"follow up visit's fees\".\n\n");
    printf("Paid fees: ");
    scanf("%f", &fees);
    p1.fees += fees;
    database_save_patient(p1.n_id, &p1); //overwrite old patient's data
    printf("Patient's total paid fees = (%0.3f)\n\n", p1.fees);
}

void patient_view_data(void)
{
    puts("Patients' data in database are:\n");
    database_view_patients();
}

void patient_edit_data(void)
{
    uint64 old_id;
    uint8 founded;
    founded = patient_check_n_id();
    if(1 == founded)
    {
        old_id = p1.n_id;
        system("cls");
        puts("\nPatient edit data screen:");
        puts("_____________________________\n");
        puts("Please enter new patient's data:\n");
        patient_get_data(&p1);
        database_edit_patient(old_id ,&p1);
        puts("================================");
        puts("Patient's new data are:\n");
        patient_print_data(&p1);
    }
    else
    {
        puts("\n-->Patient not founded!\n");
    }
}


