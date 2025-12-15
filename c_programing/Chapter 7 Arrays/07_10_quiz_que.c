#include <stdio.h>

void display(int r, int c, int arr[r][c]);

int main()
{
    int r, c;

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    int arr[r][c];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    display(r, c, arr);

    return 0;
}

void display(int r, int c, int arr[r][c])
{
    printf("2D Array elements are:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
