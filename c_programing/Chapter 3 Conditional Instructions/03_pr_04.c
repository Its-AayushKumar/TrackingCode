#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year :");
    scanf("%d", &year);

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("Entered year is leap year");
    }

    else
    {
        printf("Entered year is not leap year");
    }

    return 0;
}