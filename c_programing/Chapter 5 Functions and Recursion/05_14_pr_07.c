#include <stdio.h>
void pattern(int n);
int main()
{
    int a;
    printf("Enter a number :");
    scanf("%d", &a);
    pattern(a);

    return 0;
}

void pattern(int n)
{
    int i;
    for (i = 0; i < 2 * n - 1; i++)
    {
        printf("*\n");
    }
}