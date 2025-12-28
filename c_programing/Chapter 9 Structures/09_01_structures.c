#include <stdio.h>
#include <string.h>
struct employee
{
    int code;
    float salary;
    char name[20];
};

int main()
{
    int a = 34;
    char b = 'X';
    char name[20];
    // name = "Soham"; Illegal

    float c = 343.544;
    // employee e1 ;
    // e1.salary = 34.344; ----> won't work without employee structure

    struct employee e1;
    e1.code = 100;
    e1.salary = 34.3434;
    // e.1 name ="Aayush"; ---->wont work
    strcpy(e1.name, "Aayush");

    printf("%d", e1.code);
    return 0;
}