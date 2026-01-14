#include <stdio.h>
typedef struct date
{
    int day;
    int month;
    int year;
} date;

void display(date d)
{
    printf("The date is : %d/%d/%d\n", d.day, d.month, d.year);
}
int datecmp(date d1, date d2)
{
    // Make decision on the basis of year comparison
    if (d1.year > d2.year)
    {
        return 1;
    }
    if (d1.year < d2.year)
    {
        return -1;
    }
    // Make decision on the basis of month comparison
    if (d1.month > d2.month)
    {
        return 1;
    }
    if (d1.month < d2.month)
    {
        return -1;
    }
    // Make decision on the basis of day comparison
    if (d1.day > d2.day)
    {
        return 1;
    }
    if (d1.day < d2.day)
    {
        return -1;
    }
    return 0;
}

int main()
{
    date d1 = {2, 4, 26};
    date d2 = {2, 5, 25};
    display(d1);
    display(d2);
    int a = datecmp(d1, d2);
    printf("Date comparison function %d", a);

    return 0;
}