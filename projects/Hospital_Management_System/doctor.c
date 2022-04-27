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
} // end of doctor_login_screen();

void doctor_add_new(void)
{
    DOCTOR d1;
    uint8 select = 0;
    uint8 save_data = 2;
    system("cls");

    puts("You are welcome to Egypt hospital");
    puts("_________________________________\n");

    doctor_enter_data(&d1); // get data from user

    puts("Your data are:");
    puts("===================================");
    doctor_view_data(&d1); //print doctor's data on screen
    puts("===================================");

    while( select != 0xff)
    {
        puts("Please chose an option:");
        puts("-------------------------------------");
        puts("(1) Save data in database.");
        puts("(2) Edit data.");
        puts("(3) Return main menu WITHOUT saving..");
        puts("-------------------------------------");
        fflush(stdin);
        scanf("%i", &select);
        switch(select)
        {
            case 1:
                //save data
                save_data = database_save_doctor(&d1);
                if(0 == save_data)
                {
                    puts("Your data are saved successfully in our database.");
                    puts("Please press any key to return main menu.");
                    fflush(stdin);
                    getch();
                    select = 0xff;
                }//end of if(0 == save_data);

                break;
            case 2:
                //edit data
                doctor_edit_data(&d1);
                doctor_view_data(&d1);
                puts("-------------------------------------");
                break;
            case 3:
                //return main menu
                select = 0xff;
                break;
            default:
                //don't save and return main menu.
                puts("Invalid option!!");
                puts("Please select number from 1 to 3 only.\n");
                break;
        } //end of switch(select);
    } // end of while();



} // end of doctor_add_new();

void doctor_enter_data(DOCTOR* Rdata)
{
    /* Please note that "->" and "[]" have same precedence and executed "left to right" */
    printf("Please enter doctor's name : ");
    fflush(stdin);
    fgets((Rdata->nam), sizeof(Rdata->nam), stdin);
    (Rdata->nam)[strlen(&(Rdata->nam))-1] = '\0';

    printf("Please enter gender        : ");
    fflush(stdin);
    fgets(Rdata->gen, sizeof(Rdata->gen), stdin);
    (Rdata->gen)[strlen(&(Rdata->gen))-1] = '\0';

    printf("Please enter specialization: ");
    fflush(stdin);
    fgets(Rdata->spe, sizeof(Rdata->spe), stdin);
    Rdata->spe[strlen(&(Rdata->spe))-1] = '\0';

    printf("Please enter national Id   : ");
    fflush(stdin);
    scanf("%llu", &(Rdata->n_id));

    Rdata->h_id = random_hospital_id();

    printf("Please enter phone         : ");
    fflush(stdin);
    scanf("%llu", &(Rdata->pho));

    printf("Please enter salary        : ");
    fflush(stdin);
    scanf("%lf", &(Rdata->sal));
    puts("-------------------------------------------------");
}

void doctor_view_data(DOCTOR* Vdata)
{
    printf("Doctor's name          : %s\n", Vdata->nam);
    printf("Doctor's gender        : %s\n", Vdata->gen);
    printf("Doctor's specialization: %s\n", Vdata->spe);
    printf("Doctor's national_id   : %llu\n", Vdata->n_id);
    printf("Doctor's phone         : %llu\n", Vdata->pho);
    printf("Doctor's salary        : %0.3f\n", Vdata->sal);
    printf("Doctor's hospital_id   : %llu\n", Vdata->h_id);
}

void doctor_edit_data(DOCTOR* Edata)
{
    doctor_enter_data(Edata);
}

uint8 doctor_check_id(void)
{
    DOCTOR dr2;
    uint64 id;
    uint8 result = 100;
    uint8 flag = 0xff;
    system("cls");
    printf("Please enter your \"hospital id\": ");
    fflush(stdin);
    scanf("%llu", &id);
    printf("you entered: %llu\n", id);
    /*now we want to open doctor.pdf file and read doctors' id to check if
    this doctor is in our hospital or not; */
    result = database_check_dr_id(id, &dr2);
    if(1 == result)
    {
        //doctor is founded
        flag = 1;
    }
    else if(0 == result)
    {
        flag = 0;
    }
    else if(0xff == result)
    {
        flag = 0xff;
    }
    return flag;

}// end of doctor_check_id();



