#include <stdio.h>
int main()
{
    int arr[10];
    int i , sum,sub;
    float avg;
    for (i = 0; i < 5 ;i++)
    {
    printf("Enter number:");
    scanf(" %d",&arr[i]);
    }
    for (i =0; i<5;i++)
    {
    sum +=arr[i];
    sub -=arr[i];
}
avg=sum/5.0;
printf("sum %d\n",sum);
printf("avg %f\n",avg);
printf("sub %d\n",sub);
}