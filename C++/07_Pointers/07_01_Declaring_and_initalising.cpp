#include <iostream>

int main()
{
    // Declare and initialize pointer
    int *p_number{}; // will initialize with nullptr
    double *p_fractional_number{};

    // Explicitly initialize with nullptr
    int *p_num1{nullptr};
    int *p_fractional_number1{nullptr};

    // Pointers to different variables are of the same size
    std::cout << "sizeof(int):" << sizeof(int) << std::endl;
    std::cout << "sizeof(double):" << sizeof(double) << std::endl;
    std::cout << "sizeof(double*):" << sizeof(double *) << std::endl;
    std::cout << "sizeof(int*):" << sizeof(int *) << std::endl;
    std::cout << "sizeof(p_num1):" << sizeof(p_num1) << std::endl;
    std::cout << "sizeof(p_fractional_number1):" << sizeof(p_fractional_number1) << std::endl;

    // It doesn't matter if you put the * close to data type or to variable name
    // int*p_num2{nullptr};
    // int * p_num2{nullptr};
    // int  *p_num2{nullptr};

    int *p_num5{}, other_int_var1{};
    int *p_num6{}, other_int_var2{};
    // Confusing as you wonder if other_int_var2 is also a pointer
    // to int . It is not the structure is exactly the same for
    // the previous statement

    std::cout << "sizeof(p_num5) :" << sizeof(p_num5) << std::endl;
    std::cout << "sizeof(other_int_var1) :" << sizeof(other_int_var1) << std::endl;
    std::cout << "sizeof(p_num6) :" << sizeof(p_num6) << std::endl;
    std::cout << "sizeof(other_int_var1) :" << sizeof(other_int_var2) << std::endl;

    // It is better to separate these declarations in different lines though
    int *p_num7{};
    int other_int_var3{};

    // Initializing pointers and assigning them data
    // We know that pointers store address of variables
    int int_var{45};
    int *p_int{&int_var}; // The address of operator(&)

    std::cout << "Int var :" << int_var << std::endl;
    std::cout << "p_int(Address in memory) : " << p_int << std::endl;

    // You can also change the address stored in a pointer any time
    int int_var1{234};
    p_int = &int_var1; // Assign a diffrent address to the pointer
    std::cout << "p_int(With different address):" << p_int << std::endl;

    // Can't cross assign between pointers of different types
    int *p_int1{nullptr};
    double double_var{33.0};

    // p_int = &double_var; // Compiler error

    // Dereferencing a pointer:
    int *p_int2{nullptr};
    int int_data{56};
    p_int2 = &int_data;

    std::cout << "Value:" << *p_int2 << std::endl; // Dereferncing a pointer
    // follow the address and get the value
    return 0;
}