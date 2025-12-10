#include <stdio.h>
int main()
{
    int arr[4][5];
    int i, j;
    printf("Enter 16 element for 4X4 matrix:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Enter an element for 4X4 matrix:\n");
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix element are :\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}