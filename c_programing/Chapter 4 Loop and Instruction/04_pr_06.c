#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    printf("Enter a number:");
    scanf("%d", &n);
    do
    {
        sum += i;
        i++;

    } while (i <= n);
    printf("The sum 1 to %d is %d:", n, sum);

    return 0;
}