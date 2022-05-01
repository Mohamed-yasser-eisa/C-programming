#include "clinic.h"

static uint16 password;
static void set_password(void);
static void get_pass(void);
static void set_fees(void);
static float32 fees;
static char clinicName[50] = "(set clinic's name)";
char clinic_Name[50];
static void set_name(void);
void get_clinic_name(void);

uint16 pass_word;


/*
function setup clinic informations
*/
void clinic_setup(void)
{
    static first = 1;
    system("cls");
    puts("Clinic setup screen:");
    puts("____________________\n");
    if(1 == first)
    {
        puts("Set an admin password");
        puts("----------------------------");
        set_password();
        get_pass();
        puts("----------------------------");
        puts("Set clinic name:");
        puts("----------------------------");
        set_name();
        get_clinic_name();
        puts("----------------------------");
        puts("Set clinic fees:");
        puts("----------------------------");
        set_fees();
    }
    else
    {
        uint16 check_pass = 0;
        puts("Enter admin password\n");
        fflush(stdin);
        scanf("%hu", &check_pass);
        if(check_pass == password)
        {
            puts("Set an admin password");
            puts("----------------------------");
            set_password();
            get_pass();
            puts("----------------------------");
            puts("Set clinic name:");
            puts("----------------------------");
            set_name();
            get_clinic_name();
            puts("----------------------------");
            puts("Set clinic fees:");
            puts("----------------------------");
            set_fees();
        }
        else
        {
            puts("Wrong password!!");
        }
    }//end of else
    ++first;
    printf("press any key to return main menu...");
    fflush(stdin);
    getch();
}//end of clinic_setup(void);


static void get_pass(void)
{
    pass_word = password;
}
void get_clinic_name(void)
{
    strcpy(clinic_Name, clinicName);
}

static void set_fees(void)
{
    printf("Fees: ");
    fflush(stdin);
    scanf("%f", &fees);
    puts("Fees is changed successfully");
    printf("Clinic's fees is: %0.3f\n", fees);
}

/*
static function change password:
*/
static void set_password(void)
{
    printf("Password: ");
    fflush(stdin);
    scanf("%hu", &password);
    puts("Password is changed successfully");
    printf("Your password is: %hu\n", password);
}//end of set_password(void);

/*
static function change clinic's name:
*/
static void set_name(void)
{
    printf("Clinic's name: ");
    fflush(stdin);
    fgets(clinicName, sizeof(clinicName), stdin);
    clinicName[strlen(&clinicName)-1] = '\0';//remove last read '\n'
    puts("Clinic's name is changed successfully");
    printf("Clinics name is: %s\n", clinicName);
}


/*
function view clinic informations
*/
void clinic_view_info(void)
{
    uint8 num_cases = 0;
    system("cls");
    puts("Clinic view information screen:");
    puts("________________________________\n");
    printf("Clinics fees: %0.3f\n", fees);
    num_cases = patient_get_number();
    printf("Number of cases: %u\n", num_cases);
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}//end of clinic_view_info(void);
