#include <stdio.h>

int main()
{
    int i = 5;
    printf("The value after i++ is %d\n", i++); // In this first print is done and then increment
    printf("The value after ++i is %d\n", ++i); // In this first increment is done and then print
    printf("The value after i is %d\n", i);
    i += 13; //----> value of i is increased by 13
    printf("The value after i is %d\n", i);

    return 0;
}