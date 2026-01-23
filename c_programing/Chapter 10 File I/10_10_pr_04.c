#include <stdio.h>

int main()
{
    char name1[50], name2[50];
    float salary1, salary2;
    FILE *ptr;

    ptr = fopen("output.txt", "w");

    printf("Enter name of employee 1: ");
    scanf("%s", name1);
    printf("Enter salary of employee 1: ");
    scanf("%f", &salary1);

    printf("Enter name of employee 2: ");
    scanf("%s", name2);
    printf("Enter salary of employee 2: ");
    scanf("%f", &salary2);

    fprintf(ptr, "%s, %.0f\n", name1, salary1);
    fprintf(ptr, "%s, %.0f\n", name2, salary2);

    fclose(ptr);

    return 0;
}
