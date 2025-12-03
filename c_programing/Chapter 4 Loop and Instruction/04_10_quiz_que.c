#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the value of n :");
    scanf("%d", &n);
    for (i = n; i; i--)
    {
        printf("Reverse order is %d \n", i);
    }
    return 0;
}