#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[39];
    float marks;
};

int main()
{
    struct student s1;
    struct student *ptr;
    ptr = &s1;

    s1.id = 101;
    ptr->marks = 49.8;
    strcpy(ptr->name, "Aayush");

    printf("%d\n", s1.id);
    printf("%.2f\n", s1.marks);
    printf("%s\n", s1.name);

    return 0;
}