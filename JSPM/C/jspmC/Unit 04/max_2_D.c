#include<stdio.h>
int main(){
    int arr[3][3];
    int i,j;
    printf("Enter 9 element for 3X3 matrix:");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Enter elements for a 3x3 matrix:\n");
            scanf("%d",arr[i][j]);
        }
    }
    printf("Matrix is:");
     for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
       

}