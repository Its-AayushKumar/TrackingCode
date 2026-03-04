#include <iostream>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
} // The compiler looks for maximum and turn the T to int or what we are using
int main()
{
    int x{5};
    int y{6};
    int result = maximum(x, y);
    std::cout << "result :" << result << std::endl;

    double a{23.4}, b{2.34};
    auto result1 = maximum(a, b);
    std::cout << "result1 :" << result1 << std::endl;

    std::string p{"Hello"};
    std::string q{"world"};
    auto result2 = maximum(p, q);
    std::cout << "result2 :" << result2 << std::endl;

    return 0;
}