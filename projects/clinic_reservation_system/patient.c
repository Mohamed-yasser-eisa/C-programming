#include "patient.h"

static uint8 nextAvilableElement(void);
static void delete_patient(uint8 num);
static uint8 cursor;
static uint8 first;
static uint8 num_of_patients;


Patient patientsArray[ArraySize];

uint8 patient_reserve(void)
{
    uint8 addcase = 0;
    uint8 flag = 1;
    static uint8 first = 0;

    addcase = nextAvilableElement();
        if(addcase < ArraySize)//steel we have free space for patients:
        {
            num_of_patients++;
            system("cls");
            puts("\nPatient reserve screen:");
            puts("_________________________\n");
            puts("Enter patient's details: (Name - Age - Phone - Paid fees)");
            puts("----------------------------------------------------------\n");
            printf("Name.....: ");
            fflush(stdin);
            fgets(patientsArray[cursor].name, sizeof(patientsArray[cursor].name), stdin);
            (patientsArray[cursor].name)[strlen(&(patientsArray[cursor].name))-1] = '\0';//remove last read '\n'
            printf("Age......: ");
            fflush(stdin);
            scanf("%u", &(patientsArray[cursor].age) );
            printf("Phone....: ");
            fflush(stdin);
            scanf("%llu", &(patientsArray[cursor].phone) );
            printf("Paid fees: ");
            fflush(stdin);
            scanf("%f", &(patientsArray[cursor].paidFees) );

            patientsArray[cursor].row = cursor + 1;//number of patient in the queue

            puts("------------------------------------------\n");
            puts("\nPatient's details are:");
            puts("------------------------------------------\n");
            printf("Patient number is: %i\n", patientsArray[cursor].row);
            printf("Name.............: %s\n", patientsArray[cursor].name);
            printf("Age..............: %i\n", patientsArray[cursor].age);
            printf("Phone............: 0%llu\n", patientsArray[cursor].phone);
            printf("PaidFees.........: %0.3f\n", (patientsArray+cursor)->paidFees);
            puts("-------------------------------------------");
            flag = 0;//return patient is saved successfully
        }//end of if(addcase < arraySize);
        else//no free space
        {
            first++;
            if(first > 1)
            {
                --cursor;//now max value of cursor = arraySize
            }
        }
    return flag;
}// end of patient_reserve(void);

/*
function returns if next free index to store new patient.
*/
uint8 nextAvilableElement(void)
{
    if( (0 == cursor) && (0 == first))//is this first patient? then don't increment cursor
    {
        ++first;//increment first to know first patient is reserved
    }//end of if
    else
    {
        ++cursor;
    }//end of else

    return cursor;
}//end of nextAvilableElement(void);


void patient_view(void)
{
    uint8 i = 0;
    uint64 pho_num = 0;

    system("cls");
    puts("\nPatient view details screen:");
    puts("______________________________\n");
    printf("Enter patient's phone number: ");
    fflush(stdin);
    scanf("%llu", &pho_num);
    puts("------------------------------------------------------\n");
    for(i=0; i<ArraySize; ++i)
    {
        if(pho_num == patientsArray[i].phone)
        {
            puts("\nPatient's details are:");
            puts("------------------------------------------\n");
            printf("Patient number is: %i\n", patientsArray[i].row);
            printf("Name.............: %s\n", patientsArray[i].name);
            printf("Age..............: %i\n", patientsArray[i].age);
            printf("Phone............: 0%llu\n", patientsArray[i].phone);
            printf("PaidFees.........: %0.3f\n", (patientsArray+i)->paidFees);
            puts("-------------------------------------------");
            break;
        }//end of if();
        else if(i == (ArraySize-1))//is this last element?
        {
            puts("Patient is not found.\n");
            puts("Make sure you enter phone number correctly.\n");
            break;
        }//end of else
    }//end of for();
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}//end of patient_view(void);

void patient_edit(void)
{
    uint8 i = 0;
    uint64 pho_num = 0;

    system("cls");
    puts("\nPatient edit details screen:");
    puts("______________________________\n");
    printf("Enter patient's phone number: ");
    fflush(stdin);
    scanf("%llu", &pho_num);
    puts("------------------------------------------------------\n");
    for(i=0; i<ArraySize; ++i)
    {
        if(pho_num == patientsArray[i].phone)
        {
            puts("\nPatient's details are:");
            puts("------------------------------------------\n");
            printf("Patient number is: %i\n", patientsArray[i].row);
            printf("Name.............: %s\n", patientsArray[i].name);
            printf("Age..............: %i\n", patientsArray[i].age);
            printf("Phone............: 0%llu\n", patientsArray[i].phone);
            printf("PaidFees.........: %0.3f\n", (patientsArray+i)->paidFees);
            puts("-------------------------------------------");
            puts("Enter edited details: ");
            printf("Name.....: ");
            fflush(stdin);
            fgets(patientsArray[i].name, sizeof(patientsArray[i].name), stdin);
            (patientsArray[i].name)[strlen(&(patientsArray[i].name))-1] = '\0';
            printf("Age......: ");
            fflush(stdin);
            scanf("%u", &(patientsArray[i].age) );
            printf("Phone....: ");
            fflush(stdin);
            scanf("%llu", &(patientsArray[i].phone) );
            printf("Paid fees: ");
            fflush(stdin);
            scanf("%f", &(patientsArray[i].paidFees) );
            puts("------------------------------------------\n");
            puts("\nPatient's new data are:");
            puts("------------------------------------------\n");
            printf("Patient number is: %i\n", patientsArray[i].row);
            printf("Name.............: %s\n", patientsArray[i].name);
            printf("Age..............: %i\n", patientsArray[i].age);
            printf("Phone............: 0%llu\n", patientsArray[i].phone);
            printf("PaidFees.........: %0.3f\n", (patientsArray+i)->paidFees);
            puts("-------------------------------------------");
            break;
        }//end of if();
        else if(i == (ArraySize-1))//is this last element?
        {
            puts("Patient is not found.\n");
            puts("Make sure you enter phone number correctly.\n");
            break;
        }//end of else
    }//end of for();
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}//end of patient_edit();

void patient_delete(void)
{
    uint8 i = 0;
    char decision = '\0';
    uint16 pass = 0;
    uint8 pat_num = 0;//patient number

    system("cls");
    puts("\nPatient delete details screen:");
    puts("________________________________\n");
    printf("Enter patient's row number NOT phone number: ");//enter number of patient in the queue
    fflush(stdin);
    scanf("%u", &pat_num);
    printf("Enter password: ");
    fflush(stdin);
    scanf("%hu", &pass);
    puts("------------------------------------------------------\n");

    if(pass == pass_word)
    {
        puts("\nPatient's details are:");
        puts("------------------------------------------\n");
        printf("Patient number is: %i\n", patientsArray[i].row);
        printf("Name.............: %s\n", patientsArray[i].name);
        printf("Age..............: %i\n", patientsArray[i].age);
        printf("Phone............: 0%llu\n", patientsArray[i].phone);
        printf("PaidFees.........: %0.3f\n", (patientsArray+i)->paidFees);
        puts("-------------------------------------------\n");

        puts("Are you sure you want to delete? (Y/N)\a");
        fflush(stdin);
        scanf("%c", &decision);
        if( ((char)decision == (char)'Y') || ((char)decision == (char)'y') )
        {
            delete_patient(pat_num);
        }
    }//end of if();
    else
    {
        puts("Wrong password!.\n");
        puts("Make sure you are an admin.\n");
    }//end of else
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}

static void delete_patient(uint8 num)
{
    uint8 i = 0;
    --num;//we want to delete patient in this index;
    if(ArraySize == cursor)//the array is full
    {
        for(i=num; i<cursor; ++i)
        {
            patientsArray[i] = patientsArray[i+1];
        }//end of for loop
        cursor -= 2;//point to last patient
        num_of_patients--;
        (patientsArray[cursor].row) -= 1;
    }//end of if(ArraySize == index);
    else
    {
        for(i=num; i<=cursor; ++i)
        {
            patientsArray[i] = patientsArray[i+1];
        }
        --cursor;
        num_of_patients--;
        (patientsArray[cursor].row) -= 1;
    }//end of else

}

uint8 patient_get_number(void)
{
    return num_of_patients;
}
