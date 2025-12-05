#include <stdio.h>

int main()
{
    int i = 2, n, prime = 0;
    printf("Enter a number :");
    scanf("%d", &n);
    while (i < n)
    {

        if (n % i == 0)
        {
            prime = 1;
            break;
        }
        i++;
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