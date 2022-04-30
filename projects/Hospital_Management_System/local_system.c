#include "local_system.h"




void hospital_welcome_screen(uint8* selection)
{
    system("cls");  /*clear console screen*/
    puts("\n====================\tWelcome to Egypt hospital\t====================");
    puts("____________________________________________________________________________\n\n");
    puts("Please select from the following options:");
    puts("-----------------------------------------\n");
    puts("(1) I'm a doctor.\n");
    puts("(2) I'm a patient.\n");
    puts("(3) View data.\n");
    puts("(4) Edit data.\n");
    puts("(5) Change theme.\n");
    puts("(6) Exit.\n");
    puts("------------------------------------------\n");
    printf("Option: ");
    fflush(stdin);
    scanf("%i", &*selection); // or scanf("%i", selection);
}





void change_theme(void)
{
    /*
    Color Codes:
    0 = Black
    1 = Blue
    2 = Green
    3 = Aqua
    4 = Red
    5 = Purple
    6 = Yellow
    7 = White
    8 = Gray
    9 = Light Blue
    A = Light Green
    B = Light Aqua
    C = Light Red
    D = Light Purple
    E = Light Yellow
    F = Bright White
    */
    uint8 color = 0;
    system("cls");
    puts("Please choose a color:");
    puts("----------------------");
    puts("(1) Background: green.\tText: white.");
    puts("(2) Background: blue.\tText: white.");
    puts("(3) Background: white.\tText: black.");
    puts("(4) Background: white.\tText: purple.");
    puts("(5) Background: gray.\tText: black.\n");
    puts("-------------------------------------");

    fflush(stdin);
    scanf("%i", &color);
    switch(color)
    {
        case 1:
            system("color 2F"); //set theme to green:white
            puts("Theme now is: (green and white)");
            puts("Press any key to return main menu.\n");
            getch();
            break;
        case 2:
            system("color 9F"); //set theme to blue:white
            puts("Theme now is: (blue and white)");
            puts("Press any key to return main menu.\n");
            getch();
            break;
        case 3:
            system("color F0"); //set theme to white:black
            puts("Theme now is: (white and black)");
            puts("Press any key to return main menu.\n");
            getch();
            break;
        case 4:
            system("color FD"); //set theme to white:purple
            puts("Theme now is: (white and purple)");
            puts("Press any key to return main menu.\n");
            getch();
            break;
        case 5:
            system("color 80"); //set theme to gray:black
            puts("Theme now is: (gray and black)");
            puts("Press any key to return main menu.\n");
            getch();
            break;
    }
}

uint64 random_hospital_id(void)
{
    uint32 sec = (uint32)time(NULL);//time function returns number of seconds since (19 January 1970)
    srand(sec);//starting point of random function. It's the seed that it get initialized with.
    uint64 random_id = rand();
    return (random_id * random_id);
}


