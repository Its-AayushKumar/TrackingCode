#include <stdio.h>

struct Student
{
    int roll;
    float marks;
};

int main()
{
    struct Student s1;

    printf("Enter roll: ");
    scanf("%d", &s1.roll);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    printf("\nRoll = %d", s1.roll);
    printf("\nMarks = %.2f", s1.marks);

    return 0;
}
