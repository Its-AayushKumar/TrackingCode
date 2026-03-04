#include <iostream>

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

int main()
{
    // int x{45};
    // int y{34};
    std::string p{"Hello"};
    std::string q{"world"};
    auto result = multiply(p, q);
    std::cout << "result :" << result << std::endl;

    return 0;
}