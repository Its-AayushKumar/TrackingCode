#include <stdio.h>
#include <math.h>

int main()
{
    int a = 3;
    int b = 9;

    printf("The value of a+b is : %d\n", a + b);
    printf("The value of a-b is : %d\n", a - b);
    printf("The value of a*b is : %d\n", a * b);
    printf("The value of a/b is : %d\n", a / b);

    int x;
    x = a * b; // legal
    // a * b = x; // illegal
    printf("The value of x is : %d\n", x);

    printf("5 when divided by 2 leaves a remainder of %d\n", 5 % 2);
    printf("-5 when divided by 2 leaves a remainder of %d\n", -5 % 2);
    printf("5 when divided by -2 leaves a remainder of %d\n", 5 % -2);

    // No operator is assumed to be present
    // printf("The value of 4*5 is %d\n",(4)(5)); ---> Will not return 20
    printf("The value of 4*5 is %d\n", 4 * 5);

    // There is no operator to perform exponential in c
    printf("The value of 4^5 is %d \n", 4 ^ 5);
    printf("The 4 to the power 5  is %f \n", pow(4,5)); 
    return 0;
}
