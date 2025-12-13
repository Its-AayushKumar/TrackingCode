#include <stdio.h>

int main()
{
    int i = 34;
    int *ptr = &i;
    printf("The value of ptr is %u \n ", ptr);
    ptr++; // int type pointer has 4 bytes //char har 1
    printf("The value of ptr is %u \n ", ptr);

    char c = '3';
    char *ptrc = &c;
    printf("The value of ptrc is %u \n ", ptrc);
    ptrc++; // char has 1 byte
    printf("The value of ptrc is %u \n ", ptrc);

    float d = 34.3;
    float *ptrd = &d;
    printf("The value of ptrd is %u \n ", ptrd);
    ptrd++; // float has 1 byte
    printf("The value of ptrd is %u \n ", ptrd);
    return 0;
}