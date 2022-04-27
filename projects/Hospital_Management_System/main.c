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
        puts("-----------------------------------------\n");
        puts("(1) I'm a doctor.");
        puts("(2) I'm a nurse.");
        puts("(3) I'm a patient.");
        puts("(4) View informations.");
        puts("(5) Change theme.");
        puts("(6) Exit.\n");
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
                }
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
                //
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
