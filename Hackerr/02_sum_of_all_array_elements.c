#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int arr[1000], n;
    int sum = 0;
    // printf("Enter number:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum = arr[i] + sum;
    }

    printf("%d", sum);
    return 0;
}