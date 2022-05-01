#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stdTypedef.h"
#include "patient.h"
#include "clinic.h"





int main()
{
    static uint8 first_open = 1;
    uint8 option = 0;
    uint8 reserveAppointment = 0;
    uint8 stop = 1;
    uint8 patientFound = 0;
    get_clinic_name();

    while (stop)
    {
        system("cls");
        printf("\n*-*-*-*-* Welcome to %s clinic *-*-*-*-*\n", clinic_Name);
        puts("__________________________________________\n");
        puts("How can I serve you?");
        puts("------------------------------------------\n");
        puts("(1) Reserve an appointment.\n");
        puts("(2) View patient's information.\n");
        puts("(3) Edit patient's information.\n");
        puts("(4) View clinic's informations.\n");
        puts("(5) Delete a patient.\n");
        puts("(6) Setup clinic's informations.\n");
        puts("(7) Exit.\n");
        puts("------------------------------------------\n");
        if(1 == first_open)
        {
            option = 6;//setup clinic's informations
            ++first_open;
        }
        else
        {
            printf("option: ");
            fflush(stdin);
            scanf("%i", &option);
        }
        switch(option)
        {
        case 1://Reserve an appointment
            reserveAppointment = patient_reserve();
            if(1 == reserveAppointment)
            {
                puts("---------------------------------------\n");
                puts("Sorry, we cannot reserve a new patient today.\n");
                puts("We have reached maximum number of cases today.\n");
                printf("press any key to return main menu...");
            }
            else
            {
                puts("Patient's data are save successfully!\n");
                puts("Please be patient and wait your number.\n");
                printf("press any key to return main menu...");
            }
            fflush(stdin);
            getchar();
            stop = 1;
            break;
        case 2://view patient
            patient_view();
            stop = 1;
            break;
        case 3://Edit patient's information
            patient_edit();
            stop = 1;
            break;
        case 4://view clinic informations
            clinic_view_info();
            stop = 1;
            break;
        case 5://Delete patient:
            patient_delete();
            stop = 1;
            break;
        case 6://setup clinic informations
            clinic_setup();
            stop = 1;
            break;
        default:
            stop = 0;
            break;

        }//end of switch case.
    }//end of while(1);


    return 0;
}
