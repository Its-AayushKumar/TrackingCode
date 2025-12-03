// Multiplication table in reverse order of given n numbers
#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter number for table( To print in reverse order)  :");
    scanf("%d", &n);
    for (i = 10; i; i--)
        printf("%d X%d = %d \n", n, i, n * i);

    return 0;
}