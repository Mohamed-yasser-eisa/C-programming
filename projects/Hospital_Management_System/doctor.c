#include "doctor.h"


DOCTOR dr2;
PATIENT p2;

/********************** static functions: ***********************************/
static void follow_up_visit(uint64 national_id)
{
    p2->fUP
}






/*********************************************************/

uint8 doctor_login_screen(void)
{
    uint8 select = 0;
    system("cls");
    puts("\nDoctor login screen:");
    puts("_____________________\n");

    puts("Please select from the following options:");
    puts("-----------------------------------------\n");
    puts("(1) Doctor in the hospital.\n");
    puts("(2) New doctor.\n");
    puts("-----------------------------------------\n");
    printf("Option: ");
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
        puts("(2) Re-enter data.");
        puts("(3) Return main menu WITHOUT saving..");
        puts("-------------------------------------");
        fflush(stdin);
        scanf("%i", &select);
        switch(select)
        {
            case 1:
                //save data to database
                save_data = database_save_doctor(&d1);
                if(0 == save_data)
                {
                    puts("--> Your data are saved successfully in our database.");
                    printf("Please press any key to return main menu...");
                    fflush(stdin);
                    getch();
                    select = 0xff; //terminate while loop and return to main menu
                }//end of if(0 == save_data);
                else
                {
                    //new database is created
                    puts("New database file is created successfully!");
                    puts("Your data are stored in the new database.");
                    printf("Please press any key to return main menu...");
                    fflush(stdin);
                    getch();
                    select = 0xff; //terminate while loop and return to main menu
                }
                break;
            case 2:
                //reenter data
                puts("\n-------------------------------------");
                doctor_enter_data(&d1);
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
    printf("Please enter doctor's name...: ");
    fflush(stdin);
    fgets((Rdata->nam), sizeof(Rdata->nam), stdin);
    (Rdata->nam)[strlen(&(Rdata->nam))-1] = '\0';

    printf("Please enter gender..........: ");
    fflush(stdin);
    fgets(Rdata->gen, sizeof(Rdata->gen), stdin);
    (Rdata->gen)[strlen(&(Rdata->gen))-1] = '\0';

    printf("Please enter specialization..: ");
    fflush(stdin);
    fgets(Rdata->spe, sizeof(Rdata->spe), stdin);
    Rdata->spe[strlen(&(Rdata->spe))-1] = '\0';

    printf("Please enter national Id.....: ");
    fflush(stdin);
    scanf("%llu", &(Rdata->n_id));

    Rdata->h_id = random_hospital_id();

    printf("Please enter phone...........: ");
    fflush(stdin);
    scanf("%llu", &(Rdata->pho));

    printf("Please enter salary..........: ");
    fflush(stdin);
    scanf("%lf", &(Rdata->sal));

    printf("Please enter consultancy fees: ");
    fflush(stdin);
    scanf("%lf", &(Rdata->cons_fees));
    puts("-------------------------------------------------");
}

void doctor_view_data(DOCTOR* Vdata)
{
    printf("Doctor's name............: %s\n", Vdata->nam);
    printf("Doctor's gender..........: %s\n", Vdata->gen);
    printf("Doctor's specialization..: %s\n", Vdata->spe);
    printf("Doctor's national_id.....: %llu\n", Vdata->n_id);
    printf("Doctor's phone...........: 0%llu\n", Vdata->pho);
    printf("Doctor's salary..........: %0.3f\n", Vdata->sal);
    printf("Doctor's consultancy fees: %0.3f\n", Vdata->cons_fees);
    printf("Doctor's hospital_id.....: %llu\n", Vdata->h_id);
}


uint8 doctor_check_id(void)
{
    uint64 id;
    uint8 result = 100;
    uint8 flag = 0xff;
    system("cls");
    puts("\nDoctor check \"Hospital id\" screen:");
    puts("____________________________________\n");

    printf("Please enter your \"Hospital id\": ");
    fflush(stdin);
    scanf("%llu", &id);
    puts("------------------------------------\n");
    printf("Search result for: (%llu) is:\n\n", id);
    /*now we want to open doctor.pdf file and read doctors' id to check if
    this doctor is in our hospital or not; */
    result = database_check_dr_id(id, &dr2);
    return result;
}// end of doctor_check_id();

void doctor_welcome_screen(uint8* option)
{
    system("cls");
    puts("\nDoctor Welcome screen");
    puts("_______________________\n");
    printf("Welcome Dr.\"%s\"\n\n", dr2.nam);
    puts("Please select from the following options:");
    puts("-----------------------------------------\n");
    puts("(1) Follow up with a patient.\n");
    puts("(2) View your today's cases.\n");
    puts("(3) Return to main menu\n");
    puts("-----------------------------------------");
    fflush(stdin);
    scanf("%i", &(*option));//(&*option == option), '&' and '*' same precedence, associativity right to left

}

void doctor_follow_up(void)
{
    uint64 id;
    uint8 patientFounded = 0;

    system("cls");
    puts("\nDoctor follow up with patient screen");
    puts("____________________________________\n");
    printf("Please enter patient's national id: ");
    scanf("%llu", &id);
    patientFounded = database_check_pa_n_id(id, &p2);
    switch(patientFounded)
    {
        case 0://patient not founded
            puts("Patient is not founded.");
            break;
        case 1://patient is founded
            uint8 select = 0;
            puts("Patient is founded.\n");
            puts("Please select an option:");
            puts("---------------------------\n");
            puts("(1) Recommend a follow up visit.\n");
            puts("(2) Write a report.\n");
            puts("(3) Describe a medicine.\n");
            puts("---------------------------\n");
            fflush(stdin);
            scanf("%i", &select);
            switch(select)
            {
                case 1://recommend a follow up visit
                    break;
                case 2://write a report
                    break;
                case 3://Describe a medicine
                    break;
            }
            break;
        default://database not founded
            puts("Database is not founded.");
            break;
    }//end of switch(patientFounded);
}//end of doctor_follow_up(void);

