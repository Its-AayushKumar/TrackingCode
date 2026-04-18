#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;          // simple requirement
    requires sizeof(T) <= 4; // Nested requirement
};

template <typename T>
// requires std::integral<T> || std::floating_point<T> // OR Operator

// requires std::integral<T> && TinyType<T>

    requires std::integral<T> && requires(T t) {
        sizeof(T) <= 4;          // simple requirement
        requires sizeof(T) <= 4; // Nested requirement
    } // This will  also do the same work as above

T add(T a, T b)
{
    return a + b;
}

int main()
{
    // std::string x{"5"}; // Will give error as we have only allowed integral and floating type
    // std::string y{"4"};

    // int x{5}; // This will work as the size is less than 4
    // int y{6};

    long long int x{4}; // This will give error as the size of long long in 8
    long long int y{5};

    // add(x, y);

    std::cout << sizeof(long long int) << std::endl;

    return 0;
}