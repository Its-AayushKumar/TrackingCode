#include <stdio.h>

int main()
{
    int a = 12;
    int *ptr = &a;
    printf("The value of ptr berfore addition is %u \n", ptr);
    ptr++;
    printf("The value of ptr after addition is %u \n", ptr);

    int b = 12;
    int *ptrb = &b;
    printf("The value of ptrb berfore subtraction is %u \n", ptrb);
    ptrb--;
    printf("The value of ptrb after subtraction is %u \n", ptrb);
    printf("The value of ptr-ptrb  is %u \n", ptr - ptrb); // this will tell the size gap between the pointers

    if (ptr > ptrb)
    {
        printf("The value ptr is greater");
    }
    else
    {
        printf("The value of ptrb is greater");
    }
    return 0;
}
