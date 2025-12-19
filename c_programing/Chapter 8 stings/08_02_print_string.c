#include <stdio.h>

int main()
{
    char str[] = "Aayush";
    char *ptr = str;
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}
