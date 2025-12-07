#include <stdio.h>
int sum(int n);

int main()
{
    int n;
    printf("Enter the term till you want sum :");
    scanf("%d", &n);
    printf("The sum till %d natural number is %d", n, sum(n));

    return 0;
}

int sum(int n)
{
    int result = (n * (n + 1)) / 2;
    return result;
}