#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) < 4;          // Simple requirement : Only enforces syntax
    requires sizeof(T) < 4; // Nested Requirement
};

// TinyType auto add(TinyType auto a, TinyType auto b)
// {
//     return a + b;
// }

int main()
{
    char y{56};
    char x{67};

    // std::cout << add(x, y);
    return 0;
}