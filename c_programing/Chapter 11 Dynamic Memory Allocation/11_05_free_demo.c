#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *ptr;
    float *ptr2;
    ptr = (float *)malloc(500 * sizeof(float));
    for (int i = 0; i < 5; i++)
    {
        ptr2 = (float *)malloc(600000 * sizeof(float));
        printf("Enter the value of %d element:\n", i);
        scanf("%f", &ptr[i]);
        free(ptr2);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("The value of %d element is :%f\n", i, ptr[i]);
    }
    free(ptr);

    return 0;
}