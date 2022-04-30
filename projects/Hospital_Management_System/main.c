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
#include "stdTypedef.h"

/*========================= end ===========================*/



int main()
{
    uint8 select = 0;
    uint8 doctor_id = 0;
    uint8 patient_n_id = 0;
    uint8 exit_program = 0;
    uint8 dr_follow_up 0xff;


    system("COLOR 2F"); //set theme to: (Background: green, Text: white);

    while( 0 == exit_program)
    {
        hospital_welcome_screen(&select);

        switch(select)
        {
            /*I'm a doctor*/
            case 1:
                select = doctor_login_screen();
                if(1 == select)
                {
                    //doctor in the hospital
                    doctor_id = doctor_check_id();
                    if(0 == doctor_id)
                    {
                        puts("Your \"Hospital id\" is not in the database!\n");
                        puts("Please make sure that you entered your \"Hospital id\" correctly.\n");
                        printf("Press any key to return main menu... ");
                        fflush(stdin);
                        getch();
                    }//end of if(0 == doctor_id);
                    else if(1 == doctor_id) //doctor is founded
                    {
                        doctor_welcome_screen(&select);
                        if(1 == select)
                        {
                            //follow up with a patient:
                            dr_follow_up = doctor_follow_up();
                            switch(dr_follow_up)
                            {
                                case 0:
                                    //patient not founded
                                    break;
                                case 1:
                                    //recommend a follow up visit
                                    break;
                                case 2:
                                    //write a report
                                    break;
                                case 3:
                                    //Describe a medicine
                                    break;
                                case 4:
                                    //Database is not founded
                                    break;
                            }
                            //doctor recommends a follow up visit and determine its data and time
                            //doctor writes a report for the patient.
                            //doctor describes medicine

                        }
                        else if(2 == select)
                        {
                            //view today's appointments
                        }
                        else
                        {
                            //return to main menu.
                        }
                    }//end of else if(1 == doctor_id) //doctor is founded
                    else if(0xff == doctor_id)
                    {
                        puts("There is no doctors database!\n");
                        puts("Please make sure:\n");
                        puts("\t--> that this is not the first time to run the system.");
                        puts("\t--> that you did n't change directory of doctors database file.");
                        puts("\t--> that doctors database file is not deleted.");
                        puts("\t--> that doctors database file is not renamed.\n");
                        printf("Press any key to return main menu... ");
                        fflush(stdin);
                        getch();
                    }
                }//end of if(1 == select);
                else if(2 == select)
                {
                    //new doctor
                    doctor_add_new();
                } //end of else if(2 == select);
                break;
            case 2:
                //I'm a patient
                patient_welcome_screen(&select);
                if(1 == select)
                {
                    //reserve an appointment
                    patient_reserve_appointment();
                }
                else if(2 == select)
                {
                    //follow up
                    patient_n_id = patient_check_n_id();
                    if(1 == patient_n_id)
                    {
                        //patient is founded
                        puts("--> Patient is founded!!\n");
                        //patient came in his date
                        //print the follow up fees
                    }
                    else if(0 == patient_n_id)
                    {
                        //patient is not founded
                        puts("--> Patient \"National id\" is not in the database!\n");
                        puts("--> Please make sure that you entered patient's \"National id\" correctly.\n");
                        printf("--> Press any key to return main menu... ");
                        fflush(stdin);
                        getch();
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
                        fflush(stdin);
                        getch();
                    }
                }
                else if(2 == select)
                {
                    //inquire
                }
                else if(2 == select)
                {
                    //emergency case
                }
                break;
            case 3:
                //view data
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

    } //end of while(1);

    return 0;
} //end of main();

/*****************************************************************
* Revision Log:
* Date        By               Brief
* ---------   --------------   ----------------------------------
* 26Apr2022   Mohamed Yasser   Created this project.
* ---------   --------------   ----------------------------------
******************************************************************/
