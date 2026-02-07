#include <iostream>
#include <iomanip>

int main()
{
    /* Scientific notation
    What we have seen so far in terms of floating point types
    is fixed notation . There is another notation , scientific
    that is handy if you really huge numbers or small numbers
    to repeat*/

    double num5{192400023};
    double num6{1.92400023e8};
    double num7{1.924e8}; // Can ommit the lower 0023
                          // for simplicity if our application allows

    double num8{0.00000000003498};
    double num9{3.498e-11}; // Multiply with 10 exp(-11)

    std::cout << std::setprecision(20);

    std::cout << "number5 is :" << num5 << std::endl;
    std::cout << "number6 is :" << num6 << std::endl;
    std::cout << "number7 is :" << num7 << std::endl;
    std::cout << "number8 is :" << num8 << std::endl;
    std::cout << "number9 is :" << num9 << std::endl;

    return 0;
}