#include <stdio.h>
#include <stdlib.h>

/* enum gives a number for each enum element */
enum days
{
    saturday = 1,
    monday = 2,
    tuseday = 3,
    wednesday = 4,
    thursday = 5,
    friday = 6,
};

/* default value for first enum = 0; */
/* then each enum takes the value of the previous enum + 1; */
enum weeks{week1, week2, week3, week4 = 4, week5, week6, week7 = 4500000000, week8}wee;


/* two enums can have the same int value. It is allowed. */
enum state
{
    passed = 1,
    failed = 0,
    go = 1  
};

int main()
{
    puts("**************************************************");
    enum days dd = wednesday;//text replacement of wednesday by 4;
    printf("dd = %i\n", dd);//dd = 4;
    dd = friday + 10;
    printf("dd = %i\n", dd);//dd = 16;

    puts("--------------------------------------------------");
    puts("The default value of first enum = 0;");
    puts("The next enum after first enum = prevoius enum + 1;\n");

    wee = week1;
    printf("wee = %i\n", wee);
    wee = week2;
    printf("wee = %i\n", wee);
    wee = week3;
    printf("wee = %i\n", wee);
    wee = week4;
    printf("wee = %i\n", wee);
    wee = week5;
    printf("wee = %i\n", wee);
    wee = week6;
    printf("wee = %i\n", wee);
    wee = week7;
    printf("wee = %i\n", wee);
    wee = week8;
    printf("wee = %i\n", wee);

    puts("--------------------------------------------------");
    puts("Two enum elements can have the same int value, but can not have the same name;");
    puts("enum variable can has the same name of the enum:\n");
    enum state state;
    state = passed;
    printf("state = %i\n", state);
    state = failed;
    printf("state = %i\n", state);
    state = go;
    printf("state = %i\n", state);

    puts("--------------------------------------------------");
    puts("size of enum variable = size of largest int value;");
    printf("sizeof(dd)    = %i\n", sizeof(dd));
    printf("sizeof(wee)   = %i\n", sizeof(wee));
    printf("sizeof(state) = %i\n", sizeof(state));

    puts("--------------------------------------------------");
    puts("Notes:\n");
    puts("--> enum value must be integer value, can not be float type.");
    puts("--> No enum constants can have the same name, even if in different enums. If so, it will give you syntax error;");
    puts("--> enum constants are text replaced during compilation time, not preprocessing time like macros.");
    puts("--> the difference between enum and macros, is that enum is more readable than macros.");
    puts("--> in macros (#define) can has a float number, but enum can not.");

    puts("");
    puts("**************************************************");
    return 0;
}