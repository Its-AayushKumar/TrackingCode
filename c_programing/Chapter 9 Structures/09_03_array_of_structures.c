#include <stdio.h>
#include <string.h>

struct employee
{
    int code;
    float salary;
    char name[25];
};

int main()
{
    struct employee facebook[100];

    facebook[0].code = 100;
    facebook[0].salary = 123.4;
    strcpy(facebook[0].name, "Aayush");

    facebook[1].code = 100;
    facebook[1].salary = 133.4;
    strcpy(facebook[1].name, "Panda");

    facebook[3].code = 100;
    facebook[3].salary = 143.4;
    strcpy(facebook[3].name, "Pig");
    printf("Done");

    return 0;
}