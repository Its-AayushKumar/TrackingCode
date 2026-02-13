#include <iostream>

int main()
{
    int int_data{33};
    double double_data{55};

    // Refenences
    int &ref_int_data{int_data};
    double &ref_double_data(double_data);

    // Print stuff out
    std::cout << "int_data :" << int_data << std::endl;
    std::cout << "&int_data :" << &int_data << std::endl;
    std::cout << "double_data :" << double_data << std::endl;
    std::cout << "&double_data :" << &double_data << std::endl;

    std::cout << "ref_int_data :" << ref_int_data << std::endl;
    std::cout << "&ref_int_data :" << &ref_int_data << std::endl;
    std::cout << "ref_double_data :" << ref_double_data << std::endl;
    std::cout << "&ref_double_data :" << &ref_double_data << std::endl;

    int_data = 111;
    double_data = 68.4; // If we change the data the reference value will also change

    // Print stuff out
    std::cout << std::endl;
    std::cout << "int_data :" << int_data << std::endl;
    std::cout << "&int_data :" << &int_data << std::endl;
    std::cout << "double_data :" << double_data << std::endl;
    std::cout << "&double_data :" << &double_data << std::endl;

    std::cout << "ref_int_data :" << ref_int_data << std::endl;
    std::cout << "&ref_int_data :" << &ref_int_data << std::endl;
    std::cout << "ref_double_data :" << ref_double_data << std::endl;
    std::cout << "&ref_double_data :" << &ref_double_data << std::endl;

    ref_int_data = 45;
    ref_double_data = 89.9; // We can also change the data through ref_var

    // Print stuff out
    std::cout << std::endl;
    std::cout << "int_data :" << int_data << std::endl;
    std::cout << "&int_data :" << &int_data << std::endl;
    std::cout << "double_data :" << double_data << std::endl;
    std::cout << "&double_data :" << &double_data << std::endl;

    std::cout << "ref_int_data :" << ref_int_data << std::endl;
    std::cout << "&ref_int_data :" << &ref_int_data << std::endl;
    std::cout << "ref_double_data :" << ref_double_data << std::endl;
    std::cout << "&ref_double_data :" << &ref_double_data << std::endl;
    return 0;
}