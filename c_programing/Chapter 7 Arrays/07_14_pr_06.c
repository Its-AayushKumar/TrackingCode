#include <stdio.h>
int positive(int *arr)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter integers no. %d:\n", i + 1);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
        scanf("%d", &arr[i]);
    }
    int count = positive(arr);
    printf("Total number positive integers are :%d\n", count);

    return 0;
}