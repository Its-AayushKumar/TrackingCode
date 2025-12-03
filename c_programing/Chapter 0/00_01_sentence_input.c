#include <stdio.h>

int main()
{
    char s[100];
    scanf("%[^\n]%*c", s);
    printf("%s\n", s);

    return 0;
}

// %[^\n] → scanset

// %[...] is called a scanset.

// ^ inside the brackets means “match anything except newline”.

// \n means newline.