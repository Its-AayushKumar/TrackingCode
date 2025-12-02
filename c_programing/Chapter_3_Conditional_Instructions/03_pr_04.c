#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year :");
    scanf("%d", &year);

    if (year % 4 != 0)
    {
        printf("Entered year is not leap year");
    }

    else if (year % 100 != 0)
    {
        printf("Entered year is  leap year");
    }

    else
        (year % 400 != 0);
    {
        printf("Entered year is not leap year");
    }

    return 0;
}