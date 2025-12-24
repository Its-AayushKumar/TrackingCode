#include <stdio.h>
#include <string.h>

int main()
{
    char st1[45] = "Hello";
    char *st2 = "world";
    strcat(st1, st2);
    printf("%s", st1);
    return 0;
}