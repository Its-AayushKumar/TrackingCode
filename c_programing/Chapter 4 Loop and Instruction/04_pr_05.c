#include <stdio.h>

int main()
{
    int i = 0, sum = 0, n;
    printf("Enter a number:");
    scanf("%d", &n);
    // for (i = 0; i < n + 1; i++)
    // {
    //     sum += i;
    // }
    while (i < n + 1)
    {
        sum += i;
        i++;
    }
    printf("The value of sum 1 to %d is %d ", n, sum);
    return 0;
}