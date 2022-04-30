#include "patient.h"


PATIENT p1;



const char* dateFormat = "%i/%i/%i";
const char* timeFormat = "%i/%i";


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
    puts("(3) Inquire.\n");
    puts("(4) Emergency case.\n");
    puts("-----------------------------------------");
    fflush(stdin);
    scanf("%i", option); // or: &(*option)
}


void patient_reserve_appointment(void)
{
    uint8 option = 1;
    system("cls");
    puts("\nPatient reserve an appointment screen:");
    puts("_______________________________________\n");

    puts("Please enter patient's data:");
    puts("-----------------------------------------\n");
    patient_get_data(&p1);  //get data from patient
    puts("-----------------------------------------\n");
    puts("Your data are:\n");
    patient_print_data(&p1);

    while(0 != option)
    {
        puts("\n-----------------------------------------\n");
        puts("Please chose an option:");
        puts("------------------------------------");
        puts("(1) Save data to database.");
        puts("(2) Re-enter data.");
        puts("(3) Return main menu and don't save.");
        puts("------------------------------------");
        printf("option: ");
        fflush(stdin);
        scanf("%i", &option);

        if(1 == option)
        {
            //Save data to database
            if(0 == database_save_patient(&p1))
            {
                puts("Patient's data are saved successfully in patient.pdf database file.");
                printf("Please press any key to return main menu...");
                fflush(stdin);
                getch();
                option = 0;
            }
            else
            {
                //new database is created
                puts("New database file is created successfully!");
                puts("Your data are stored in the new database.");
                printf("Please press any key to return main menu...");
                fflush(stdin);
                getch();
                option = 0; //terminate while loop and return to main menu
            }
        }
        else if(2 == option)
        {
            //Re-enter data
            puts("-----------------------------------------\n");
            patient_get_data(&p1);  //get data from patient
            puts("-----------------------------------------\n");
            puts("Your data are:\n");
            patient_print_data(&p1);
        }
        else
        {
            //return main menu.
            option = 0; //stop while and exit function to main.
        }

    }//end of while(0 != option);

}//end of patient_reserve_appointment();

void patient_get_data(PATIENT* d)
{
    uint16 day = 0;
    uint8 gt = 0;
    uint16 month = 0;
    uint8 hr = 0;
    uint8 min = 0;
    uint16 year = 0;

    printf("Patient's name...................: ");
    fflush(stdin);
    fgets((d->nam), sizeof(d->nam), stdin);
    (d->nam)[strlen(d->nam)-1] = '\0';

    printf("Patient's gender.................: ");
    fflush(stdin);
    fgets((d->gen), sizeof(d->gen), stdin);
    (d->gen)[strlen(d->gen)-1] = '\0';

    printf("Wanted specialization............: ");
    fflush(stdin);
    fgets((d->spe), sizeof(d->spe), stdin);
    (d->spe)[strlen(d->spe)-1] = '\0';

    printf("Does patient has insurance? (Y/N): ");
    fflush(stdin);
    scanf("%c", &(d->insurance));

    printf("Patient's age....................: ");
    fflush(stdin);
    scanf("%i", &(d->age));

    printf("Patient's national id............: ");
    fflush(stdin);
    scanf("%llu", &(d->n_id));

    printf("Patient's phone number...........: ");
    fflush(stdin);
    scanf("%llu", &(d->pho));

    printf("Date (DD/MM/YYYY)................: ");
    scanf("%c%i/%i/%i", &gt,&day, &month, &year);
    sprintf(d->dat, dateFormat, day, month, year);


    printf("Time (HH/MM).....................: ");
    scanf("%c%i/%i", &gt, &min, &hr);
    sprintf(d->tim, timeFormat, min, hr);

    printf("Patient's symptoms...............: ");
    fflush(stdin);
    fgets((d->sym), sizeof(d->sym), stdin);
    (d->sym)[strlen(d->sym)-1] = '\0';

}

void patient_print_data(PATIENT* d)
{
    printf("Patient's name.......: %s\n", d->nam);
    printf("Patient's gender.....: %s\n", d->gen);
    printf("Wanted specialization: %s\n", d->spe);
    printf("Patient's age........: %i\n", d->age);
    printf("Patient's national id: %i\n", d->n_id);
    printf("Patient's phone......: 0%i\n", d->pho);
    printf("Date.................: %s\n", d->dat);
    printf("Time.................: %s\n", d->tim);
    printf("Patient's symptoms...: %s\n", d->sym);
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
    /*now we want to open doctor.pdf file and read doctors' id to check if
    this doctor is in our hospital or not; */
    result = database_check_pa_n_id(n_id, &p1);
    return result;
}
