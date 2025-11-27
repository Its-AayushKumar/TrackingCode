#include <stdio.h>
int main()
{
    int a = 9;
    // int b = 8.5; is not recommended because as 8.5 is not an interger
    float b = 5.5;
    char c = 'x';
    int d = 46;
    int e = 46 + 4;
    printf("The value of a is %d\n", a);
    printf("The value of b is %f\n", b);
    printf("The value of a is %c\n", c);
    printf("The sum of a + d is %d\n", a + d);
    printf("The value of a is %d\n", e);
    return 0;
}

// // Try yourself -- create a program to add two numbers in c
// #include <stdio.h>
// int main()
// {
//     int a = 6;
//     int b = 9;
//     int sum = a + b;
//     printf("The sum of a + b is %d", sum);
//     return 0;
// }