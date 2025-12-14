// Question 9

#include <stdio.h>
struct student
{
    int roll;
    char name[20];
    float marks;
};
int main()
{
    struct student s1;
    printf("Enter Student Roll no : ");
    scanf("%d", &s1.roll);

    // clear leftover newline before using fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Enter Student Name : ");
    fgets(s1.name, sizeof(s1.name), stdin);

    printf("Enter Student Marks : ");
    scanf("%f", &s1.marks);
    printf("\nRoll No : %d", s1.roll);
    printf("Name : %s", s1.name);
    printf("Marks : %.2f\n", s1.marks);
    return 0;
}