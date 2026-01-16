#include <stdio.h>

int main()
{
    FILE *ptr;
    // // fgetc demo for reading a file
    // ptr = fopen("getcdemo.txt", "r");
    // char c = fgetc(ptr);
    // printf("The value of my charater is %c \n", c);

    ptr = fopen("putcdemo.txt", "w");
    putc('c', ptr);
    putc('c', ptr);
    putc('c', ptr);
    fclose(ptr);
    return 0;
}