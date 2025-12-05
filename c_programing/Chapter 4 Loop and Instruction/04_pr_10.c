// This is not the best method to check prime
#include <stdio.h>

int main()
{
    int i, n, prime = 0;
    printf("Enter a number :");
    scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            prime = 1;
            break;
        }
    }
    if (prime == 1 && n != 2)
    {
        printf("This is not a prime number");
    }
    else
    {
        printf("The number is a prime number");
    }

    return 0;
}