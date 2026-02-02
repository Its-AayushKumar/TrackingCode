#include <stdio.h>
#include <string.h>

int main()
{
    char st1[45] = "Hello";
    char *st2 = "world";
    int val = strcmp(st1, st2); // Here charaters are matched accrording to ascii value
    printf("%d", val);
}