#include "patient.h"


PATIENT p1;



const char* dateFormat = "%i/%i/%i";
const char* timeFormat = "%i/%i";


void patient_welcome_screen(uint8* option)
{
    system("cls");
    puts("\nPatient's welcome screen");
    puts("________________________\n");

    puts("Please select from the following options:");
    puts("-----------------------------------------\n");
    puts("(1) First visit.\n");
    puts("(2) Follow up.\n");
    puts("(3) Inquire.\n");
    puts("(4) Emergency case.\n");
    puts("-----------------------------------------");
    fflush(stdin);
    scanf("%i", option);
}

uint8 patient_selection(uint8* selection)
{
    switch(*selection)
    {
        case 1:
            //call first visit function
            patient_first_visit(&p1);
            break;
        case 2:
            //call follow up function
            break;
        case 3:
            //call Inquire function
            break;
        case 4:
            //call emergency function
            break;
        default:
            //wrong choice
            return 0;
            break;
    }
}

void patient_first_visit(PATIENT* p)
{
    system("cls");
    puts("\nPatient's first visit screen");
    puts("______________________________\n");

    puts("Please enter patient's data:");
    puts("-----------------------------------------\n");
    patient_get_data(p);
    puts("-----------------------------------------\n");
    puts("Your data are:\n");
    patient_print_data(&p1);
    puts("-----------------------------------------\n");
    puts("Please chose an option:");
    puts("------------------------------------");
    puts("(1) Save data to database.");
    puts("(2) Edit your data.");
    puts("(3) Return main menu and don't save.");
    puts("------------------------------------");
    fflush(stdin);
    getch();
    //////*******************************
}

void patient_get_data(PATIENT* d)
{
    uint16 day = 0;
    uint8 gt = 0;
    uint16 month = 0;
    uint8 hr = 0;
    uint8 min = 0;
    uint16 year = 0;

    printf("Patient's name: ");
    fflush(stdin);
    fgets((d->nam), sizeof(d->nam), stdin);
    (d->nam)[strlen(d->nam)-1] = '\0';

    printf("Patient's gender: ");
    fflush(stdin);
    fgets((d->gen), sizeof(d->gen), stdin);
    (d->gen)[strlen(d->gen)-1] = '\0';

    printf("Wanted specialization: ");
    fflush(stdin);
    fgets((d->spe), sizeof(d->spe), stdin);
    (d->spe)[strlen(d->spe)-1] = '\0';

    printf("Does patient has insurance? (Y/N): ");
    fflush(stdin);
    scanf("%c", &(d->insurance));

    printf("Patient's Age: ");
    fflush(stdin);
    scanf("%i", &(d->age));

    printf("Patient's National id: ");
    fflush(stdin);
    scanf("%llu", &(d->n_id));

    printf("Patient's phone number: ");
    fflush(stdin);
    scanf("%llu", &(d->pho));

    printf("Date (DD/MM/YYYY): ");
    scanf("%c%i/%i/%i", &gt,&day, &month, &year);
    sprintf(d->dat, dateFormat, day, month, year);


    printf("Time (HH/MM): ");
    scanf("%c%i/%i", &gt, &min, &hr);
    sprintf(d->tim, timeFormat, min, hr);

    printf("Patient's symptoms: ");
    fflush(stdin);
    fgets((d->sym), sizeof(d->sym), stdin);
    (d->sym)[strlen(d->sym)-1] = '\0';

}

void patient_print_data(PATIENT* d)
{
    printf("Patient's name: %s\n", d->nam);
    printf("Patient's gender: %s\n", d->gen);
    printf("Wanted specialization: %s\n", d->spe);
    printf("Patient's age: %i\n", d->age);
    printf("Patient's national id: %i\n", d->n_id);
    printf("Patient's phone: %i\n", d->pho);
    printf("Date: %s\n", d->dat);
    printf("Time: %s\n", d->tim);
    printf("Patient's symptoms: %s\n", d->sym);
}
