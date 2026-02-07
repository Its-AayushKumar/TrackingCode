#include <iostream>

int main()
{
    std::cout << "Infinity and NaN" << std::endl;

    double num10{-5.6};
    double num11{}; // Initialized to 0
    double num12{}; // Initialized to 0

    // Infinity
    double result{num10 / num11};

    std::cout << num10 << "/" << num11 << " yeilds " << result << std::endl;
    std::cout << result << "+" << num10 << " yeilds " << result + num10 << std::endl;

    // NaN
    result = num11 / num12;
    std::cout << num11 << "/" << num12 << " yeilds " << result << std::endl;

    return 0;
}
// IF we use int instead of double the we will get runtime error or our program will crash
// Infinity and NaN only happen in floating - point types(float, double, long double) not in int.