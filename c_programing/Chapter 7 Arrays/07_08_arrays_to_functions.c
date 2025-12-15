#include <stdio.h>

// void printArray(int *ptr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("The value of element %d is %d \n ", i + 1, *(ptr + i));
//     }
// }
void printArray(int ptr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("The value of element %d is %d \n", i + 1, ptr[i]);
    }
    ptr[2] = 4444;
}
int main()
{
    int n;
    printf("Enter no. of element you want to store in array :");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter  number %d :", i + 1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    printf("%d", arr[2]);
    return 0;
}