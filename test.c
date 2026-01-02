#include <stdio.h>

int main()
{
    int n;
    printf("Enter a nunber ; ");
    scanf("%d", &n);
    int k = 2 * n - 1;
    int arr[k][k];
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr);
    }
    return 0;
}