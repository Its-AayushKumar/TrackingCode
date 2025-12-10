#include <stdio.h>
int main ()
{
    int i ;
    int arr[15];
    
    for (i = 0;i < 11 ;i++)
    {
        printf("Enter your Marks :");
        scanf("%d",&arr[i]);
    }
    for (i =0;i <11 ; i++)
    {
        if (arr[i] <35){
        printf("%d\n",arr[i]);
            }
    }
}