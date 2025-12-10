#include <stdio.h>
struct book
{
    char name;
    float price;
    int pages;
};
int main()
{

    struct book b1 = {'B', 130.00, 550};
    printf("\nAddress of name  = %p", (void *)&b1.name);
    printf("\nAddress of price = %p", (void *)&b1.price);
    printf("\nAddress of pages = %p", (void *)&b1.pages);
    return 0;
}