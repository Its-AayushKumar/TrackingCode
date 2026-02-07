#include <iostream>
#include <iomanip>

int main()
{
    // Declare and initialize the variable
    float num1{1.1234567890123456f}; // Precision -->7
    double num2{1.1234567890123456}; // Precision -->15
    long double num3{1.1234567890123456L};

    // Print out sizes
    std::cout << "sizeof float :" << sizeof(float) << std::endl;
    std::cout << "sizeof double :" << sizeof(double) << std::endl;
    std::cout << "sizeof long double :" << sizeof(long double) << std::endl;

    // Precision
    std::cout << std::setprecision(20);            // Control the precision from std::cout
    std::cout << "number1 :" << num1 << std::endl; // 7 digits
    std::cout << "number2 :" << num2 << std::endl; // 15'ish digits
    std::cout << "number3 :" << num3 << std::endl; // 15+ digits

    // Float problems : The precision is usually too limited
    // For a lot of applications
    float num4{1233445678.0f}; // Error:narrowing conversion
    std::cout << "number4 : " << num4 << std::endl;

    return 0;
}
// setprecision(20) --> means it will print 20 significant digits.