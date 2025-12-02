#include <stdio.h>

int main()
{
    float tax = 0, income;
    printf("Enter your yearly income in INR :");
    scanf("%f", &income);
    if (income <= 250000)
    {
        printf("You are not eligible for paying tax");
    }
    else if (income > 250000 && income <= 500000)
    {
        tax = tax + 0.05 * (income - 250000);
    }
    else if (income > 500000 && income <= 1000000)
    {
        tax = tax + 0.20 * (income - 500000);
    }
    else if (income > 100000)
    {
        tax = tax + 0.30 * (income - 1000000);
    }
    printf("Your income tax to be paid is %f \n", tax);
    return 0;
}
