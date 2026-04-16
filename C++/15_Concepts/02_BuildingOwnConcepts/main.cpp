#include <iostream>
#include <concepts>
#include <type_traits>

// Syntax1
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

template <typename T>
    requires MyIntegral<T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    int x{4};
    int y{5};

    std::cout << add(x, y); // 🔥 print result

    return 0;
}