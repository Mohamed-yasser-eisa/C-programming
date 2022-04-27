#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*strcuture definition does not consume any memory*/
/*structure definition is just a declaration for the compiler to the new data type.*/
struct car
{
    int x;
    int y;
    short z;
}f = {10,22,33};/*here we created variable 'f' of datatype: (struct car) it reserve a memory location. */
 
struct student
{
    int Id;
    float GPA;
    char name[10];
    short int day[4];
}s={10,3.5,"Adel Mosa",{4,3,2,1}};

struct client
{
    int id;
    float sallary;
}global_struct;

struct manager
{
    int id;
    struct client m;
};

struct customer
{
    int number;
    struct customer *c;
};


int i=0;


struct car call_value(struct car cv);
void call_reference(struct car *ptr);




int main()
{
    puts("**************************************************");
    struct car w;
    printf("w    = %i\n", w);//Unlike array, name of struct = value of first member in it.
    printf("w.x  = %i\n", w.x);//value of first element.
    printf("&w   = %i\n", &w);//like array, address of struct = address of first member in it.
    printf("&w.x = %i\n", &w.x);//address of member 'x' in the struct.
    printf("&w.y = %i\n", &w.y);//address of member 'y' in the struct.
    printf("&w.z = %i\n", &w.z);//address of member 'z' in the struct.

    puts("--------------------------------------------------------------");
    struct student st1;
    
    puts("Please enter student Id:");
    scanf("%i", &st1.Id);
    puts("Please enter student GPA:");
    scanf("%f", &st1.GPA);
    puts("Please enter student Name:");
    fflush(stdin);
    gets(st1.name);
    printf("\nStudent Id = %i\n", st1.Id);
    printf("Student GPA = %0.3f\n", st1.GPA);
    printf("Student Name = %s\n", st1.name);

    puts("--------------------------------------------------------------");
    printf("st1.name = %i\n", st1.name);//Name of array is a pointer to char
    printf("st1.name+1 = %i\n", st1.name+1);//step of array name = 1 byte
    printf("st1.&name = %i\n", &st1.name);//&Name of array is pointer to array
    printf("st1.name+1 = %i\n", &st1.name+1);//step of pointer to array = 10 bytes

    puts("--------------------------------------------------------------");
    printf("&st1.name[0]     = %i\n", &st1.name[0]);
    printf("&st1.name[1]     = %i\n", &st1.name[1]);
    printf("&st1.name[0] + 1 = %i\n", &st1.name[0]+1);

    puts("--------------------------------------------------------------");
    puts("Local and global struct variables:");

    puts("--> default value for global struct members = 0");
    puts("--> default value for local struct members = garbage value.\n");

    struct client local_struct;

    printf("global_struct.id      = %i\n", global_struct.id);
    printf("global_struct.sallary = %0.2f\n\n", global_struct.sallary);

    printf("local_struct.id      = %i\n", local_struct.id);
    printf("local_struct.sallary = %0.2f\n", local_struct.sallary);



    puts("--------------------------------------------------------------");
    puts("Please enter date of 4 days:");
    for(i=0; i<4; ++i)
    {
        scanf("%i", &st1.day[i]); //&st1.day+i
    }
    puts("Days are:");
    for(i=0; i<4; ++i)
    {
    printf("%i\n", *(st1.day+i));  //st1.day[i]
    }

    puts("--------------------------------------------------------------");
    /*initializing struct members of type array: */
    struct student st2 = {10,2.5, {'M','o','h','a','m','e','d'}, {15,25,35,45}};
    puts("st2 members are:\n");
    printf("Id  = %i\n", st2.Id);
    printf("GPA = %f\n", st2.GPA);
    printf("Days = {");
    for(i=0; i<4; ++i)
    {
    printf(" %i,", *(st2.day+i));  //st2.day[i]
    }
    puts("\b }");
    printf("name = %s\n", st2.name);
    puts("----     ----    ----    ----    ----");
    struct student st3 = {50,3, "Ali Moham", {1,2,3,4}};

    strcpy(st3.name, "Mahmoud");//copy string in array of chars


    puts("st3 members are:\n");
    printf("Id  = %i\n", st3.Id);
    printf("GPA = %f\n", st3.GPA);
    printf("Days = {");
    for(i=0; i<4; ++i)
    {
    printf(" %i,", *(st3.day+i));  //st3.day[i]
    }
    puts("\b }");
    printf("name = %s\n", st3.name);

    puts("------------------------------------------------------------");
    puts("Pointer to struct:\n");
    puts("--> Access and step of pointer to struct equals to size of struct");
    puts("--> When we derefernce pointer to struct it now access number of bytes = struct size");

    puts("");
    struct car *ptr1 = &f; //now ptr stores address of struct car f;
    // *ptr1 === f;
    printf("(*ptr1).x = %i\n", (*ptr1).x);
    printf("(*ptr1).y = %i\n", (*ptr1).y);
    printf("(*ptr1).z = %i\n", (*ptr1).z);
    puts("----     ----  Or use arrow operator (->) as follow  ----    ----    ----");
    printf("ptr1 -> x = %i\n", ptr1 -> x);
    printf("ptr1 -> y = %i\n", ptr1 -> y);
    printf("ptr1 -> z = %i\n", ptr1 -> z);
    puts("----     ----    ----    ----    ----");
    printf("size of f = %i bytes\n", sizeof(f));
    printf("f     = %i\n", f);//value of first member
    printf("&f    = %i\n", &f);//address of first member
    printf("&f.Id = %i\n", &f.x);//address of first member
    printf("&f+1  = %i\n", &f+1);//step of struct size
    printf("&f.Id = %i\n", &f.x+1);//step of int size
    puts("");
    printf("ptr1       = %i\n", ptr1);
    printf("ptr1 +1    = %i\n", ptr1+1);
    printf("*ptr1      = %i\n", *ptr1);
    printf("*(ptr1 +1) = %i\n", *(ptr1+1));
    printf("f = %i\n", f);
    puts("------------------------------------------------------------");
    puts("How to access member in struct of type array, using pointer\n");

    struct student *ptr2 = &s;
    printf("ptr2 -> Id   = %i\n", ptr2 -> Id);
    printf("ptr2 -> GPA  = %0.2f\n", ptr2 -> GPA);
    printf("ptr2 -> name = %s\n", ptr2 -> name);
    printf("ptr2 -> day[0]  = %hd\n", ptr2 -> day[0]);
    printf("ptr2 -> day[1]  = %hd\n", ptr2 -> day[1]);
    printf("ptr2 -> day[2]  = %hd\n", ptr2 -> day[2]);
    printf("ptr2 -> day[3]  = %hd\n", ptr2 -> day[3]);
    puts("----     ----    ----    ----    ----");
    strcpy(ptr2 -> name, "Ahmed Moh");
    printf("ptr2 -> name = %s\n", ptr2 -> name);

    puts("------------------------------------------------------------");
    puts("Call by value with struct:\n");

    struct car cv1 = {10,20,30};
    printf("cv1.x = %i\n", cv1.x);
    printf("cv1.y = %i\n", cv1.y);
    printf("cv1.z = %hd\n", cv1.z);
    puts("----     ----    ----    ----    ----");
    cv1 = call_value(cv1);//call by value
    printf("cv1.x = %i\n", cv1.x);
    printf("cv1.y = %i\n", cv1.y);
    printf("cv1.z = %hd\n", cv1.z);

    puts("------------------------------------------------------------");
    puts("Call by reference with struct:\n");

    struct car cv2 = {1,2,3};
    printf("cv2.x = %i\n", cv2.x);
    printf("cv2.y = %i\n", cv2.y);
    printf("cv2.z = %hd\n", cv2.z);
    puts("----     ----    ----    ----    ----");
    call_reference(&cv2);//call by reference
    printf("cv2.x = %i\n", cv2.x);
    printf("cv2.y = %i\n", cv2.y);
    printf("cv2.z = %hd\n", cv2.z);

    puts("------------------------------------------------------------");
    puts("Nested struct:\n");
    puts("--> Nested struct is allowed in C, but inner struct can not be of the same type of outer struct");
    struct manager m1;
    m1.id = 1012;
    m1.m.id = 870;
    m1.m.sallary = 10000.500;

    printf("m1.id        = %i\n", m1.id);
    printf("m1.m.id      = %i\n", m1.m.id);
    printf("m1.m.sallary = %0.3f\n", m1.m.sallary);

    puts("------------------------------------------------------------");
    puts("Pointers with nested struct:\n");

    struct manager *mptr = &m1;
    mptr -> id = 5060;
    mptr -> m.id = 8090;
    mptr -> m.sallary = 10605.6654;
    printf("mptr -> id        = %i\n", mptr -> id);
    printf("mptr -> m.id      = %i\n", mptr -> m.id);
    printf("mptr -> m.sallary = %0.3f\n", mptr -> m.sallary);

    puts("------------------------------------------------------------");
    puts("Struct pointer int struct:\n");

    struct customer cs1;
    struct customer cs2;
    cs1.number = 1000;
    cs2.number = 2000;
    (cs2.c) = &cs1;
    
    printf("(cs2.c) -> number = %i\n", (*cs2.c).number); //(cs2.c) -> number

    puts("------------------------------------------------------------");
    puts("size of struct:\n");

    puts("--> size of struct = (sum of sizes of all members + struct padding).");
    puts("--> so size of any struct >= sum of sizes of all members.\n");

    printf("size of struct car      = %i\n", sizeof(struct car));
    printf("size of struct client   = %i\n", sizeof(struct client));
    printf("size of struct manager  = %i\n", sizeof(struct manager));
    printf("size of struct customer = %i\n", sizeof(struct customer));
    printf("size of struct student  = %i\n\n", sizeof(struct student));

    puts("--> size of struct != sum of sizes of all members due to \"strcuture padding\".");
    puts("--> (structure padding) is optimization done by the compiler to make programe execution faster");
    puts("--> In (structure padding) the compiler allocate unused memory locations free between struct members to make");
    puts("      each member read/write in one clock cycle if it is posible.");



    puts("**************************************************");
    return 0;
}

/*Function implementation section:*/

struct car call_value(struct car cv)
{
    cv.x = 1000;
    cv.y = 70;
    cv.z = 20;
    return cv;
}


void call_reference(struct car *ptr)
{
    ptr -> x = 500; //*ptr.x
    ptr -> y = 800;//*ptr.y
    ptr -> z = 300;//*ptr.z

}