#include <iostream>

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

int main()
{
    int x{45}; // We have to use same type of variable
    int y{34};
    // std::string p{"Hello"};
    // std::string q{"world"};// We cannot multiply the strings .
    auto result = multiply(x, y);
    std::cout << "result :" << result << std::endl;

    return 0;
}