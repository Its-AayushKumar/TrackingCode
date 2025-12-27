#include <stdio.h>
void copy(char *target, char *source)
{
    int i = 0;

    while (source[i] != '\0')
    {
        target[i] = source[i];
        i++;
    }

    target[i] = '\0';
}
int main()
{
    char source[] = "Aayush";
    char target[30];
    copy(target, source);
    printf("%s", target);
    return 0;
}