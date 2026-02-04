#include <iostream>
#include <string> // Here it works with out this but in some compiler it does'nt so better to include
int main()
{
    // Printing data
    // std::cout << "Hello c++23" << std::endl;

    // int age{21};
    // std::cout << "Age:" << age << std::endl;

    // std::cerr << "Error message : Something is wrong" << std::endl;
    // std::clog << "Log message : Something happened " << std::endl;

    // Taking input from user
    int age1;
    std::string name;

    std::cout << "Please type your name and age :" << std::endl;

    // std::cin >> name;
    // std::cin >> age1;

    std::cin >> name >> age1;

    std::cout << "Hello " << name << " you are " << age1 << " years old " << std::endl;

    return 0;
}
// But here we cannot write our name with spaces if we do it will not ask our age
// Solution in next program