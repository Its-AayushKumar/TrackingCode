#include <stdio.h>
int main()
{
    char arr[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        scanf(" %c", &arr[i]);
    }
    printf("Your entered character is ");
    for (i = 4; i !=-1; i--)
    {
        printf("%c", arr[i]);
    }
}