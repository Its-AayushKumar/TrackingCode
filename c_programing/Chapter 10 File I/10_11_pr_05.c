#include <stdio.h>

int main()
{
    FILE *ptr1, *ptr2;
    int num;

    ptr1 = fopen("num.txt", "r");  // old file
    ptr2 = fopen("num1.txt", "w"); // new file

    fscanf(ptr1, "%d", &num); // read integer
    num = num * 2;            // double it
    fprintf(ptr2, "%d", num); // write to new file

    fclose(ptr1);
    fclose(ptr2);

    return 0;
}
