#include<stdio.h>
int main(){
    int arr[4][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int i,j;
    printf("Elements of 2-D array array:\n");
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
}
return 0;}