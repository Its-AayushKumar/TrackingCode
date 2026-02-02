#include <iostream>

// Funtion for addition
int addnumbers(int first_param, int second_param)
{
    int add = first_param + second_param;
    return add;
}

int main()
{
    int first_number{3}; // Statement
    int second_number{7};

    std::cout << "First number :" << first_number << std::endl;
    std::cout << "Second number :" << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum :" << sum << std::endl; // 10

    sum = addnumbers(25, 5);
    std::cout << "Sum :" << sum << std::endl; // 30

    std::cout << "Sum :" << addnumbers(10, 30) << std::endl;  //40

    return 0;
}