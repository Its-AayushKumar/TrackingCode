#include <stdio.h>

int main()
{
    int a = 10;
    if (a = 11)
    {
        printf("I am 11");
    }
    else
    {
        printf("I am not 11");
    }

    return 0;
}
// Here the output will be "I am 11" because we have used assignment operator
// (a=11)instead of comparison opreator. Assignment operator always give true value
