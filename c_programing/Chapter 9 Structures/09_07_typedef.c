#include <stdio.h>
#include <string.h>

typedef struct employee // Typedef is used to create a alice name
{
    int code;
    float salary;
    char name[25];
} emp; // Using typedef we dont have to type struct employee again instead we can use emp
void show(emp emp1)
{
    printf("THe code of employee is :%d\n", emp1.code);
    printf("THe salary of employee is :%f\n", emp1.salary);
    printf("THe name of employee is :%s\n", emp1.name);
}
int main()
{
    // Declaring e1 and ptr
    emp e1;
    emp *ptr;

    // Pointing ptr to e1
    ptr = &e1;

    // Set the number values for e1
    ptr->code = 101;
    ptr->salary = 874353.43;
    strcpy(ptr->name, "Ayush");

    printf("%d\n", e1.code);

    show(e1);
    return 0;
}