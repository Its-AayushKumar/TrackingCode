#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the value of n :");
    scanf("%d", &n);
    printf("The  natural numbers till %d are :\n", n);
    for (i = 0; i < n + 1; i++)
    {
        // printf("The  natural numbers till %d are :\n", n);
        printf("%d\n", i);
    }
    return 0;
}
