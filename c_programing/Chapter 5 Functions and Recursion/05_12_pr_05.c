#include <stdio.h>

int main()
{
    int a = 3;
    printf("%d %d %d ", a, ++a, a++); // In gcc it is read fron right to left.
    return 0;                         // It may vary compiler to compiler.
}