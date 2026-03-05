#include <iostream>
template <typename T>
T maximum(T a, T b); // Declaration

int main()
{
    double a{23.4};
    double b{23.4};

    std::cout << "Out - &a :" << &a << std::endl; // Address 1
    auto result = maximum(a, b);
    std::cout << "Out - &a :" << &a << std::endl; // Address 1
    return 0;
}

// Defenition
template <typename T>
T maximum(T a, T b)
{
    std::cout << "In - &a :" << &a << std::endl; // Address 2
    return (a > b) ? a : b;
}
// Address are different because we are passing by value so a copy is generated
