#include <iostream>

int max(int a, int b)
{
    std::cout << "int overload called " << std::endl;
    return (a > b) ? a : b;
}

double max(double a, double b) // to overload a function Parameters should be different
{
    std::cout << "double overload called" << std::endl;
    return (a > b) ? a : b;
}

double max(int a, double b) // This is also valid
{
    std::cout << "(int,double) overload called" << std::endl;
    return (a > b) ? a : b;
}

double max(double a, int b, int c)
{
    std::cout << "(double,int,int) overload called" << std::endl;
    return a;
}

std::string_view max(std::string_view a, std::string_view b)
{
    std::cout << "(string_view,string_view) overload called" << std::endl;
    return (a > b) ? a : b;
}
int main()
{
    int x{4};
    int y{9};
    double b{7.8};
    double c{3.4};

    auto result = max(x, c, y);

    max("Hello", "World!");
    return 0;
}