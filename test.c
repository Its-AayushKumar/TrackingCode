#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int remainder;
    int sum = 0;
    while (remainder == 0)
    {
        remainder = n % 10;
        n = (n - remainder) / 10;
        sum = remainder + sum;
    }
    printf("%d", sum);
    return 0;
}