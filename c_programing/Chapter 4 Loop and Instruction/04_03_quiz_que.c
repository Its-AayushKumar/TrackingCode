#include <stdio.h>

int main()
{
    int a = 0;
    printf("Enter a number:");
    scanf("%d", &a);
    while (a >= 10 && a <= 20)
    {
        printf("%d\n", a);
        a++; // a = a + 1
    }

    return 0;
}