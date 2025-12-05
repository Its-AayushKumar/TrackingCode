#include <stdio.h>

int main()
{
    for (int i = 9; i; i--) // Here test value is not given so it is considered as true
    // for (int i = 9; i > -3; i--) // This can be used of printing negative values
    {
        printf("The value is %d \n", i);
    }
    return 0;
}