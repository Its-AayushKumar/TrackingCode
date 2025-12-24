#include <stdio.h>
#include <string.h>

int main()
{
    char st1[34];
    char st2[34];
    char c;
    int i = 0;

    printf("Enter the value of first string \n");
    scanf("%s", st1);
    printf("Enter the second string charater by charater \n");

    while (c != '\n')
    {
        fflush(stdin);
        scanf("%c", &c);
        st2[i] = c;
        i++;
    }
    st2[i - 1] = '\0'; // Here we are doing i - 1 because st2 it also incudes \n

    printf("The value of st1 %s\n", st1);
    printf("The value of st2 %s\n", st2);

    int val = strcmp(st1, st2);
    printf("%d", val);
    return 0;
}