#include <stdio.h>

int main()
{
    int i = 1, n, fact = 1;
    printf("Enter a number :");
    scanf("%d", &n);
    while (i <= n)
    {
        fact *= i;
        i++;
    }
    printf("The factorial of %d is %d", n, fact);
    return 0;
}