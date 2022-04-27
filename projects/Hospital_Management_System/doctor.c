#include "doctor.h"

uint8 doctor_login_screen(void)
{
    uint8 select = 0;
    system("cls");

    puts("Doctor's login screen:");
    puts("______________________\n");

    puts("(1) Doctor in the hospital.");
    puts("(2) New doctor.");
    puts("-----------------------");

    fflush(stdin);
    scanf("%i", &select);
    return select;
}

void doctor_add_new(void)
{
    DOCTOR d1;
    uint8 select = 0;
    system("cls");

    puts("Welcome to Egypt hospital");
    puts("_________________________\n");

    doctor_enter_data(&d1); // get data from user

    puts("Your data are:");
    puts("===================================");
    doctor_view_data(&d1); //print doctor's data on screen
    puts("===================================");
    puts("Please chose an option:");
    puts("-----------------------\n");
    puts("(1) Save data in database.");
    puts("(2) Edit data.");
    puts("(3) Return main menu.");
    puts("-----------------------\n");
    fflush(stdin);
    scanf("%i", &select);
    switch(select)
    {
        case 1:
            //save data
            database_save_doctor(&d1);
            break;
        case 2:
            //edit data
            break;
        case 3:
            //return main menu
            break;
        default:
            //don't save and return main menu.
            break;
    }


}

void doctor_enter_data(DOCTOR* Rdata)
{
    /* Please note that "->" and "[]" have same precedence and executed "left to right" */
    printf("Please enter doctor's name: ");
    fflush(stdin);
    fgets((Rdata->nam), sizeof(Rdata->nam), stdin);
    (Rdata->nam)[strlen(&(Rdata->nam))-1] = '\0';

    printf("Please enter gender: ");
    fflush(stdin);
    fgets(Rdata->gen, sizeof(Rdata->gen), stdin);
    (Rdata->gen)[strlen(&(Rdata->gen))-1] = '\0';

    printf("Please enter specialization: ");
    fflush(stdin);
    fgets(d1.spe, sizeof(d1.spe), stdin);
    d1.spe[strlen(&(d1.spe))-1] = '\0';

    printf("Please enter national Id: ");
    fflush(stdin);
    scanf("%llu", &d1.n_id);

    d1.h_id = random_hospital_id();

    printf("Please enter phone: ");
    fflush(stdin);
    scanf("%llu", &d1.pho);

    printf("Please enter salary: ");
    fflush(stdin);
    scanf("%lf", &d1.sal);
    puts("-------------------------------------------------");
}

void doctor_view_data(DOCTOR* Vdata)
{
    printf("Doctor's name: %s\n", Vdata->nam);
    printf("Doctor's gender: %s\n", Vdata->gen);
    printf("Doctor's specialization: %s\n", Vdata->spe);
    printf("Doctor's national_id: %llu\n", Vdata->n_id);
    printf("Doctor's phone: %llu\n", Vdata->pho);
    printf("Doctor's salary: %0.3f\n", Vdata->sal);
    printf("Doctor's hospital_id: %llu\n", Vdata->h_id);
}



void doctor_edit_data(DOCTOR* Edata)
{

}
