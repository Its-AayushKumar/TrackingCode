#include <stdio.h>
int main()
{
    int arr[3][3];
    int i, j;
    printf("Enter 9 element for 3X3 matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter an element for  matrix:\n");
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix element are :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of matrix is :\n");
    for(i = 0;i<3;i++){
        for(j = 0;j < 3;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}