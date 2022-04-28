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
    system("COLOR 2F");



    while(1)
    {
        system("cls");  /*clear console screen*/
        puts("\n====================\tWelcome to Egypt hospital\t====================");
        puts("____________________________________________________________________________\n\n");
        puts("Please select from the following options:");
        puts("-----------------------------------------");
        puts("(1) I'm a doctor.\n");
        puts("(2) I'm a nurse.\n");
        puts("(3) I'm a patient.\n");
        puts("(4) View informations.\n");
        puts("(5) Change theme.\n");
        puts("(6) Exit.");
        puts("------------------------------------------");

        fflush(stdin);
        scanf("%i", &select);

        switch(select)
        {
            /*I'm a doctor*/
            case 1:
                select = doctor_login_screen();
                if(1 == select)
                {
                    //doctor in the hospital
                    uint8 result = 4;
                    result = doctor_check_id();
                    if(0 == result)
                    {
                        system("cls");
                        puts("Your \"Hospital Id\" is not in the database!");
                        puts("Please make sure you enter your \"Hospital Id\" correctly.");
                    }
                    else if(1 == result) //doctor is founded
                    {
                        doctor_welcome_screen(&select);
                        if(1 == select)
                        {
                            //follow up with a patient
                        }
                        else if(2 == select)
                        {
                            //view today's cases
                        }
                        fflush(stdin);
                        getch();
                    }
                    else if(0xff == result)
                    {
                        puts("doctor.pdf is not founded");
                        fflush(stdin);
                        getch();
                    }
                }//end of if(1 == select);
                else if(2 == select)
                {
                    //new doctor
                    doctor_add_new();
                }
                break;
            case 2:
                //
                break;
            case 3:
                //I'm a patient
                //patient welcome screen
                patient_welcome_screen(&select);
                if(0 == patient_selection(&select))
                {
                    //wrong choice
                    break;
                }
                break;
            case 4:
                /*background color*/
                change_theme();
                break;
            case 5:
                //
                break;
            default:
                puts("Invalid choice!");
                puts("Time out...");
                return 0;
        }

        //getche();

    }
}

/*****************************************************************
* Revision Log:
* Date        By               Brief
* ---------   --------------   ----------------------------------
* 26Apr2022   Mohamed Yasser   Created this project.
* ---------   --------------   ----------------------------------
******************************************************************/
