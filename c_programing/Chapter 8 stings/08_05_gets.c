#include <stdio.h>

int main()
{
    char s[35];
    printf("Enter your name:");
    gets(s);
    puts(s);
    // fgets(s, sizeof(s), stdin);
    // printf("Name :%s\n", s);
    return 0;
}