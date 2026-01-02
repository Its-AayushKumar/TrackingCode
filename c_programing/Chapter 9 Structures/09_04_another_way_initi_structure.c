
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
    struct employee Aayush = {101, 1234.9, "Aayush"};
    printf("Code is %d :\n", Aayush.code);
    printf("Code is %f :\n", Aayush.salary);
    printf("Code is %s :\n", Aayush.name);
    return 0;
}