/********************************************************
*@file: main.c
*@version: 1.0.0
*@author: Mohamed Yasser
*@brief: this is the main file for the hospital management system.
***********************************************************/

/*--------------- includes section starts: ---------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "local_system.h"
#include "doctor.h"
#include "patient.h"
#include "stdTypedef.h"

/*========================= end ===========================*/



int main()
{
    uint8 select = 0; //takes elected option from user
    uint8 doctor_id = 0; //takes doctor's "hospital id"
    uint8 patient_n_id = 0; //takes patient's "national id"
    uint8 exit_program = 1; //loop until exit_program = 0;
    uint8 option = 0; //takes options from return functions
    uint8 password_check = 0xFF;

    //uint8 dr_follow_up = 0xff;
    system("COLOR 2F"); //set theme to: (Background: green, Text: white);

    while(exit_program) //loop until exit_program = 0;
    {
        hospital_welcome_screen(&select); //display options and take selection

        switch(select)
        {
            case 1: //I'm a doctor
////////////////////////////////////////////////////////////////////////////
                select = doctor_login_screen();
                if(1 == select)//doctor in the hospital
                {
                    doctor_id = doctor_check_id();
                    if(0 == doctor_id)//doctor not found
                    {
                        puts("--> Your \"Hospital id\" is not in the database!\n");
                        puts("--> Please make sure that you entered your \"Hospital id\" correctly.\n");
                    }//end of if(0 == doctor_id);
                    else if(1 == doctor_id) //doctor is founded
                    {
                        doctor_welcome_screen(&option);
                        if(1 == option)//follow up with a patient:
                        {
                            doctor_follow_up();
                            //doctor recommends a follow up visit and determine its data and time
                            //doctor writes a report for the patient.
                            //doctor describes medicine

                        }
                        else
                        {
                            //do nothing and return to main menu.
                        }
                    }//end of else if(1 == doctor_id) //doctor is founded
                    else if(104 == doctor_id)
                    {
                        puts("There is no doctors database!\n");
                        puts("Please make sure:\n");
                        puts("\t--> that this is not the first time to run the system.");
                        puts("\t--> that you did n't change directory of doctors database file.");
                        puts("\t--> that doctors database file is not deleted.");
                        puts("\t--> that doctors database file is not renamed.\n");
                    }
                    printf("Press any key to return main menu... ");
                    fflush(stdin);
                    getch();
                }//end of if(1 == select);
                else if(2 == select)//new doctor
                {
                    doctor_add_new();
                } //end of else if(2 == select);
///////////////////////////////////////////////////////////////////////////////////////
            break;
            case 2: //I'm a patient
                patient_welcome_screen(&option);
                if(1 == option) //reserve an appointment
                {
                    patient_reserve_appointment(); //take patient's data and save to database
                }
                else if(2 == option) //follow up
                {
                    patient_n_id = patient_check_n_id();
                    if(1 == patient_n_id)
                    {
                        //patient is founded
                        //puts("--> Patient is founded!!\n");
                        patient_follow_up();
                        puts("\nData is saved successfully!\n");
                        puts("Please be patient and wait your row.\n");
                        printf("Press any key to return main menu... ");
                    }
                    else if(0 == patient_n_id)
                    {
                        //patient is not founded
                        puts("--> Patient \"National id\" is not in the database!\n");
                        puts("--> Please make sure that you entered patient's \"National id\" correctly.\n");
                        printf("--> Press any key to return main menu... ");
                    }
                    else
                    {
                        //database is not founded
                        puts("There is no patients database!\n");
                        puts("Please make sure:\n");
                        puts("\t--> that this is not the first time to run the system.");
                        puts("\t--> that you did n't change directory of patients database file.");
                        puts("\t--> that patients' database file is not deleted.");
                        puts("\t--> that patients' database file is not renamed.\n");
                        printf("Press any key to return main menu... ");
                    }
                } //end of else if(2 == option);
            fflush(stdin);
            getch();
            exit_program = 1;
            break;
            case 3:
                password_check = system_view_data();
                if(0 == password_check)
                {
                    puts("\nWrong password!!\n");
                    puts("You must be an admin to show data.\n");
                }
                else if(1 == password_check)
                {
                    patient_view_data();
                }
                else if(2 == password_check)
                {
                    doctor_view_data();
                }
                else
                {
                    puts("\nInvalid selection!!\n");
                }
            printf("Press any key to return main menu... ");
            fflush(stdin);
            getch();
            exit_program = 1;
            break;
            case 4:
                //edit data
                break;
            case 5:
                //change theme
                change_theme();
                break;
            case 6:
                exit_program = 1;
                break;
            default:
                puts("\n--> Invalid choice!");
                puts("--> Time out...\n");
                exit_program = 1; //terminate while() and close the program.
        }// end of switch(select);

    } //end of while(exit_program);

    return 0;
} //end of main();

/*****************************************************************
* Revision Log:
* Date        By               Brief
* ---------   --------------   ----------------------------------
* 26Apr2022   Mohamed Yasser   Created this project.
* ---------   --------------   ----------------------------------
******************************************************************/
