#include <stdio.h>
#include <string.h>

struct employee
{
    int code;
    float salary;
    char name[25];
};
void show(struct employee emp)
{
    printf("THe code of employee is :%d\n", emp.code);
    printf("THe salary of employee is :%f\n", emp.salary);
    printf("THe name of employee is :%s\n", emp.name);
}
int main()
{
    struct employee e1;
    struct employee *ptr;

    ptr = &e1;
    //(*ptr).code = 101; Or this can also be used
    ptr->code = 101;
    ptr->salary = 874353.43;
    strcpy(ptr->name, "Ayush");

    printf("%d\n", e1.code);

    show(e1);
    return 0;
}